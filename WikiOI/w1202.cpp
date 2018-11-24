#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,n,s=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);
        s+=a;
    }
    printf("%d\n",s);
    //system("pause");
    return 0; 
}
