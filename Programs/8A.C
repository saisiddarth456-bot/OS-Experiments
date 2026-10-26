#include <stdio.h>
int main() {
 int planes, time, total_time = 0;
 printf("Enter number of planes waiting for takeoff (max 10): ");
 if (scanf("%d", &planes) == 1 && planes > 0) {
 for (int i = 1; i <= planes; i++) {
 printf("Plane %d takeoff prep time (mins): ", i);
 scanf("%d", &time);
 total_time += time;
 printf("Plane %d cleared for takeoff at minute %d\n",
 i, total_time);
 }
 }
 return 0;
}
