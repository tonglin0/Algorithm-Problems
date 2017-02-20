#include<cstdio>
#include<cstdlib>
#include<vector> 
#include<cstring>
#include<queue>
#define INF 2e9
using namespace std;

queue <int> qq;
vector<int> g[403];
int pa[403],dis[403],low[403],c[403][403],e[403],gap[403];
bool vis[403];//,che[403];

int main()
{
  freopen("3281.in","r",stdin);
  freopen("3281.out","w",stdout);
  int n,m,p,q,i,j;
  memset(c,0,sizeof(c));
  scanf("%d%d%d",&n,&p,&q);
  for (i=1;i<=n;i++)
  {
    int u,v,w,d1,d2;
    scanf("%d%d",&d1,&d2);
    c[i][i+100]=1;
    g[i].push_back(i+100);
    //
    g[i+100].push_back(i);
    for (j=1;j<=d1;j++)
    {
      int d;
      scanf("%d",&d);
      c[d+200][i]=1;
      //
      g[i].push_back(d+200);
      g[d+200].push_back(i);
    } 
    for (j=1;j<=d2;j++)
    {
      int d;
      scanf("%d",&d);
      c[i+100][d+300]=1;
      //
      g[d+300].push_back(i+100);
      g[i+100].push_back(d+300);
    }
  }
  for (i=1;i<=p;i++)
  {
    c[0][i+200]=1;
    //
    g[i+200].push_back(0);
    g[0].push_back(i+200);
  }
  for (i=1;i<=q;i++)
  {
    c[i+300][401]=1;
    //
    g[401].push_back(i+300);
    g[i+300].push_back(401);
  }
  memset(dis,0,sizeof(dis));
  for (i=0;i<=q+300;i++) dis[i]=-1;
  dis[401]=0;
  memset(vis,0,sizeof(vis));
  qq.push(401);
  vis[401]=true;
  while(!qq.empty())
  {
    int u=qq.front();
    qq.pop();
    for (i=1;i<=n;i++)
    {
      if (!vis[i]&&c[i][u]) 
      {
        qq.push(i);
        vis[i]=true;
        dis[i]=dis[u]+1;
      }
      if (!vis[i+100]&&c[i+100][u])
      {
        qq.push(i+100);
        vis[i+100]=true;
        dis[i+100]=dis[u]+1;
      }
    }
    for (i=1;i<=p;i++)
      if (!vis[i+200]&&c[i+200][u])
      {
        qq.push(i+200);
        vis[i+200]=true;
        dis[i+200]=dis[u]+1;
      }
    for (i=1;i<=q;i++)
      if (!vis[i+300]&&c[i+300][u])
      {
        qq.push(i+300);
        vis[i+300]=true;
        dis[i+300]=dis[u]+1;
      }
  }
  //memset(che,0,sizeof(che));
  dis[0]=5;
  /*
  for (i=1;i<=q;i++)
  {
    printf("i=%d ",i+300);
    for (j=0;j<g[i+300].size();j++)
      printf("%d ",g[i+300][j]);
    printf("\n");
  }
  return 0;*/
  
  memset(gap,0,sizeof(gap));
  memset(e,0,sizeof(e));
  memset(low,0,sizeof(low));
  memset(pa,0,sizeof(pa));
  for (i=1;i<=n;i++)
  { 
    gap[dis[i]]++;
    gap[dis[i+100]]++;
  }
  for (i=1;i<=p;i++)
    gap[dis[i+200]]++;
  for (i=1;i<=q;i++)
    gap[dis[i+300]]++;
  gap[5]++;
  int u,top=0,ans=0;
  bool flag;
  low[0]=int(INF);
  while(dis[0]<n+n+p+q+2)
  {
    flag=false;
    int d;
    d=g[top].size();
    for (i=e[top];i<d;i++)
    {
      u=g[top][i];
      if (c[top][u]&&dis[top]-1==dis[u])
      {
        flag=true;
        e[top]=i; 
        break;
      }
    }
    if (flag)
    {
      pa[u]=top;
      low[u]=min(low[top],c[top][u]);
      top=u;
      if (top==401)
      {
        ans+=low[401];
        int j=401;
        while(j!=0)
        {
          c[pa[j]][j]-=low[401];
          c[j][pa[j]]+=low[401];
          j=pa[j];
        }
        top=0;
        memset(pa,0,sizeof(pa));
        memset(low,0,sizeof(low));
        low[0]=int(INF);
      } 
    }
    else
    {
      int mi=n+n+p+q+1;
      int k=g[top].size();
      for (i=0;i<k;i++)
      {
        if (c[top][g[top][i]]&&dis[g[top][i]]<mi&&dis[g[top][i]]!=-1)
        {
          mi=dis[g[top][i]];
        }
      }
      mi++;
      gap[dis[top]]--;
      if (!gap[dis[top]]) break;
      dis[top]=mi;
      gap[mi]++;
      e[top]=0;
      if (top!=0) top=pa[top];
    }
  }
  printf("%d\n",ans);
  return 0;
}
