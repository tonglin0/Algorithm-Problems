#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,f=1,n;
    scanf("%d",&n);
    if (n==1) printf("\\n\n");
    else
    {
        for (i=2;i<=sqrt(n);i++)
          if (n%i==0) 
          {
            printf("\\n\n");
            f=0;
            break;
          }
        if (f) printf("\\t\n");
    }
    //system("pause");
    return 0;
} 
