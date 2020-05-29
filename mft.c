#include<stdio.h>
int main()
{
      int ms, bs, nob, ef, n, mp[10], tif=0;
      int i, p=0;
      printf("Enter size of memory: ");
      scanf("%d",&ms);
      printf("Enter block size: ");
      scanf("%d",&bs);
      nob = ms / bs, ef = ms - nob * bs;
      ef = nob;
      printf("Enter no.of processes: ");
      scanf("%d",&n);
      for (i = 0; i < n; i++) {
            printf("Enter memory required for process %d: ", i+1);
            scanf("%d",&mp[i]);
      }
      printf("No of blocks available in memory: %d\n", nob);

      for(i = 0; i < n && p < nob; i++)
      {
            printf("Process %d\tMemory Req: %d\t", i + 1, mp[i]);
            if (mp[i] > bs) printf("Not Allocated\t-------\n");
            else {
                  printf("Allocated\tInternal Fragmentation: %d\n", bs - mp[i]);
                  tif += bs - mp[i];
                  p++;
            }
      }
      if (i < n) printf("\n Memory is Full, Remaining process can't be accomodated\n");
      printf("Total Internal Fragmentation is: %d\n",tif);
      printf("Total External Fragmentation is: %d\n", (ef - p) * bs + ms - bs * nob);
}