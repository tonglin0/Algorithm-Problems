#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lint long long
using namespace std;

lint phi(lint x)
{
  lint ans=x;
  lint m=(lint)sqrt(x+0.5);
  for (lint i=2;i<=m;i++)
    if (x%i==0)
    {
      ans=ans/i*(i-1);
      while(x%i==0)
        x/=i;
	}
  if (x>1)
    ans=ans/x*(x-1);
  return ans;
}

int main()
{
  freopen("2480.in","r",stdin);
  freopen("2480.out","w",stdout);
  lint n,i,j,k,m;
  while(scanf("%I64d",&n)==1)
  {
    m=(lint)(sqrt(n+0.5));
    lint ans=0;
	for (i=1;i<=m;i++)
	if (n%i==0)
	{
	  if (i*i==n)
	    ans+=i*phi(n/i);
	  else
	  {
	    ans+=i*phi(n/i);
	    ans+=n/i*phi(i);
	  }
	}
	printf("%I64d\n",ans);
  }
  return 0;
}
