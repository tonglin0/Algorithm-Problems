#include<stdio.h>
#include<stdlib.h>

int main()
{
    int max,min,n;
    scanf("%d\n",&n);
    scanf("%d",&min);
    max=min;
    int a;
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&a);
        if (a<min) min=a;
        if (a>max) max=a;
    }
    printf("%d %d",min,max);
    //system("pause");
    return 0; 
}
