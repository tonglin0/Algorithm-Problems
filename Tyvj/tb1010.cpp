#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int ans,n,i;
  scanf("%d",&n);
  double m=floor(sqrt(n)+0.5);
  if (m*m==n)
    ans=1;
  else
    ans=0;
  m=sqrt(n); 
  for (i=1;i<m;i++)
    if (n%i==0)
      ans+=2;
  printf("%d",ans);
  //system("pause");
  return 0;
} 
