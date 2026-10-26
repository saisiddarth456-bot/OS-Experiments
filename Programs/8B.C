#include <stdio.h>
int main() {
 int rooms, time[10], total = 0;
 printf("Enter number of rooms to clean: ");
 if (scanf("%d", &rooms) == 1 && rooms > 0 && rooms <= 10) {
 for (int i = 0; i < rooms; i++) {
 printf("Room %d estimated cleaning time (mins): ", i + 1);
 scanf("%d", &time[i]);
 }
 for (int i = 0; i < rooms - 1; i++) {
 for (int j = 0; j < rooms - i - 1; j++) {
 if (time[j] > time[j + 1]) {
 int temp = time[j];
 time[j] = time[j + 1];
 time[j + 1] = temp;
 }
 }
 }
 printf("\nCleaning Schedule (Shortest First):\n");
 for (int i = 0; i < rooms; i++) {
 total += time[i];
 printf("Cleaning %d-min room completed at minute %d\n",
 time[i], total);
 }
 }
 return 0;
}
