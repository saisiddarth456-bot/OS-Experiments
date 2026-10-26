#include <stdio.h>
#include <threads.h>
mtx_t m[20];
int n;
int eat(void *arg) {
 int i = *(int *)arg;
 int l = i, r = (i + 1) % n;
 if (i % 2) {
 mtx_lock(&m[l]);
 mtx_lock(&m[r]);
 } else {
 mtx_lock(&m[r]);
 mtx_lock(&m[l]);
 }
 printf("Person %d is eating using chopstick %d & %d\n",
 i + 1, l + 1, r + 1);
 mtx_unlock(&m[l]);
 mtx_unlock(&m[r]);
 return 0;y
}
int main() {
 printf("Enter number of diners (2-20): ");
 if (scanf("%d", &n) != 1 || n < 2 || n > 20)
 return 1;
 thrd_t t[20];
 int ids[20];
 for (int i = 0);
for (int i = 0; i < n; i++)
 mtx_init(&m[i], mtx_plain);
 for (int i = 0; i < n; i++) {
 ids[i] = i;
 thrd_create(&t[i], eat, &ids[i]);
 
}
 
for (int i = 0; i < n; i++)
 thrd_join(t[i], NULL);
 for (int i = 0; i < n; i++)
 mtx_destroy(&m[i]);
 return 0;
}
