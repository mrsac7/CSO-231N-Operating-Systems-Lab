#include <stdio.h>
#include <stdlib.h>
void solve(int process[],int n,int bt[],int wt[],int tat[],int quantum)
{
   int rem_bt[n];
   for(int i=0;i<n;i++)
   rem_bt[i]=bt[i];
   int t=0;
   while(1)
   {
     int done= 1;
     for(int i=0;i<n;i++)
     {
        if(rem_bt[i]>0)
        {
          done= 0;
          if(rem_bt[i]>quantum)
          {
             t+=quantum;
             rem_bt[i]-=quantum;
          }
          else
          {
             t+=rem_bt[i];
             wt[i]=t-bt[i];
             rem_bt[i]=0;
          }
        }
     }
     if(done==1)
     break;
   }
   for(int i=0;i<n;i++)
   tat[i]=bt[i]+wt[i];
}
int main()
{
    int process[] = { 1, 2, 3},i;
    int n = sizeof process / sizeof process[0];
    int wt[n],tat[n];
    int bt[] = {1, 2, 3};
    int quantum = 2;
    solve(process,n,bt,wt,tat,quantum);
    for(i=0;i<n;i++)
     printf("Process=%d  Turn_around_time=%d  Waiting_time=%d\n",process[i],tat[i],wt[i]);
    return 0;
}