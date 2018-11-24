#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 400006
using namespace std;

int s[MN];
int set[MN];
int sl,sr;

void build(int p,int l,int r)
{
  if (l==r)
  {
    s[p]=1;
    set[p]=-1;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=s[p<<1]+s[p<<1|1];
  set[p]=-1;
}

void pushdown(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  int mid=(l+r)>>1;
  set[lc]=set[rc]=set[p];
  s[lc]=(mid-l+1)*set[lc];
  s[rc]=(r-mid)*set[rc];
  set[p]=-1;
}

void update(int p,int l,int r,int k)
{
  if (l==r)
  {
    set[p]=k;
    s[p]=k;
    return ;
  }
  int mid=(l+r)>>1;
  if (sl<=l&&sr>=r)
  {
    set[p]=k;
    s[p]=(r-l+1)*k;
    return ;
  }
  if (set[p]!=-1)
    pushdown(p,l,r);
  if (sl<=mid)
    update(p<<1,l,mid,k);
  if (sr>mid)
    update(p<<1|1,mid+1,r,k);
  s[p]=s[p<<1]+s[p<<1|1];
}

int main()
{
  freopen("1698.in","r",stdin);
  freopen("1698.out","w",stdout);
  int T,ii,n,i,j,k,m;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&sl,&sr,&k);
      update(1,1,n,k);
    }
    printf("Case %d: The total value of the hook is %d.\n",ii,s[1]);
  }
  return 0;
}
