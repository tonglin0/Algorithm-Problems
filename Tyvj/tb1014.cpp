#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long long a[100003];
int main()
{
  int n;
  unsigned long long i;
  memset(a,0,sizeof(a));
  a[1]=1;
  scanf("%d",&n);
  for (i=2;i<=n;i++)
    a[i]=a[i-1]+i*(i+1)/2;
  printf("%llu\n",a[n]);
  //system("pause");
} 
