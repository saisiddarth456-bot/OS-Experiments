#include <stdio.h>
int main() {
 int n, f, i, j, page, hit;
 int a[20], frame[10], freq[10] = {0};
 int faults = 0;
 printf("Enter number of pages: ");
 scanf("%d", &n);
 if (n < 1 || n > 20) return 1;
 printf("Enter page reference string: ");
 for (i = 0; i < n; i++) scanf("%d", &a[i]);
 printf("Enter number of frames: ");
 scanf("%d", &f);
 if (f < 1 || f > 10) return 1;
 for (i = 0; i < f; i++) frame[i] = -1;
 for (i = 0; i < n; i++) {
 page = a[i];
 hit = 0;
 for (j = 0; j < f; j++) {
 if (frame[j] == page) {
 freq[j]++;
 hit = 1;
 break;
 }
 }
 if (!hit) {
 int pos = 0;
 for (j = 1; j < f; j++)
 if (freq[j] < freq[pos]) pos = j;
 frame[pos] = page;
 freq[pos] = 1;
 faults++;
 }
 }
  }
 }
 printf("Page Faults = %d\n", faults);
 return 0;
}
