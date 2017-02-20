#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define MN 32100
using namespace std;

struct node{int x,y1,y2;};
node q[MN];
int set[MN<<1];
int ql,qr;
bool cmp(node a,node b){return a.x<b.x;}
bool vis[8002][8002];
vector<int> g[MN>>1];

void build(int p,int l,int r)
{
  if (l==r) 
  {
    set[p]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r); 
}

void pushdown(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  set[lc]=set[rc]=set[p];
  set[p]=-1;
}

void query(int p,int l,int r,int k)
{
  if (set[p]>=0)
  {
    vis[set[p]][k]=true;
    return ;
  }
  int mid=(l+r)>>1;
  if (set[p]!=-1)
    pushdown(p,l,r);
  if (ql<=mid)
    query(p<<1,l,mid,k);
  if (qr>mid)
    query(p<<1|1,mid+1,r,k);
}

void update(int p,int l,int r,int k)
{
  if (ql<=l&&qr>=r)
  {
    set[p]=k;
    return ;
  }
  int mid=(l+r)>>1;
  if (set[p]!=-1)
    pushdown(p,l,r);
  if (ql<=mid)
    update(p<<1,l,mid,k);
  if (qr>mid)
    update(p<<1|1,mid+1,r,k);
  /*if (set[p<<1]!=-1&&set[p<<1]==set[p<<1|1])
    set[p]=set[p<<1];
  else
    set[p]=-1;*/
}

int main()
{
  freopen("1436.in","r",stdin);
  freopen("1436.out","w",stdout);
  int T,n,i,j,k,m;
  scanf("%d",&T);
  while(T--)
  {
    memset(set,0,sizeof(set));//build(1,0,16004);
    //build(1,0,16004);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&q[i].y1,&q[i].y2,&q[i].x);
      q[i].y1<<=1;q[i].y2<<=1;
    }
    sort(q+1,q+n+1,cmp);
    memset(vis,0,sizeof(vis));
    for (i=1;i<=n;i++)
    {
      ql=q[i].y1;qr=q[i].y2;
      query(1,0,16004,i);
      update(1,0,16004,i);
    }
    int ans=0;
    for (i=0;i<(MN>>1);i++)
      g[i].clear();
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (vis[i][j])
          g[i].push_back(j);
    /*for (k=1;k<=n;k++)
      for(i=1;i<=n;i++)
        if (vis[i][k])
          for (j=1;j<=n;j++)
            if (vis[i][j]&&vis[k][j])
              ans++;*/
    for (i=1;i<=n;i++)
    {
      for (j=0;j<g[i].size();j++)
      {
        int u=g[i][j];
        for (k=0;k<g[u].size();k++)
          if (vis[i][g[u][k]])
            ans++;
      }
    }  
    printf("%d\n",ans);
  }
  return 0;
}
