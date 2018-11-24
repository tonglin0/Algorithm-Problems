#include <stdlib.h>
#include <stdio.h>

int main()
{
    char ch;
    int s,i,f=1,n,j;
    scanf("%d\n%d\n",&n,&s);
    for (i=1;i<=n;i++)
    {
        scanf("%c %d\n",&ch,&j);
        if (((ch=='/')||(ch=='%'))&&(j==0))
        {
            printf("Error!");
            f=0;
            break;                                   
        }
        else
        {
            if (ch=='+')
              s+=j;
            else if (ch=='-')
              s-=j;
            else if (ch=='*')
              s*=j;
            else if (ch=='/')
              s/=j;
            else if (ch=='%')
              s%=j;
        }
    }
    if(f) printf("%d\n",s);
    return 0;
} 
