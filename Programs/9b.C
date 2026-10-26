#include <stdio.h>
int main() {
 int n,q,i,t=0,done,b[10],r[10],w[10]={0},ta[10];
 printf("Enter number of print jobs: ");
 scanf("%d",&n);
 if (n < 1 || n > 10) return 1;
 printf("Enter printing time for each job:\n");
 for(i=0;i<n;i++) {
 printf("Job %d: ",i+1);
 scanf("%d",&b[i]);
 r[i]=b[i];
 }
 printf("Enter time quantum: ");
 scanf("%d",&q);
 if (q <= 0) return 1;
 do {
 done=1;
 for(i=0;i<n;i++)
 if(r[i]>0) {
 done=0;
 if(r[i]>q) { t+=q; r[i]-=q; }
 else { t+=r[i]; r[i]=0; ta[i]=t; }
 }
 } while(!done);
 printf("\nJob\tBurst\tWaiting\tTurnaround\n");
 for(i=0;i<n;i++) {
 w[i]=ta[i]-b[i];
 printf("J%d\t%d\t%d\t%d\n",i+1,b[i],w[i],ta[i]);
 }
 return 0;
}
