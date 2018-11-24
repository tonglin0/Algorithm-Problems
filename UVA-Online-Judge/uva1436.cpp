#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define lint long long
#define MN 500009
using namespace std;

lint MOD,n;
lint pre[MN];
lint isleaf[MN];
lint s[MN];
bool vis[MN];
lint c[MN];
lint s1[MN];//,s2[MN];

lint pow_mod(lint a,lint b,lint c)
{
  lint ans=1;
  lint t=a%c;
  while(b)
  {
    if (b&1) ans=ans*t%c;
    b>>=1;
    t=t*t%c;
  }
  return ans;
}

void bfs()
{
  queue<int> q;
  pre[1]=0;
  for (int i=1;i<=n;i++)
    s[i]=1;
  for (int i=1;i<=n;i++)
    if (!isleaf[i])
      q.push(i);
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
	if (u==1)
      continue;
    s[pre[u]]+=s[u];
    isleaf[pre[u]]--;
    if (!isleaf[pre[u]])
      q.push(pre[u]);
  }
}

int main()
{
  freopen("1436.in","r",stdin);
  freopen("1436.out","w",stdout);
  lint T,i,j,k,m;
  scanf("%lld",&T);
  lint p=0;
  memset(vis,0,sizeof(vis));
  for (i=2;i<=500000;i++)
    if (!vis[i])
    {
	  c[++p]=i;
	  for (j=i*i;j<=500000;j+=i)
	    vis[j]=true;
    }
  while(T--)
  {
    scanf("%lld%lld",&n,&MOD);
    memset(isleaf,0,sizeof(isleaf));
    memset(s,0,sizeof(s));
	for (i=2;i<=n;i++)
    {
      scanf("%lld",&pre[i]);
      isleaf[pre[i]]++;
	}
	bfs();
	memset(s1,0,sizeof(s1));
	//memset(s2,0,sizeof(s2));
	lint tmpn=n;
	for (i=1;i<=p;i++)
	{
	  n=tmpn;
	  if (c[i]>n) break;
	  while(n)
	  {
	    s1[i]+=n/c[i];
	    n/=c[i];
	  }
	}
	n=tmpn;
	for (i=1;i<=n;i++)
	{
	  for (j=1;j<=p&&s[i]!=1;j++)
	  {
	    while(s[i]%c[j]==0)
	    {
	      s1[j]--;
	      s[i]/=c[j];
		}
	  }
	}
	lint ans=1;
	for (i=1;i<=p;i++)
	  ans=ans*pow_mod(c[i],s1[i],MOD)%MOD;
	printf("%lld\n",ans);
  }
  return 0;
}
