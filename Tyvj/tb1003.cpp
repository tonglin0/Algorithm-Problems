#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  unsigned long long a,b;
  double m;
  scanf("%llu%llu",&a,&b);
  if (a==0||b==0)
  {
    printf("1");
    return 0;
  }/*
  a=1;
  for (int i=1;i<=63;i++)
    a*=2;
  b=a;*/
  //printf("%I64u\n",a);
  //return 0;
  m=floor(log(a)/log(10)+log(b)/log(10)+1);
  printf("%.0lf",m);
  return 0;
} 
