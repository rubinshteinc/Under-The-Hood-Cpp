
#include "producer.h"

int in = 0;

void* producer(void* args) {
    int ID = *(int*)args;
    int i;
    int randNum;

    for (i = 0; i < 40; ++i) {

        sem_wait(&p_sem);
        pthread_mutex_lock(&mutex);

        randNum =  (rand() %(1000000+1));
        Box[in] = randNum;
        printf("producer %d: product = %d\n", ID, randNum);
        in = (in+1) % BOX_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&c_sem);
    }
    return args;
}
