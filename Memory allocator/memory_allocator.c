#include "memory_allocator.h"
#include <stdlib.h>
#include <stdio.h>
#define MASK_TO_FREE 0x1
#define WORD_SIZE 8

/*
 Assume:
  * 1 - free block,
  * 0 - occupied block.
  * The size of block is even so didn't need to change the sign bit of block. - ?????

*/


struct MemoryAllocator{
    void *_memoryPool;
    size_t _size;
};

/*Auxiliary functions - Declaration*/
size_t getSizeBlock(void *ptrBlock);
void setSizeBlock(void *ptrBlock, size_t size);
int isFree(void *ptrBlock);
void changeBlockStatus(void *ptrBlock);
void* getPtrToNextBlock(void *ptrBlock);
void* getPtrToPayload(void *ptrBlock);

MemoryAllocator* MemoryAllocator_init(void* memoryPool, size_t size){
    MemoryAllocator *allocator = (MemoryAllocator*)malloc(sizeof(struct MemoryAllocator));
    allocator -> _memoryPool = memoryPool;
    allocator -> _size = size;

    *(size_t*)(allocator -> _memoryPool) = size;
    (*(size_t*)allocator -> _memoryPool) |= 0x1;

    return allocator;
}

void* MemoryAllocator_release(MemoryAllocator* allocator){
    void *memoryPoolTemp = allocator -> _memoryPool;
    free(allocator);

    return memoryPoolTemp;
}

void* MemoryAllocator_allocate(MemoryAllocator* allocator, size_t size){

    if(!allocator){
        return NULL;
    }

    size_t offset = 0;
    void *currentBlock = allocator -> _memoryPool;
    size_t blockSize;
    size += (size % WORD_SIZE != 0) * WORD_SIZE - size % WORD_SIZE;

    while(offset < allocator -> _size){
        blockSize = getSizeBlock(currentBlock);

        if (isFree(currentBlock)) {

            if(size == blockSize){
                //TODO change the bit of block - DONE
                changeBlockStatus(currentBlock);
                return getPtrToPayload(currentBlock);
            }

            if(size < blockSize){

                setSizeBlock((size_t*)currentBlock + size, *(size_t*)currentBlock - size);
                setSizeBlock(currentBlock, size);

                //TODO change the bit of block - DONE
                changeBlockStatus(currentBlock);

                return getPtrToPayload(currentBlock);
            }

            if(size > blockSize) {

                if(isFree(getPtrToNextBlock(currentBlock))) {

                    /*merge blocks*/
                    //TODO להוציא את מרג' לפונקציה נפרדת (נמצא ב - 3 מקומות בקוד)
                    setSizeBlock(currentBlock,getSizeBlock(currentBlock) + getSizeBlock(getPtrToNextBlock(currentBlock)));
                }
                else{

                    offset += getSizeBlock(currentBlock) + sizeof(size_t);
                    currentBlock = allocator ->_memoryPool + offset;
                }
            }
        }

        else{
            offset += getSizeBlock(currentBlock) + sizeof(size_t);
            currentBlock = allocator ->_memoryPool + offset;
        }

    }

    return NULL;
}

void MemoryAllocator_free(MemoryAllocator* allocator, void *ptr){
    if(allocator) {

        changeBlockStatus(ptr);
        if(isFree(getPtrToNextBlock(ptr - sizeof(size_t)))) {
            /*merge blocks*/
            setSizeBlock(ptr,getSizeBlock(ptr) + getSizeBlock(getPtrToNextBlock(ptr)));
        }
    }
}

size_t MemoryAllocator_optimize(MemoryAllocator *allocator) {

    if(!allocator){
        return NULL;
    }
    size_t offset = 0;
    size_t maxBlockSize = 0;
    size_t blockSize;
    void *currentBlock = allocator->_memoryPool;

    while (offset < allocator->_size) {

        if (isFree(currentBlock)) {

            if (isFree(getPtrToNextBlock(currentBlock))) {
                /*merge blocks*/
                setSizeBlock(currentBlock, getSizeBlock(currentBlock) + getSizeBlock(getPtrToNextBlock(currentBlock)));
            }
            else{

                if(maxBlockSize < getSizeBlock(currentBlock)) {
                    maxBlockSize = getSizeBlock(currentBlock);
                    offset += getSizeBlock(currentBlock) + sizeof(size_t);
                    currentBlock += offset;
                }
            }
        }
        else {

            offset += getSizeBlock(currentBlock) + sizeof(size_t);
            currentBlock += offset;
        }
    }

    return maxBlockSize;
}


/*Auxiliary functions - Implementation*/

size_t getSizeBlock(void *ptrBlock){
//   TODO לבודד את הגודל כי עכשיו זה ביחד עם סיבית הסימן - DONE

    *((size_t *)ptrBlock - sizeof(size_t)) >>= 1;
    *((size_t *)ptrBlock - sizeof(size_t)) <<= 1;
    printf(" getSizeBlock \n");
    return *(size_t*)ptrBlock;
}

void setSizeBlock(void *ptrBlock, size_t size){
    *(size_t*)(ptrBlock) = size;
}

int isFree(void *ptrBlock){
    printf(" isFree \n");

    return *(size_t*)ptrBlock & MASK_TO_FREE;
}

void changeBlockStatus(void *ptrBlock){
    printf(" changeBlockStatus \n");

    if(isFree(ptrBlock)) {
        *(size_t *) ptrBlock |= MASK_TO_FREE;
    }
    else{
        setSizeBlock(ptrBlock, getSizeBlock(ptrBlock) + 1);
    }
}

void* getPtrToNextBlock(void *ptrBlock){
    printf(" getPtrToNextBlock \n");

    return (size_t*)ptrBlock + getSizeBlock(ptrBlock);
}


void* getPtrToPayload(void *ptrBlock){

    return (size_t *)ptrBlock + 1;
}