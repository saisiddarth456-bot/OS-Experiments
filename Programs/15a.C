#include <stdio.h>
#include <string.h>
int main() {
 char files[10][20], name[20];
 int n = 0, ch, i;
 printf("Directory: Shared\n");
 printf("1.Add 2.Search 3.Delete 4.Display 5.Exit\n");
 while (1) {
 printf("Choice: ");
 if (scanf("%d", &ch) != 1 || ch == 5)
 break;
 if (ch == 4) {
 printf("Shared: ");
 for (i = 0; i < n; i++)
 printf("%s ", files[i]);
 printf("\n");
 continue;
 }
 if (ch < 1 || ch > 3) {
 puts("Invalid choice");
 continue;
 }
 printf("File name: ");
 scanf("%19s", name);
for (i = 0; i < n &&
 strcmp(files[i], name) != 0; i++);
 if (ch == 1) {
 if (i < n)
 puts("File already exists");
 else if (n >= 10)
 puts("Directory full");
 else {
 strcpy(files[n++], name);
 puts("Added");
 }
 }
 else if (ch == 2)
 puts(i < n ? "File found" : "File not found");
 else if (i == n)
 puts("File not found");
 else {
 for (int j = i; j < n - 1; j++)
 strcpy(files[j], files[j + 1]);
 n--;
 puts("Deleted");
 }
 }
 return 0;
}
