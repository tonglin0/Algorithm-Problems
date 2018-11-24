#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF (int)1e9
using namespace std;

struct monst{
       int time,money,ks;
};
monst mon[52];
bool map[52][52];
vector<int> g[52];
int n,cnt,m,ans;
bool vis[52];
struct node{
       int val,cost;
       bool operator < (node b) const{
            if (val!=b.val) return val<b.val;return cost>b.cost;
            };
};

void dfs(int u)
{
  g[cnt].push_back(u);
  vis[u]=true;
  for (int i=1;i<=n;i++)
    if (!vis[i]&&map[u][i])
      dfs(i);
}

void divide_group()
{
  int i,j;
  for (i=1;i<=n;i++)
    if (!vis[i])
    {
      cnt++;
      g[cnt].clear();
      dfs(i);
    }
}

void solve()
{
  int i,j,k;
  priority_queue<node> q1,q2;
  for (i=1;i<=cnt;i++)
  {
    while(!q1.empty())
      q1.pop();
    while(!q2.empty())
      q2.pop();
    node s;
    s.val=s.cost=0;
    q1.push(s);
    for (j=0;j<g[i].size();j++)
    {
      monst u=mon[g[i][j]];
      while(!q1.empty())
      {
        node t=q1.top();q1.pop();
        q2.push(t);
        t.val+=u.money;
        t.cost+=u.time;
        if (t.val>=m)
        {
          ans=min(ans,t.cost);
          continue;
        }
        if (t.cost>=ans)
          continue;
        q2.push(t);
      }
      int mincost=INF;
      while(!q2.empty())
      {
        node t=q2.top();q2.pop();
        if (t.cost<mincost)
        {
          q1.push(t);
          mincost=t.cost;
        }
      }
    }
  }
}

int main()
{
  freopen("3810.in","r",stdin);
  freopen("3810.out","w",stdout);
  int ca,ii=0,i,j,k;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    printf("Case %d: ",ii);
    scanf("%d%d",&n,&m);
    memset(map,0,sizeof(map));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&mon[i].time,&mon[i].money,&mon[i].ks);
      while(mon[i].ks--)
      {
        int u;
        scanf("%d",&u);
        map[i][u]=map[u][i]=true;
      }
    }
    cnt=0;
    memset(vis,0,sizeof(vis));
    divide_group();
    ans=INF;
    solve();
    if (ans==INF)
      printf("Poor Magina, you can't save the world all the time!\n");
    else
      printf("%d\n",ans);
  }
  return 0;
}
