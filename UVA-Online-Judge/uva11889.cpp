#include<cstdlib>
#include<cstdio>
#define lint long long
using namespace std;

lint gcd(lint a,lint b)
{
  lint t;
  while(b)
  {
    t=a;
    a=b;
    b=t%b;
  }
  return a;
}

int main()
{
  freopen("11889.in","r",stdin);
  freopen("11889.out","w",stdout);
  lint a,T,b,x,y,i,j;
  scanf("%lld",&T);
  while(T--)
  {
    scanf("%lld%lld",&x,&y);
    b=y/x;
    if (y%x)
      printf("NO SOLUTION\n");
    else
    {
      lint t;
      while((t=gcd(x,b))!=1&&b<y)
      {
        x/=t;
		b=b*t;
	  }
	  printf("%lld\n",b);
	}
  }
  return 0;
}
