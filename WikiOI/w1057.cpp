#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f=1,sum=0,i,j,s=0,t;
    for (i=1;i<=12;i++)
    { 
        s+=300;
        scanf("%d\n",&t);
        if (s<t)
           {
                printf("-%d\n",i);
                f=0; 
                break;
           }
        else
        {
            s-=t;
            t=s/100;
            sum+=t*100;
            s-=t*100;
        }
    }
    if (f) printf("%d",s+sum/10*12);
    return 0;
} 
