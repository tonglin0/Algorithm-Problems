#include <stdlib.h>
#include <stdio.h>

int main()
{    
    double a,b,sa=0,ans;
    int i,n;
    ans=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%lf%lf",&a,&b);
        ans+=a*b;
        sa+=a;
    }
    ans=ans/sa;
    printf("%.2lf",ans);
    //system("pause");
    return 0;
} 
