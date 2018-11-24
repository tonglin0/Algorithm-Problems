#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int a[103][103];
int main()
{
  memset(a,0,sizeof(a));
  int x,y,n,i,j,k,s;
  scanf("%d",&n);
  x=0;
  y=n;
  s=0;
  while(s<n*n)
  {
    while(!a[x+1][y]&&x+1<=n) a[++x][y]=++s;
    while(!a[x][y-1]&&y-1>=1) a[x][--y]=++s;
    while(!a[x-1][y]&&x-1>=1) a[--x][y]=++s;
    while(!a[x][y+1]&&y+1<=n) a[x][++y]=++s; 
  }
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n;j++)
      printf("%d ",a[i][j]);
    printf("\n");
  }
  //system("pause");
  return 0;
} 
