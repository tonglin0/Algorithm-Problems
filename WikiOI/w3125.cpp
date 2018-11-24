#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,m,i,j,k;
  scanf("%d%d",&n,&m);
  for (i=0;i<=n-1;i++)
  {
    for (j='A'+i;j>='A'&&-j+'A'+i+1<=m;j--)
      putchar(j);
    for (j='B';j<='B'+m-(i+1)-1;j++)
      putchar(j);
    putchar('\n');
  }   
  //system("pause");
  return 0;
}
