#include <stdio.h>
int main() {
 int index, n, block[20], used[50] = {0};
 int i, valid = 1;
 char file[20];
 printf("Enter file name: ");
 scanf("%19s", file);
 printf("Enter index block: ");
 scanf("%d", &index);
 printf("Enter number of data blocks: ");
 scanf("%d", &n);
 if (index < 0 || index >= 50 || n < 1 || n > 20) {
 printf("Invalid input\n");
 return 0;
 }
 used[index] = 1;
 printf("Enter data block numbers:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &block[i]);
 if (block[i] < 0 || block[i] >= 50)
 valid = 0;
 else if (used[block[i]])
 valid = 0;
 else
 used[block[i]] = 1;
 }
 if (!valid) {
 printf("Invalid or repeated block\n");
 return 0;
 }
 printf("\nFile: %s\nIndex block: %d\n", file, index);
 printf("Data blocks: ");
 for (i = 0; i < n; i++)
EXPERIMENT 14 (CONTINUED) | SEQUENTIAL AND INDEXED FILE 
ALLOCATION
14(B) Indexed File Allocation
ALGORITHM
Step 1: Read file name, index block and number of data blocks.
Step 2: Validate index location and number of data blocks.
Step 3: Read each proposed data-block number.
Step 4: Check for valid positions, repeats and conflicts with the index block.
Step 5: Display the index and allocated data blocks if valid.
Step 6: Stop.
PROGRAM
#include <stdio.h>
int main() {
 int index, n, block[20], used[50] = {0};
 int i, valid = 1;
 char file[20];
 printf("Enter file name: ");
 scanf("%19s", file);
 printf("Enter index block: ");
 scanf("%d", &index);
 printf("Enter number of data blocks: ");
 scanf("%d", &n);
 if (index < 0 || index >= 50 || n < 1 || n > 20) {
 printf("Invalid input\n");
 return 0;
 }
 used[index] = 1;
 printf("Enter data block numbers:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &block[i]);
 if (block[i] < 0 || block[i] >= 50)
 valid = 0;
 else if (used[block[i]])
 valid = 0;
 else
 used[block[i]] = 1;
 }
 if (!valid) {
 printf("Invalid or repeated block\n");
 return 0;
 }
 printf("\nFile: %s\nIndex block: %d\n", file, index);
 printf("Data blocks: ");
 for (i = 0; i < n; i++)
EXPERIMENT 14 (CONTINUED) | SEQUENTIAL AND INDEXED FILE 
ALLOCATION
14(B) Indexed File Allocation
ALGORITHM
Step 1: Read file name, index block and number of data blocks.
Step 2: Validate index location and number of data blocks.
Step 3: Read each proposed data-block number.
Step 4: Check for valid positions, repeats and conflicts with the index block.
Step 5: Display the index and allocated data blocks if valid.
Step 6: Stop.
PROGRAM
#include <stdio.h>
int main() {
 int index, n, block[20], used[50] = {0};
 int i, valid = 1;
 char file[20];
 printf("Enter file name: ");
 scanf("%19s", file);
 printf("Enter index block: ");
 scanf("%d", &index);
 printf("Enter number of data blocks: ");
 scanf("%d", &n);
 if (index < 0 || index >= 50 || n < 1 || n > 20) {
 printf("Invalid input\n");
 return 0;
 }
 used[index] = 1;
 printf("Enter data block numbers:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &block[i]);
 if (block[i] < 0 || block[i] >= 50)
 valid = 0;
 else if (used[block[i]])
 valid = 0;
 else
 used[block[i]] = 1;
 }
 if (!valid) {
 printf("Invalid or repeated block\n");
 return 0;
 }
 printf("\nFile: %s\nIndex block: %d\n", file, index);
 printf("Data blocks: ");
 for (i = 0; i < n; i++)
EXPERIMENT 14 (CONTINUED) | SEQUENTIAL AND INDEXED FILE 
ALLOCATION
14(B) Indexed File Allocation
ALGORITHM
Step 1: Read file name, index block and number of data blocks.
Step 2: Validate index location and number of data blocks.
Step 3: Read each proposed data-block number.
Step 4: Check for valid positions, repeats and conflicts with the index block.
Step 5: Display the index and allocated data blocks if valid.
Step 6: Stop.
PROGRAM
#include <stdio.h>
int main() {
 int index, n, block[20], used[50] = {0};
 int i, valid = 1;
 char file[20];
 printf("Enter file name: ");
 scanf("%19s", file);
 printf("Enter index block: ");
 scanf("%d", &index);
 printf("Enter number of data blocks: ");
 scanf("%d", &n);
 if (index < 0 || index >= 50 || n < 1 || n > 20) {
 printf("Invalid input\n");
 return 0;
 }
 used[index] = 1;
 printf("Enter data block numbers:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &block[i]);
 if (block[i] < 0 || block[i] >= 50)
 valid = 0;
 else if (used[block[i]])
 valid = 0;
 else
 used[block[i]] = 1;
 }
 if (!valid) {
 printf("Invalid or repeated block\n");
 return 0;
 }
 printf("\nFile: %s\nIndex block: %d\n", file, index);
 printf("Data blocks: ");
 for (i = 0; i < n; i++)
EXPERIMENT 14 (CONTINUED) | SEQUENTIAL AND INDEXED FILE 
ALLOCATION
14(B) Indexed File Allocation
ALGORITHM
Step 1: Read file name, index block and number of data blocks.
Step 2: Validate index location and number of data blocks.
Step 3: Read each proposed data-block number.
Step 4: Check for valid positions, repeats and conflicts with the index block.
Step 5: Display the index and allocated data blocks if valid.
Step 6: Stop.
PROGRAM
#include <stdio.h>
int main() {
 int index, n, block[20], used[50] = {0};
 int i, valid = 1;
 char file[20];
 printf("Enter file name: ");
 scanf("%19s", file);
 printf("Enter index block: ");
 scanf("%d", &index);
 printf("Enter number of data blocks: ");
 scanf("%d", &n);
 if (index < 0 || index >= 50 || n < 1 || n > 20) {
 printf("Invalid input\n");
 return 0;
 }
 used[index] = 1;
 printf("Enter data block numbers:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &block[i]);
 if (block[i] < 0 || block[i] >= 50)
 valid = 0;
 else if (used[block[i]])
 valid = 0;
 else
 used[block[i]] = 1;
 }
 if (!valid) {
 printf("Invalid or repeated block\n");
 return 0;
 }
 printf("\nFile: %s\nIndex block: %d\n", file, index);
 printf("Data blocks: ");
 for (i = 0; i < n; i++)
 printf("%d ", block[i]);
 return 0;
}
