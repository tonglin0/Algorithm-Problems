#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<ctime>
#define lint long long
#define INF (int)1e9
using namespace std;

lint c[1000009];

lint gcd(lint a,lint b)
{
  while(b)
  {
    lint t=a;
    a=b;
    b=t%b;
  }
  return a;
}

int main()
{
  freopen("3505.in","r",stdin);
  freopen("3505.out","w",stdout);
  lint n,m,i,j,k,ca;
  //cin>>n>>m;
  scanf("%lld%lld",&n,&m);
  n++;m++;
  c[0]=c[1]=c[2]=0;
  for (i=3;i<=n*m;i++)
    c[i]=(i-1)*(i-2)/2*i/3;
  lint ans=c[n*m];
  ans-=c[m]*n;
  ans-=c[n]*m;
  for (i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
      lint s=(n-i)*(m-j)*(gcd(i,j)-1)*2;
      ans-=s;
	}
  printf("%lld\n",ans);
  //cout<<ans<<endl;
  return 0;
}

