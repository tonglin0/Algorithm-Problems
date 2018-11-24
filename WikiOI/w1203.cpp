#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a,b,c;
    scanf("%lf%lf",&a,&b);
    c=a-b;
    if (c<0) c=-c;
    if (c<=0.00000001) printf("yes");
    else printf("no");
    //system("pause");
    return 0;
} 
