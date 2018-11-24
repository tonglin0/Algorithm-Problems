#include<stdio.h>
#include<stdlib.h>

char a[503][503];
int main()
{
  int n,i,j;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      if (i==j||i+j==n+1)
        a[i][j]='X';
      else
        a[i][j]=' ';
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n;j++)
      putchar(a[i][j]);
    putchar('\n'); 
  }
  //system("pause");
  return 0;
}
