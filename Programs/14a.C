#include <stdio.h>
int main() {
 int disk[50] = {0}, start, n, i, free = 1;
 char file[20];
 printf("Enter file name: ");
 scanf("%19s", file);
 printf("Enter starting block: ");
 scanf("%d", &start);
 printf("Enter number of blocks: ");
 scanf("%d", &n);
 if (start < 0 || n <= 0 || start + n > 50) {
 printf("Invalid block range\n");
 return 0;
 }
 for (i = start; i < start + n; i++) {
 if (disk[i] != 0)
 free = 0;
 }
 if (free) {
 printf("\nFile: %s\nAllocated blocks: ", file);
 for (i = start; i < start + n; i++) {
 disk[i] = 1;
 printf("%d ", i);
 }
 } else {
 printf("Blocks not available");
 }
 return 0;
}
