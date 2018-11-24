#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 842006
using namespace std;

int mc[MN];

void build(int p,int l,int r,int k)
{
  if (l==r)
  {
    mc[p]=k;
    return;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid,k);
  build(p<<1|1,mid+1,r,k);
  mc[p]=max(mc[p<<1],mc[p<<1|1]);
}

int query(int p,int l,int r,int q)
{
  if (mc[p]<q) return -1;
  if (l==r)
  {
    mc[p]-=q;
    return l;
  }
  int mid=(l+r)>>1;
  int t;
  if (mc[p<<1]>=q)
    {t=query(p<<1,l,mid,q);mc[p]=max(mc[p<<1],mc[p<<1|1]);return t;}
  else if (mc[p<<1|1]>=q)
    {t=query(p<<1|1,mid+1,r,q);mc[p]=max(mc[p<<1],mc[p<<1|1]);return t;}
  else 
    return -1;
}

int main()
{
  freopen("2795.in","r",stdin);
  freopen("2795.out","w",stdout);
  int n,i,j,k,m,h,w;
  while(scanf("%d%d%d",&n,&w,&m)==3)
  {
    memset(mc,0,sizeof(mc));
    if (n>m) n=m;
    build(1,1,n,w);
    for (i=1;i<=m;i++)
    {
      scanf("%d",&k);
      if (k>w) printf("-1\n");
        else
          printf("%d\n",query(1,1,n,k));
    }
  }
  return 0;
}
