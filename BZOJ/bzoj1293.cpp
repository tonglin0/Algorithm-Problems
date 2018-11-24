#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int cur[63],num[63];
vector<int> g[63];

int main()
{
  freopen("1293.in","r",stdin);
  freopen("1293_2.out","w",stdout);
  memset(cur,0,sizeof(cur));
  memset(num,0,sizeof(num));
  int n,m,i,j,k,t;
  for (i=0;i<63;i++) g[i].clear();
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  {
    scanf("%d",&num[i]);
    for (j=1;j<=num[i];j++)
    {
      int u;
      scanf("%d",&u);
      g[i].push_back(u);
    }
  }
  long long ans=(long long)1e11;
  int max=-1;
  for (i=1;i<=m;i++)
  {
    pii x;
    x.first=g[i][0];
    x.second=i;
    q.push(x);
    if (x.first>max) max=x.first;
  }
  while(1)
  {
    pii x;
    x=q.top();q.pop();
    if (max-x.first<ans) ans=max-x.first;
    int u=x.second;
    if (++cur[u]>=num[u])
      break;
    else
    {
      q.push(make_pair(g[u][cur[u]],u));
      if (g[u][cur[u]]>max) max=g[u][cur[u]];
    }
  }
  printf("%d\n",ans);
  return 0;
}
