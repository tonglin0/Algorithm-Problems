#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
  int n,i,j;
  short a[100000];
  memset(a,0,sizeof(a));
  scanf("%d",&n);
  double m=floor(sqrt(n)+0.5);
  double mm=floor(sqrt(m)+0.5);
  for (i=2;i<=mm;)
  {
    for (j=i*i;j<=m;j+=i) a[j]=1;
    i++; 
    while (i<=mm&&a[i]) i++;
  }
  int ans=0;
  for (i=2;i<=m;i++)
    if (!a[i]) ans++;
  printf("%d\n",ans);
  //system("pause");
  return 0;
} 
