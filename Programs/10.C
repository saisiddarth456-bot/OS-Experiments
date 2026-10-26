#include <stdio.h>
int main() {
 int n,f,a[50],q[10],i,j,k=0,hit=0,fault=0,found;
 printf("Enter number of pages: ");
 scanf("%d",&n);
 printf("Enter number of frames: ");
 scanf("%d",&f);
 if (n < 1 || n > 50 || f < 1 || f > 10) return 1;
 for(i=0;i<f;i++) q[i]=-1;
 printf("Enter page sequence: ");
 for(i=0;i<n;i++) scanf("%d",&a[i]);
 for(i=0;i<n;i++) {
 found=0;
 for(j=0;j<f;j++)
 if(q[j]==a[i]) found=1;
 if(found) hit++;
 else {
 q[k]=a[i];
 k=(k+1)%f;
 fault++;
 }
 }
 printf("\nPage Faults = %d\nHits = %d\n",fault,hit);
 return 0;
}
