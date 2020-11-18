#ifndef PRODUCER_CONSUMER_GLOBAL_VARS_H
#define PRODUCER_CONSUMER_GLOBAL_VARS_H

#include <pthread.h>
#include <semaphore.h>
#define BOX_SIZE 6
#define NUM_PRODUCER 3
#define NUM_CONSUMER 4

extern int Box[BOX_SIZE];
sem_t c_sem;
sem_t p_sem;
extern pthread_mutex_t mutex;
extern int out;
extern int in;
#endif //PRODUCER_CONSUMER_GLOBAL_VARS_H
