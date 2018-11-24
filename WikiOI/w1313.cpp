#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  double m;
  int i,n;
  scanf("%d",&n);
  m=floor(sqrt(n+0.5));
  for (i=2;i<=m;i++)
    if (n%i==0)
    {
      printf("%d\n",n/i);
      return 0;
    }
  return 0;
} 
