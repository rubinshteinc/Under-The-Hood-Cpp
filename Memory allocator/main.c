#include <stdio.h>
#include <stdlib.h>
#include "memory_allocator.h"

struct MemoryAllocator{
    char *memoryPool;
    size_t size;
};
void testMemoryAllocator_init(){
    void *arr = (void*)malloc(100);

    if(arr == NULL){
        printf("Memory allocation failed!!!\n");
        exit(1);
    }
    MemoryAllocator *allocator = MemoryAllocator_init(arr, 100);

    if(100 == allocator->size){
        printf("MemoryAllocator_init success\n");
    }
    free(arr);
}
void testMemoryAllocator_release(){

    void *arr = (void*)malloc(100);

    if(arr == NULL){
        printf("Memory allocation failed!!!\n");
        exit(1);
    }
    MemoryAllocator *allocator = MemoryAllocator_init(arr, 100);
    long *result = MemoryAllocator_release(allocator);

    if(result){
        printf("MemoryAllocator_release success\n");
    }
    free(arr);
}
int main() {

//    testMemoryAllocator_init();
//    testMemoryAllocator_release();

    void *arr = (void*)malloc(100);
    if(arr == NULL){
        printf("Memory allocation failed!!!\n");
        exit(1);
    }

    MemoryAllocator *allocator = MemoryAllocator_init(arr, 104);

    void* alloc_result1 = MemoryAllocator_allocate(allocator, 10);
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result1 - 8)) - 1); //16
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result1 + 16))); //72
    size_t size1 = MemoryAllocator_optimize(allocator);
    printf("%ld\n", size1); // 72

    void* alloc_result2 = MemoryAllocator_allocate(allocator, 10);
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result2 - 8)) - 1); //16
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result2 + 16))); //48
    size_t size2 = MemoryAllocator_optimize(allocator);
    printf("%ld\n", size2); //48

    void* alloc_result3 = MemoryAllocator_allocate(allocator, 10);
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result3 - 8)) - 1); //16
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result3 + 16))); //24

    void* alloc_result4 = MemoryAllocator_allocate(allocator, 10);
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result4 - 8)) - 1); //16
    printf("Allocated successfully: %ld\n", *((long*)(alloc_result4 + 16))); //0
    return 0;
}