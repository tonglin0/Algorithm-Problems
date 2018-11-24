#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1003];
int main()
{
  int i,n;
  scanf("%d\n",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  for (i=n;i>=2;i--)
    printf("%d ",a[i]);
  printf("%d\n",a[1]);
  //system("pause");
  return 0;
} 
