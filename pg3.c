#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
//iterns
void main(){
int iterns,i;
printf("enter iterns:");
scanf("%d",&iterns);
int itern[11]={0};
#pragma omp parallel for schedule(static,2)
for(i=1; i<=iterns; i++){
int t = omp_get_thread_num();
#pragma omp critical
{
itern[t]+=1;
printf("thread %d itern %d value: %d\n",t,itern[t],i);
}
}
}

