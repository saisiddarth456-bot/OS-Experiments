#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
int main() {
 
int main() {
int n, i, head, total = 0;
 int n, i, head, total = 0;
int request[20];
 printf("Enter number of requests: ");
int request[20];
 printf("Enter number of requests: ");
scanf("%d", &n);
 printf("Enter request queue: ");
scanf("%d", &n);
 printf("Enter request queue: ");
for (i = 0; i < n; i++)
 for (i = 0; i < n; i++)
scanf("%d", &request[i]);
 printf("Enter initial head position: ");
scanf("%d", &request[i]);
 printf("Enter initial head position: ");
scanf("%d", &head);
 for (i = 0; i < n; i++) {
scanf("%d", &head);
 for (i = 0; i < n; i++) {
total += abs(head - request[i]);
 head = request[i];
total += abs(head - request[i]);
 }
head = request[i];
 printf("Total Head Movement = %d
}
\n", total);
 printf("Total Head Movement = %d
return 0;
\n", total);
 
}
return 0;
}
