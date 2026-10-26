#include <stdio.h>
int main() {
 int b, p, i, j, worst;
 int block[10], process[10], alloc[10];
 printf("Enter number of blocks: ");
 scanf("%d", &b);
 if (b < 1 || b > 10) return 1;
 printf("Enter block sizes: ");
 for (i = 0; i < b; i++) scanf("%d", &block[i]);
 printf("Enter number of processes: ");
 scanf("%d", &p);
 if (p < 1 || p > 10) return 1;
 printf("Enter process sizes: ");
 for (i = 0; i < p; i++) scanf("%d", &process[i]);
 for (i = 0; i < p; i++) {
 worst = -1;
 for (j = 0; j < b; j++) {
 if (block[j] >= process[i]) {
 if (worst == -1 || block[j] > block[worst])
 worst = j;
 }
 }
 if (worst != -1) {
 alloc[i] = worst;
 block[worst] -= process[i];
 } else alloc[i] = -1;
 }
 printf("\nProcess\tBlock\n");
 for (i = 0; i < p; i++) {
 if (alloc[i] != -1)
 printf("%d\t%d\n", process[i], alloc[i] + 1);
 else
 printf("%d\tNot Allocated\n", process[i]);
}
return 0;
}
