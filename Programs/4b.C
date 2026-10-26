#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
int cap, total, boarded = 0; 
sem_t seats; 
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t ride = PTHREAD_COND_INITIALIZER; 
  
void* pass(void* id) { 
    sem_wait(&seats); 
    pthread_mutex_lock(&m); 
    printf("Passenger %ld boarded (%d/%d)\n", 
           (long)id, ++boarded, cap); 
    if (boarded == cap) pthread_cond_signal(&ride); 
    pthread_mutex_unlock(&m); 
    return NULL; 
} 
  
void* car(void* a) { 
    for (int r = 1; r <= total / cap; r++) { 
        pthread_mutex_lock(&m); 
        while (boarded < cap) pthread_cond_wait(&ride, &m); 
        printf("*** RIDE #%d RUNNING ***\n", r); 
        usleep(500000); 
        boarded = 0; 
        pthread_mutex_unlock(&m); 
        for (int i = 0; i < cap; i++) sem_post(&seats); 
    } 
    return NULL;
    int main() { 
    printf("Enter capacity & total: "); 
    if (scanf("%d %d", &cap, &total) != 2 || cap <= 0 || 
        total <= 0 || total % cap != 0) return 1; 
    sem_init(&seats, 0, cap); 
    pthread_t c, t[total]; 
    pthread_create(&c, NULL, car, NULL);
    for (long i = 1; i <= total; i++) { 
 
 
        pthread_create(&t[i - 1], NULL, pass, (void*)i); 
        usleep(20000); 
    } 
    for (int i = 0; i < total; i++) pthread_join(t[i], NULL); 
    pthread_join(c, NULL); 
    sem_destroy(&seats); 
    pthread_mutex_destroy(&m); 
    pthread_cond_destroy(&ride); 
    return 0; 
} 
  
