#include <stdio.h>
int main() {
 int total_resources, allocated, max_need;
 printf("Enter Total Resources, Current Allocated, and Max Need: ");
 if (scanf("%d %d %d", &total_resources,
 &allocated, &max_need) == 3) {
 if (total_resources < 0 || allocated < 0 ||
 allocated > total_resources || max_need < allocated) {
 printf("Invalid input\n");
 return 1;
 }
 int available = total_resources - allocated;
 int remaining_need = max_need - allocated;
 printf("\nAvailable: %d | Remaining Need: %d\n",
 available, remaining_need);
 printf("State: %s\n",
 (available >= remaining_need)
 ? "SAFE (Request can be granted)"
 : "UNSAFE (Insufficient resources)");
 }
 return 0;
}
