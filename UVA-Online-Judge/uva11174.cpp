#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
#define M 1000000007
#define lint long long
using namespace std;

lint s[40090];
lint fac[40090];
lint rfac[40090];
vector<int> g[40090];
bool vis[40090];

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

lint rev(lint a,lint n)
{
  lint x,y,d;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

lint find(int x)
{
  if (vis[x])
    return s[x];
  vis[x]=true;
  s[x]=1;
  for (int i=0;i<g[x].size();i++)
    s[x]+=find(g[x][i]);
  return s[x];
}

int main()
{
  freopen("11174.in","r",stdin);
  freopen("11174.out","w",stdout);
  lint T,i,j,k,m,n;
  scanf("%lld",&T);
  fac[0]=1;
  for (i=1;i<=40002;i++)
    fac[i]=i*fac[i-1]%M;
  for (i=1;i<=40002;i++)
    rfac[i]=rev(i,M);
  while(T--)
  {
    for (i=0;i<40009;i++)
      g[i].clear();
    memset(vis,0,sizeof(vis));
    memset(s,0,sizeof(s));
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=m;i++)
    {
      lint u,v;
      scanf("%lld%lld",&u,&v);
      g[v].push_back(u);
	}
	for (i=1;i<=n;i++)
	  if (!vis[i])
	    s[i]=find(i);
	lint ans=fac[n];
	for (i=1;i<=n;i++)
	  ans=ans*rfac[s[i]]%M;
	printf("%lld\n",(ans%M+M)%M);
  }
  return 0;
}
