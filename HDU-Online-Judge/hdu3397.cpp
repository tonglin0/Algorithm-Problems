#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MN 410010
using namespace std;

int ql,qr;
int s1[MN],l1[MN],s0[MN],l0[MN],l1l[MN],l1r[MN],l0l[MN],l0r[MN];
int set[MN],x[MN];

void changeall(int p,int l,int r,int k)
{
  if (k==0)
  {
    s0[p]=l0[p]=l0l[p]=l0r[p]=r-l+1;
    s1[p]=l1[p]=l1l[p]=l1r[p]=0;
  }
  else
  {
    s0[p]=l0[p]=l0l[p]=l0r[p]=0;
    s1[p]=l1[p]=l1l[p]=l1r[p]=r-l+1;
  }
}

void swapall(int p,int l,int r)
{
  swap(s1[p],s0[p]);
  swap(l1[p],l0[p]);
  swap(l1l[p],l0l[p]);
  swap(l1r[p],l0r[p]);
}

void build(int p,int l,int r)
{
  if (l==r)
  {
    int d;
    scanf("%d",&d);
    if (d==1)
    {
      s1[p]=l1[p]=l1l[p]=l1r[p]=1;
      s0[p]=l0[p]=l0l[p]=l0r[p]=0;
      set[p]=-1;
      x[p]=0;
    }
    else
    {
      s1[p]=l1[p]=l1l[p]=l1r[p]=0;
      s0[p]=l0[p]=l0l[p]=l0r[p]=1;
      set[p]=-1;
      x[p]=0;
    }
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  int lc=p<<1,rc=p<<1|1;
  s1[p]=s1[lc]+s1[rc];
  s0[p]=s0[lc]+s0[rc];
  l1[p]=max(l1[lc],l1[rc]);
  if (l1r[lc]>0&&l1l[rc]>0)
    l1[p]=max(l1[p],l1r[lc]+l1l[rc]);
  l0[p]=max(l0[lc],l0[rc]);
  if (l0r[lc]>0&&l0l[rc]>0)
    l0[p]=max(l0[p],l0r[lc]+l0l[rc]);
  l1l[p]=l1l[lc];
  if (l1l[lc]==mid-l+1)
    l1l[p]+=l1l[rc];
  l0l[p]=l0l[lc];
  if (l0l[lc]==mid-l+1)
    l0l[p]+=l0l[rc];
  l1r[p]=l1r[rc];
  if (l1r[rc]==r-mid)
    l1r[p]+=l1r[lc];
  l0r[p]=l0r[rc];
  if (l0r[rc]==r-mid)
    l0r[p]+=l0r[lc];
  set[p]=-1;
  x[p]=0;
}

void pushdown(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  int mid=(l+r)>>1;
  if (set[p]>=0)
  {
    set[lc]=set[rc]=set[p];
    if (set[p]==0)
    {
      changeall(lc,l,mid,0);
      changeall(rc,mid+1,r,0);
      x[lc]=0;x[rc]=0;
    }
    else
    {
      changeall(lc,l,mid,1);
      changeall(rc,mid+1,r,1);
      x[lc]=0;x[rc]=0;
    }
    set[p]=-1;
    x[p]=0;
  }
  else if (x[p]>0)
  {
    swapall(lc,l,mid);
    swapall(rc,mid+1,r);
    if (set[lc]>=0)
      set[lc]=1-set[lc];
    else
      x[lc]^=1;
    if (set[rc]>=0)
      set[rc]=1-set[rc];
    else
      x[rc]^=1;
    x[p]=0;
    set[p]=-1;
  }
}

void update(int p,int l,int r,int k)
{
  if (ql<=l&&qr>=r)
  {
    set[p]=k;
    x[p]=0;
    if (k==0)
    {
      s0[p]=l0[p]=l0l[p]=l0r[p]=r-l+1;
      s1[p]=l1[p]=l1l[p]=l1r[p]=0;
    }
    else
    {
      s0[p]=l0[p]=l0l[p]=l0r[p]=0;
      s1[p]=l1[p]=l1l[p]=l1r[p]=r-l+1;
    }
    return ;
  }
  pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(p<<1,l,mid,k);
  if (qr>mid)
    update(p<<1|1,mid+1,r,k);  // copied "build()" from now on
  int lc=p<<1,rc=p<<1|1;
  s1[p]=s1[lc]+s1[rc];
  s0[p]=s0[lc]+s0[rc];
  l1[p]=max(l1[lc],l1[rc]);
  if (l1r[lc]>0&&l1l[rc]>0)
    l1[p]=max(l1[p],l1r[lc]+l1l[rc]);
  l0[p]=max(l0[lc],l0[rc]);
  if (l0r[lc]>0&&l0l[rc]>0)
    l0[p]=max(l0[p],l0r[lc]+l0l[rc]);
  l1l[p]=l1l[lc];
  if (l1l[lc]==mid-l+1)
    l1l[p]+=l1l[rc];
  l0l[p]=l0l[lc];
  if (l0l[lc]==mid-l+1)
    l0l[p]+=l0l[rc];
  l1r[p]=l1r[rc];
  if (l1r[rc]==r-mid)
    l1r[p]+=l1r[lc];
  l0r[p]=l0r[rc];
  if (l0r[rc]==r-mid)
    l0r[p]+=l0r[lc];
  set[p]=-1;
  x[p]=0;
}

void xorupdate(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
  {
    swapall(p,l,r);
    if (set[p]>=0)
      set[p]=1-set[p];
    else
      x[p]^=1;
    return ;
  }
  pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (ql<=mid)
    xorupdate(p<<1,l,mid);
  if (qr>mid)
    xorupdate(p<<1|1,mid+1,r);
  int lc=p<<1,rc=p<<1|1;  // copied from now on
  s1[p]=s1[lc]+s1[rc];
  s0[p]=s0[lc]+s0[rc];
  l1[p]=max(l1[lc],l1[rc]);
  if (l1r[lc]>0&&l1l[rc]>0)
    l1[p]=max(l1[p],l1r[lc]+l1l[rc]);
  l0[p]=max(l0[lc],l0[rc]);
  if (l0r[lc]>0&&l0l[rc]>0)
    l0[p]=max(l0[p],l0r[lc]+l0l[rc]);
  l1l[p]=l1l[lc];
  if (l1l[lc]==mid-l+1)
    l1l[p]+=l1l[rc];
  l0l[p]=l0l[lc];
  if (l0l[lc]==mid-l+1)
    l0l[p]+=l0l[rc];
  l1r[p]=l1r[rc];
  if (l1r[rc]==r-mid)
    l1r[p]+=l1r[lc];
  l0r[p]=l0r[rc];
  if (l0r[rc]==r-mid)
    l0r[p]+=l0r[lc];
}

int querysum(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return s1[p];
  pushdown(p,l,r);
  int ans=0;
  int mid=(l+r)>>1;
  if (ql<=mid)
    ans=querysum(p<<1,l,mid);
  if (qr>mid)
    ans+=querysum(p<<1|1,mid+1,r);
  int lc=p<<1,rc=p<<1|1;  // copied from now on
  s1[p]=s1[lc]+s1[rc];
  s0[p]=s0[lc]+s0[rc];
  l1[p]=max(l1[lc],l1[rc]);
  if (l1r[lc]>0&&l1l[rc]>0)
    l1[p]=max(l1[p],l1r[lc]+l1l[rc]);
  l0[p]=max(l0[lc],l0[rc]);
  if (l0r[lc]>0&&l0l[rc]>0)
    l0[p]=max(l0[p],l0r[lc]+l0l[rc]);
  l1l[p]=l1l[lc];
  if (l1l[lc]==mid-l+1)
    l1l[p]+=l1l[rc];
  l0l[p]=l0l[lc];
  if (l0l[lc]==mid-l+1)
    l0l[p]+=l0l[rc];
  l1r[p]=l1r[rc];
  if (l1r[rc]==r-mid)
    l1r[p]+=l1r[lc];
  l0r[p]=l0r[rc];
  if (l0r[rc]==r-mid)
    l0r[p]+=l0r[lc];
  return ans;
}

int querylen(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return l1[p];
  int ans=0;
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  if (ql<=mid)
    ans=querylen(p<<1,l,mid);
  if (qr>mid)
    ans=max(ans,querylen(p<<1|1,mid+1,r));
  int lc=p<<1,rc=p<<1|1;
  ans=max(ans,min(l1r[lc],mid-ql+1)+min(l1l[rc],qr-mid));  // copied from now on
  s1[p]=s1[lc]+s1[rc];
  s0[p]=s0[lc]+s0[rc];
  l1[p]=max(l1[lc],l1[rc]);
  if (l1r[lc]>0&&l1l[rc]>0)
    l1[p]=max(l1[p],l1r[lc]+l1l[rc]);
  l0[p]=max(l0[lc],l0[rc]);
  if (l0r[lc]>0&&l0l[rc]>0)
    l0[p]=max(l0[p],l0r[lc]+l0l[rc]);
  l1l[p]=l1l[lc];
  if (l1l[lc]==mid-l+1)
    l1l[p]+=l1l[rc];
  l0l[p]=l0l[lc];
  if (l0l[lc]==mid-l+1)
    l0l[p]+=l0l[rc];
  l1r[p]=l1r[rc];
  if (l1r[rc]==r-mid)
    l1r[p]+=l1r[lc];
  l0r[p]=l0r[rc];
  if (l0r[rc]==r-mid)
    l0r[p]+=l0r[lc];
  return ans;
}

int main()
{
  freopen("3397.in","r",stdin);
  freopen("3397.out","w",stdout);
  int T,i,j,k,m,n;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    build(1,0,n-1);
    //printf("%d\n",l1[5]);         mostly no BUG in build()
    while(m--)
    {
      scanf("%d%d%d",&k,&ql,&qr);
      if (k==0)
        update(1,0,n-1,0);
      else if (k==1)
        update(1,0,n-1,1);
      else if (k==2)
        xorupdate(1,0,n-1);
      else if (k==3)
        printf("%d\n",querysum(1,0,n-1));
      else 
        printf("%d\n",querylen(1,0,n-1));
    }
    //printf("%d\n",s0[1]);
  }
  return 0;
}
