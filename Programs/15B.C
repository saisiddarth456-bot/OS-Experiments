#include <stdio.h>
#include <string.h>
int main() {
 char u[10][20], f[10][10][20], name[20];
 int count[10] = {0}, n = 0, ch, i, j;
 puts("1.Create folder 2.Add 3.Display 4.Exit");
 while (1) {
 printf("Choice: ");
 if (scanf("%d", &ch) != 1 || ch == 4)
 break;
 if (ch == 3) {
 for (i = 0; i < n; i++) {
 printf("%s: ", u[i]);
 for (j = 0; j < count[i]; j++)
 printf("%s ", f[i][j]);
 puts("");
 }
 continue;
 }
 if (ch != 1 && ch != 2) {
 puts("Invalid choice");
 continue;
 }
 printf("User folder: ");
 scanf("%19s", name);
 for (i = 0; i < n &&
 strcmp(u[i], name) != 0; i++);
 if (ch == 1) {
 if (i < n)
 puts("Folder exists");
 else if (n == 10)
 puts("Folder full");
else {
 strcpy(u[n++], name);
 puts("Folder created");
 }
 }
 else if (i == n)
 puts("Folder not found");
 else if (count[i] == 10)
 puts("Folder full");
 else {
 printf("File name: ");
 scanf("%19s", name);
 for (j = 0; j < count[i] &&
 strcmp(f[i][j], name) != 0; j++);
 if (j < count[i])
 puts("File exists");
 else {
 strcpy(f[i][count[i]++], name);
 puts("Added");
 }
 }
 }
 return 0;
}
