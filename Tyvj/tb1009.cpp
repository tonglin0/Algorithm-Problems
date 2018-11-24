#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
  double m;
  int i,n;
  scanf("%d",&n);
  if (n==1)
  {
    printf("No");
    return 0;
  }
  m=floor(sqrt(n));
  for (i=2;i<=m;i++)
    if (n%i==0)
    {
      printf("No\n");
      return 0;
    }
  printf("Yes\n"); 
  return 0;
}
