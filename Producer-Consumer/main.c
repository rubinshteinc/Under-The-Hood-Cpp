#include "global_vars.h"
#include "consumer.h"
#include "producer.h"

int Box[BOX_SIZE];
pthread_mutex_t mutex  = PTHREAD_MUTEX_INITIALIZER;

int main() {

    sem_init(&c_sem, 0, 0);
    sem_init(&p_sem, 0, BOX_SIZE);

    pthread_t producers[NUM_PRODUCER];
    pthread_t consumers[NUM_CONSUMER];
    int t;
    int p0 = 0, p1 = 1, p2 = 2, c0 = 0, c1 = 1, c2 = 2, c3 = 3;

    pthread_create(&consumers[c0], NULL, consumer, (void*)&c0);
    pthread_create(&consumers[c1], NULL, consumer, (void*)&c1);
    pthread_create(&consumers[c2], NULL, consumer, (void*)&c2);
    pthread_create(&consumers[c3], NULL, consumer, (void*)&c3);
    pthread_create(&producers[p0], NULL, producer, (void*)&p0);
    pthread_create(&producers[p1], NULL, producer, (void*)&p1);
    pthread_create(&producers[p2], NULL, producer, (void*)&p2);



    for(t = 0; t < NUM_PRODUCER; ++t){
        pthread_join(producers[t], NULL);
    }

    for(t = 0; t < NUM_CONSUMER; ++t){
        pthread_join(consumers[t], NULL);
    }

    printf("\n");

    sem_destroy(&c_sem);
    sem_destroy(&p_sem);
    return 0;
}




