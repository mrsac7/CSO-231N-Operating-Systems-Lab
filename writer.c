#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
  
int main() 
{ 
    key_t key = ftok("shmfile",65); 
  
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
    printf("%d %d\n", key, shmid);
    char *s = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Write Data: ");
    scanf("%s",s);
    printf("Data written in memory: %s\n",s); 
    shmdt(s); 
  
    return 0; 
} 