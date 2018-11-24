#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#define lint long long
using namespace std;

lint min(lint a,lint b){return a<b?a:b;}

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

lint g[309][309];

int main()
{
  freopen("1393.in","r",stdin);
  freopen("1393.out","w",stdout);
  lint n,i,j,k,m;
  for (i=1;i<=300;i++)
    for (j=1;j<=i;j++)
      g[i][j]=g[j][i]=gcd(i,j);
  while(scanf("%lld%lld",&n,&m)==2)
  {
    if (n==0||m==0) break;
    lint ans=0;
    for (i=1;i<=n-1;i++)
      for (j=1;j<=m-1;j++)
        if (g[i][j]==1)
        {
          ans+=min(i,n-i)*(m-j);
          ans+=min(j,m-j)*(n-i);
          ans-=min(j,m-j)*min(i,n-i);
		}
	printf("%lld\n",2*ans);
  }
  return 0;
}
