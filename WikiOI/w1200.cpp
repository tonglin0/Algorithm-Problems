#include<cstdio>
#include<cstdlib>
#define LL long long
using namespace std;

void ex_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
  if (b==0)
  {
    d=a;
    x=1;
    y=0;
  }
  else
  {
    ex_gcd(b,a%b,d,y,x);
    y-=x*(a/b);
  }
}

int main()
{
  LL d,a,b,x,y;
  scanf("%I64d%I64d",&a,&b);
  ex_gcd(a,b,d,x,y);
  printf("%I64d\n",(x%b+b)%b);
  system("pause");
  return 0;
}
