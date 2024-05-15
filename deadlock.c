#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1, mutex2;

void* thread1(void* arg) {
    printf("Thread 1: Attempting to acquire mutex1...\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 1: Mutex1 acquired.\n");
    
    // Sleep to allow thread2 to acquire mutex2
    sleep(1);
    
    printf("Thread 1: Attempting to acquire mutex2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 1: Mutex2 acquired.\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

void* thread2(void* arg) {
    printf("Thread 2: Attempting to acquire mutex2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: Mutex2 acquired.\n");

    // Sleep to allow thread1 to acquire mutex1
    sleep(1);

    printf("Thread 2: Attempting to acquire mutex1...\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 2: Mutex1 acquired.\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize mutexes
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    // Create threads
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    // Join threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutexes
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
