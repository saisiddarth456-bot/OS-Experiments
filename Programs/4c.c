
    
PROGRAM 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
int cap, total; 
sem_t seats; 
  
void* pass(void* id) { 
    sem_wait(&seats); 
    printf("Passenger %ld seated\n", (long)id); 
    return NULL; 
} 
  
void* car(void* a) { 
    for (int r = 1; r <= total / cap; r++) { 
        usleep(300000); 
        printf("*** RIDE #%d RUNNING ***\n", r); 
        usleep(500000); 
        for (int i = 0; i < cap; i++) sem_post(&seats); 
    } 
    return NULL; 
} 
  
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
    return 0; 
} 
 
 
