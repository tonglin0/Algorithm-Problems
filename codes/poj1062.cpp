#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

typedef pair<int,int> pii;
struct node{int v,w;bool e;};
priority_queue<pii,vector<pii>,greater<pii> >q;
vector<node> g[104];
int dis[104],ord[104];
bool vis[104];
vector<int> ex;

int main()
{
  //freopen("1062.in","r",stdin);
  //freopen("1062.out","w",stdout);
  int n,i,j,m,t,k;
  scanf("%d%d",&m,&n);
  t=0;
  ex.clear();
  memset(ord,0,sizeof(ord));
  for (i=1;i<=n;i++)
  {
    int u,v,w,p,o;
    scanf("%d%d%d",&p,&o,&k);
    ord[i]=o;
    bool flag=false;
    for (j=0;j<ex.size();j++)
      if (ex[j]==o)
      {
        flag=true;
        break;
      }
    if (!flag) ex.push_back(o);
    node x;
    x.v=i;
    x.w=p;
    x.e=true;
    g[t].push_back(x);
    for (j=1;j<=k;j++)
    {
      scanf("%d%d",&v,&w);
      x.v=i;
      x.w=w;
      x.e=true;
      g[v].push_back(x);
    }
  }
  int ii,ans=(int)2e9;
  for (ii=0;ii<ex.size();ii++)
  {
  int l=ex[ii],r=ex[ii]+m;
  for (i=0;i<=n;i++)
  {
    for (j=0;j<g[i].size();j++)
    {
      g[i][j].e=true;  
      if (ord[g[i][j].v]>r||ord[g[i][j].v]<l)
      {
        g[i][j].e=false;
        //g[i].erase(g[i].begin()+j,g[i].begin()+j+1);
        //j--;
      }
    }
  }
  memset(dis,127,sizeof(dis));
  dis[0]=0;
  memset(vis,0,sizeof(vis));
  q.push(make_pair(0,0));
  while(!q.empty())
  {
    pii x=q.top();
    q.pop();
    int u=x.second;
    if (vis[u]) continue;
    for (i=0;i<g[u].size();i++)
      if (g[u][i].e&&!vis[g[u][i].v]&&dis[u]<dis[g[u][i].v]-g[u][i].w)
        q.push(make_pair(dis[g[u][i].v]=dis[u]+g[u][i].w,g[u][i].v));
  }
  ans=min(ans,dis[1]);
  }
  printf("%d\n",ans);
  return 0;
}
