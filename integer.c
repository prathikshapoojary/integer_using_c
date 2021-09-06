
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argsv[])
{
        int fd[2];
        int val=100;
        pipe(fd);
        if(fork() != 0)
        {
                close(fd[0]);
                printf(" Parent process passed number is: %d\n",val);
                write(fd[1], &val, sizeof(val));
                close(fd[1]);
        }
        else
        {

                close(fd[1]);
                read(fd[0], &val, sizeof(val));
                printf("Child(%d) received value : %d \n", getpid(),val);
                int r,sum=0, temp= val;
                while(val>0)
                {
                        r = val%10;
                        sum = sum+(r*r*r);
                        val=val/10;
                }
                if(temp == sum)
                {
                        printf("\nYES!\n");
                }
                else
                {
                        printf("\nNO\n");
                }
                close(fd[0]);
        }
        return 0;
}
~                                                                                                               ~            
