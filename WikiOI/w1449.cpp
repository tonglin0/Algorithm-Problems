#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s=1,i,n;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      s*=i;
    printf("%d",s);
    //system("pause");
    return 0;
} 
