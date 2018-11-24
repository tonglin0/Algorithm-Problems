#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MN 801000
using namespace std;

int set[MN],l1[MN],l0[MN],a1[MN],a0[MN],b1[MN],b0[MN],sum1[MN],sum0[MN],x[MN];
int ql,qr;

void setall0(int p,int l,int r)
{
  l0[p]=a0[p]=b0[p]=sum0[p]=r-l+1;
  l1[p]=a1[p]=b1[p]=sum1[p]=0;
  x[p]=0;set[p]=0;
}

void setall1(int p,int l,int r)
{
  l1[p]=a1[p]=b1[p]=sum1[p]=r-l+1;
  l0[p]=a0[p]=b0[p]=sum0[p]=0;
  x[p]=0;set[p]=1;
}

void swapall(int p,int l,int r)
{
  swap(sum1[p],sum0[p]);
  swap(l1[p],l0[p]);
  swap(a1[p],a0[p]);
  swap(b1[p],b0[p]);
}

void pushup(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  int mid=(l+r)>>1;
  sum1[p]=sum1[lc]+sum1[rc];
  sum0[p]=sum0[lc]+sum0[rc];
  l1[p]=max(l1[lc],l1[rc]);
  l1[p]=max(l1[p],b1[lc]+a1[rc]);
  l0[p]=max(l0[lc],l0[rc]);
  l0[p]=max(l0[p],b0[lc]+a0[rc]);
  a1[p]=a1[lc];
  if (a1[lc]==mid-l+1) 
    a1[p]+=a1[rc];
  a0[p]=a0[lc];
  if (a0[lc]==mid-l+1)
    a0[p]+=a0[rc];
  b1[p]=b1[rc];
  if (b1[rc]==r-mid)
    b1[p]+=b1[lc];
  b0[p]=b0[rc];
  if (b0[rc]==r-mid)
    b0[p]+=b0[lc];
}

void pushdown(int p,int l,int r)
{
  int mid=(l+r)>>1;
  int lc=p<<1,rc=p<<1|1;
  if (set[p]>=0)
  {
    if (set[p]==0)
    {
      set[lc]=0;
      set[rc]=0;
      setall0(lc,l,mid);
      setall0(rc,mid+1,r);
    }
    else
    {
      set[lc]=1;
      set[rc]=1;
      setall1(lc,l,mid);
      setall1(rc,mid+1,r);
    }
    set[p]=-1;
  }
  if (x[p])
  {
    if (set[lc]>=0)
    {
      set[lc]=!set[lc];
      if (set[lc]==0)
        setall0(lc,l,mid);
      else
        setall1(lc,l,mid);  
    }
    else
    {
      x[lc]^=x[p];
      swapall(lc,l,mid);
    }
    if (set[rc]>=0)
    {
      set[rc]=!set[rc];
      if (set[rc]==0)
        setall0(rc,mid+1,r);
      else
        setall1(rc,mid+1,r);
    }
    else
    {
      x[rc]^=x[p];
      swapall(rc,mid+1,r);
    }
    x[p]=0;
  }
}

void build(int p,int l,int r)
{
  if (l==r)
  {
    int t;
    scanf("%d",&t);
    if (t==0)
      setall0(p,l,r);
    else
      setall1(p,l,r);
    set[p]=-1;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  pushup(p,l,r);
  set[p]=-1;
  x[p]=0;
}

void setupdate(int p,int l,int r,int k)
{
  if (ql<=l&&qr>=r)
  {
    x[p]=0;
    set[p]=k;
    if (k==1)
      setall1(p,l,r);
    else
      setall0(p,l,r);
    return ;
  }
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  if (ql<=mid)
    setupdate(p<<1,l,mid,k);
  if (qr>mid)
    setupdate(p<<1|1,mid+1,r,k);
  pushup(p,l,r);
}

void xorupdate(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
  {
    if (set[p]>=0)
    {
      set[p]=!set[p];
      if (set[p]==0)
        setall0(p,l,r);
      else 
        setall1(p,l,r);
    }
    else
    {
      x[p]^=1;
      swapall(p,l,r);
    }
    return ;
  }
  pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (ql<=mid)
    xorupdate(p<<1,l,mid);
  if (qr>mid)
    xorupdate(p<<1|1,mid+1,r);
  pushup(p,l,r);
}

int querysum(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return sum1[p];
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  int ans=0;
  if (ql<=mid)
    ans=querysum(p<<1,l,mid);
  if (qr>mid)
    ans+=querysum(p<<1|1,mid+1,r);
  pushup(p,l,r);
  return ans;
}

int querylen(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return l1[p];
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  int ans=0;
  if (ql<=mid)
    ans=querylen(p<<1,l,mid);
  if (qr>mid)
    ans=max(ans,querylen(p<<1|1,mid+1,r));
  ans=max(ans,min(b1[p<<1],mid-ql+1)+min(a1[p<<1|1],qr-mid));
  pushup(p,l,r);
  return ans;
}

int main()
{
  freopen("1858.in","r",stdin);
  freopen("1858.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  build(1,0,n-1);
  int op;
  for (i=1;i<=m;i++)
  {
    scanf("%d%d%d",&op,&ql,&qr);
    if (op==0)
      setupdate(1,0,n-1,0);
    else if (op==1)
      setupdate(1,0,n-1,1);
    else if (op==2)
      xorupdate(1,0,n-1);
    else if (op==3)
      printf("%d\n",querysum(1,0,n-1));
    else
      printf("%d\n",querylen(1,0,n-1));
  }
  return 0;
}
