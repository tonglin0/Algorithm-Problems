#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int a[14];
int main()
{
    int t,i,k,n,j;
    memset(a,0,sizeof(a));
    scanf("%d\n",&n);
    for (i=1;i<=n;i++)
      scanf("%d\n",&a[i]);
    for (i=1;i<=n-1;i++)
      {
        k=i;
        for (j=i+1;j<=n;j++)
          if (a[j]<a[k])
            k=j;
        t=a[k];
        a[k]=a[i];
        a[i]=t;
      }
    for (i=1;i<=n;i++)
      printf("%d\n",a[i]);
    return 0;
} 
