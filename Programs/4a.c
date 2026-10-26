 #include <stdio.h> 
#include <pthread.h> 
#include <unistd.h> 
  
int cap, total, boarded = 0, ride = 1; 
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; 
  
void* pass(void* id) { 
    pthread_mutex_lock(&m); 
    printf("Passenger %ld boarded (%d/%d)\n", 
           (long)id, ++boarded, cap); 
    if (boarded == cap) { 
        printf("*** RIDE #%d RUNNING ***\n", ride++); 
        usleep(500000); 
        boarded = 0; 
    } 
    pthread_mutex_unlock(&m); 
    return NULL; 
} 
  
int main() { 
    printf("Enter capacity & total: "); 
    if (scanf("%d %d", &cap, &total) != 2 || 
        cap <= 0 || total <= 0) return 1; 
    pthread_t t[total]; 
    for (long i = 1; i <= total; i++) { 
        pthread_create(&t[i - 1], NULL, pass, (void*)i); 
        usleep(20000); 
    } 
    for (int i = 0; i < total; i++) pthread_join(t[i], NULL); 
    pthread_mutex_destroy(&m); 
    return 0; 
} 
 

 
