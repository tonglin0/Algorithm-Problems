#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 200003
using namespace std;

int sum[MN*35],root[MN],ls[MN*35],rs[MN*35];
int fa[MN][35],dep[MN],a[MN],b[MN];
int n,tot=0,sz;
vector<int> g[MN];

void change(int &k,int o,int l,int r,int p)
{
  k=++tot;
  sum[k]=sum[o]+1;ls[k]=ls[o];rs[k]=rs[o];
  if (l==r)
    return ;
  int mid=(l+r)>>1;
  if (p<=mid)
    change(ls[k],ls[o],l,mid,p);
  else
    change(rs[k],rs[o],mid+1,r,p);
}

void dfs(int u,int pre)
{
  fa[u][0]=pre;
  dep[u]=dep[pre]+1;
  int p=lower_bound(b+1,b+sz+1,a[u])-b;
  change(root[u],root[pre],1,sz,p);
  for (int i=0;i<g[u].size();i++)
    if (g[u][i]!=pre)
      dfs(g[u][i],u);
}

void build(int &k,int l,int r)
{
  k=++tot;
  sum[k]=0;
  if (l==r)
    return ;
  int mid=(l+r)>>1;
  build(ls[k],l,mid);
  build(rs[k],mid+1,r);
}

void bz()
{
  int m=(int)floor(log(n+0.1)/log(2.0));
  for (int j=1;j<=m;j++)
    for (int i=1;i<=n;i++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
}

int get_lca(int p,int q)
{
  if (dep[p]<dep[q])
    swap(p,q);
  int m=(int)floor(log(n+0.1)/log(2.0));
  for (int j=m;j>=0;j--)
    if (dep[fa[p][j]]>=dep[q])
      p=fa[p][j];
  if (p==q)
    return p;
  for (int j=m;j>=0;j--)
    if (fa[p][j]!=fa[q][j])
    {
      p=fa[p][j];
      q=fa[q][j];
	}
  return fa[p][0];
}

int query(int ql,int qr,int lca,int lca2,int k,int l,int r)
{
  if (l==r)
    return l;
  int suma=sum[ls[ql]]+sum[ls[qr]];
  int sumb=sum[ls[lca]]+sum[ls[lca2]];
  int mid=(l+r)>>1;
  if (suma-sumb>=k)
    return query(ls[ql],ls[qr],ls[lca],ls[lca2],k,l,mid);
  else
    return query(rs[ql],rs[qr],rs[lca],rs[lca2],k-suma+sumb,mid+1,r);
}

int main()
{
  freopen("10628.in","r",stdin);
  freopen("10628.out","w",stdout);
  int ca,i,j,qus,k,m,ii=0;
  int lastans=0;
  scanf("%d%d",&n,&qus);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b+1,b+n+1);
  sz=unique(b+1,b+n+1)-b-1;
  for (i=1;i<=n-1;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  build(root[0],1,sz);
  dep[0]=0;
  dfs(1,0);
  bz();
  while(qus--)
  {
    int ql,qr;
    scanf("%d%d%d",&ql,&qr,&k);
    ql^=lastans;
    int lca=get_lca(ql,qr);
    lastans=b[query(root[ql],root[qr],root[lca],root[fa[lca][0]],k,1,sz)];
    if (qus!=0)
	  printf("%d\n",lastans);
	else
	  printf("%d",lastans);
  }
  return 0;
}

