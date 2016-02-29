#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include "shmExample.h"
#define SHMSZ 10


 int main(int argc, char** argv)
 {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     * We'll name our shared memory segment
     * "5678".
     */
    key = 5678;

    /*
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return -1;
    }
    
    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        return -1;
    }
    for(int i = 0; i < 9; i++)
    {
        shm[i] = '?';
    }
    shm[9] = 'P';
   
    int pid = fork();
    
    if(pid != 0)
    {
        while(1==1)
        {
            //parent
            if(shm[9] == 'P')
            {
                int notdone;
                notdone = 1;
                while(notdone == 1)
                {
                    int i = rand()%9;
                    if(shm[i] == '?')
                    {
                        shm[i] = 'x';
                        notdone = 0;
                        winCheck('x', shm);
                        shm[9] = 'C';
                    }
                }
            }
            waitWhileEqual('C', shm);
        }
    }
    else
    {
       while(1==1)
        {
            if(shm[9] == 'C')
            {
                int notdone2;
                notdone2 = 1;
                while(notdone2 == 1)
                {
                    int i = rand()%9;
                    if(shm[i] == '?')
                    {
                        shm[i] = 'o';
                        notdone2 = 0;
                        winCheck('o', shm);
                        shm[9] = 'P';
                    }
                }
            }
            waitWhileEqual('P', shm);
        }
    }
    
    printf("The mem address is: %p\n", shm);
    return 0;
 }
 
 void waitWhileEqual(char val, char* shm)
 {
    while(shm[9] == val)
    {
        //wait
    }
 }
 
 void winCheck(char c, char* shm)
 {
     if((shm[0] && shm[3] && shm[6] == c) || (shm[1] && shm[4] && shm[7] == c) || (shm[2] && shm[5] && shm[8] == c) ||
        (shm[0] && shm[1] && shm[2] == c) || (shm[3] && shm[4] && shm[5] == c) || (shm[6] && shm[7] && shm[8] == c) ||
        (shm[0] && shm[4] && shm[8] == c) || (shm[2] && shm[4] && shm[6] == c))
        {
            printf("the winner is: %c\n", c);
        }
        
        return 0;
 }