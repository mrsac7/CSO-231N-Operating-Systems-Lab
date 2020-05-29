#include<stdio.h>
int main()
{
      int ms, mp[10], i, temp, n = 0;
      int ch = 1;
      printf("Enter size of memory: ");
      scanf("%d",&ms);
      temp = ms;
      for(i = 0; ch == 1; i++, n++)
      {
            printf("Enter memory required for process %d (in bytes): ", i + 1);
            scanf("%d", &mp[i]);
            if (mp[i] <= temp) {
                  printf("Memory is allocated for process %d\n", i + 1);
                  temp-=mp[i];
            }
            else {
                  printf("Memory is Full\n");
                  break;
            }
            printf("Do you want to continue (1/0): ");
            scanf("%d",&ch);
      }
      printf("Total Memory Available: %d\n", ms);
      for (i =  0; i < n; i++){
            printf("Process %d\tMemory Req: %d\n", i + 1, mp[i]);
      }
      printf("Total Memory Allocated is: %d\n", ms - temp);
      printf("Total External Fragmentation is: %d\n", temp);
}