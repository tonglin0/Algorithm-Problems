#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long long a[93];
int main()
{
  int i,n;
  scanf("%d",&n);
  if (n==0)
  {
    printf("1\n");
    return 0;
  } 
  a[1]=2;
  a[2]=3;
  for (i=3;i<=n;i++)
    a[i]=a[i-1]+a[i-2];
  printf("%llu",a[n]);
  //system("pause");
  return 0;
} 
