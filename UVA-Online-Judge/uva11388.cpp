#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
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
  freopen("11388.in","r",stdin);
  freopen("11388.out","w",stdout);
  lint k1,k2,T,a,b,i,j,k,x,y;
  cin>>T;
  while(T--)
  {
    cin>>x>>y;
    if (y%x)
    {
      printf("-1\n");
      continue;
	}
    /*lint m=(lint)(sqrt(y/x)+0.5);
    bool flag=false;
	for (k1=1;k1<=m;k1++)
    {
      k2=y/x/k1;
      a=k1*x;b=k2*x;
      lint g=gcd(a,b);
      if (g==x)
      {
        printf("%lld %lld\n",a,b);
        flag=true;
        break;
	  }
	}
	if (!flag)
	  printf("-1\n");*/
	printf("%lld %lld\n",x,y);
  }
  return 0;
}
