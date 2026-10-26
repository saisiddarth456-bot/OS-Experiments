#include <stdio.h>
int main() {
 int n,i,j,p[10],t[10],w[10],ta[10],pr[10],x;
 char name[10][20],temp[20];
 printf("Enter number of patients: ");
 scanf("%d",&n);
 if (n < 1 || n > 10) return 1;
 for(i=0;i<n;i++) {
 printf("\nPatient %d name: ",i+1);
 scanf("%19s",name[i]);
 printf("Treatment time: ");
 scanf("%d",&t[i]);
 printf("Priority (1=Highest): ");
 scanf("%d",&pr[i]);
 }
 for(i=0;i<n-1;i++)
 for(j=i+1;j<n;j++)
 if(pr[i]>pr[j]) {
 x=pr[i]; pr[i]=pr[j]; pr[j]=x;
 x=t[i]; t[i]=t[j]; t[j]=x;
 sprintf(temp,"%s",name[i]);
 sprintf(name[i],"%s",name[j]);
 sprintf(name[j],"%s",temp);
 }
 w[0]=0;
 for(i=1;i<n;i++) w[i]=w[i-1]+t[i-1];

printf("\nPatient\tPriority\tTreatment\tWaiting\tTurnaround\n");
 for(i=0;i<n;i++) {
 ta[i]=w[i]+t[i];
 printf("%s\t%d\t\t%d\t\t%d\t%d\n",
 name[i],pr[i],t[i],w[i],ta[i]);
 }
 return 0;
}
