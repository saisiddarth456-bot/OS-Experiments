#include <stdio.h> 
#include <pthread.h> 
  
void *satellite(void *a) { 
    printf("ISRO satellite detected heat anomaly\n"); 
    return NULL; 
} 
  
void *drone(void *a) { 
    printf("Drone dispatched\n"); 
    printf("Fire heat harvested for charging\n"); 
    printf("Drone returning to base\n"); 
    return NULL; 
} 
  
int main() { 
    pthread_t s, d; 
  
    pthread_create(&s, NULL, satellite, NULL); 
    pthread_join(s, NULL)
       pthread_create(&d, NULL, drone, NULL); 
    pthread_join(d, NULL); 
  
    return 0; 
}
