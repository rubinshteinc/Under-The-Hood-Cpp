#include "consumer.h"

int out = 0;

void* consumer(void *args)  {
    int ID = *(int*)args;
    int i;

    for (i = 0; i < 30; ++i) {
        sem_wait(&c_sem);
        pthread_mutex_lock(&mutex);

        printf("consumer %d: product = %d\n", ID, Box[out]);
        out = (out+1) % BOX_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&p_sem);
    }


    return args;
}


