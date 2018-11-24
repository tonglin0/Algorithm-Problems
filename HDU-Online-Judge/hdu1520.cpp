#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int p[6009];
int f[6009][2];
int fa[6009];
struct node{
	int id,l,r;
};
node tr[6009];
int lc[6009];
int root;
bool vis[6009][2];

int find(int u,int sig)
{
  if (vis[u][sig])
    return f[u][sig];
  vis[u][sig]=true;
  if (sig==0)
  {
    if (tr[u].l==0&&tr[u].r==0)
      return f[u][sig]=0;
    if (tr[u].l==0)
      return f[u][sig]=find(tr[u].r,0);
    if (tr[u].r==0)
      return f[u][sig]=find(tr[u].l,1);
    return f[u][sig]=find(tr[u].l,1)+find(tr[u].r,0);
  }
  else
  {
    if (tr[u].l==0&&tr[u].r==0)
      return f[u][sig]=max(0,p[u]);
    if (tr[u].l==0)
      return f[u][sig]=find(tr[u].r,1)+max(0,p[u]);
    if (tr[u].r==0)
      return f[u][sig]=max(find(tr[u].l,0)+p[u],find(tr[u].l,1));
    return f[u][sig]=find(tr[u].r,1)+max(find(tr[u].l,1),find(tr[u].l,0)+p[u]);
  }
}

int main()
{
  freopen("1520.in","r",stdin);
  freopen("1520.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&p[i]);
    int u,v;
    memset(tr,0,sizeof(tr));
    memset(fa,0,sizeof(fa));
    while(scanf("%d%d",&u,&v)==2)
    {
      if (u==0&&v==0)
        break;
      fa[u]=v;
      if (tr[v].l==0)
      {
        tr[v].l=u;
        lc[v]=u;
	  }
	  else
	  {
	    tr[lc[v]].r=u;
	    lc[v]=u;                 //一开始没有写这一行
	  }
	}
	for (i=1;i<=n;i++)
	  if (fa[i]==0)
	  {
	    root=i;
	    break;
	  }
	p[0]=0; 
	memset(vis,0,sizeof(vis));
	printf("%d\n",max(find(root,0),find(root,1)));
  }
  return 0;
}
