#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[103][103],b[103][103];
int main()
{
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  int n,i,j,k;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      b[j][n-i+1]=a[i][j];
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n;j++)
      printf("%d ",b[i][j]);
    printf("\n");
  }
  //system("pause");
  return 0;
} 
