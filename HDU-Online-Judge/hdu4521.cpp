#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 400011
using namespace std;

int ms[MN];
int f[MN];
int a[MN];
int ql,qr;

void pushup(int p,int l,int r)
{
  ms[p]=max(ms[p<<1],ms[p<<1|1]);
}

void build(int p,int l,int r)
{
  if (l==r)
  {
    ms[p]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  pushup(p,l,r);
}

void update(int p,int l,int r,int q,int k)
{
  if (l==r)
  {
    ms[p]=max(ms[p],k);
    return ;
  }
  int mid=(l+r)>>1;
  if (q<=mid)
    update(p<<1,l,mid,q,k);
  else
    update(p<<1|1,mid+1,r,q,k);
  pushup(p,l,r);
}

int query(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return ms[p];
  int mid=(l+r)>>1;
  int ans=0;
  if (ql<=mid)
    ans=max(ans,query(p<<1,l,mid));
  if (qr>mid)
    ans=max(ans,query(p<<1|1,mid+1,r));
  return ans;
}

int main()
{
  freopen("4521.in","r",stdin);
  freopen("4521.out","w",stdout);
  int d,n,i,j,k,m;
  while(scanf("%d%d",&n,&d)==2)
  {
    for (i=1;i<=n;i++)
    {
	  scanf("%d",&a[i]);
	  a[i]++;
	}
    build(1,0,100002);
    int ans=1;
    ql=0;
    for (i=1;i<=n;i++)
    {
	  qr=a[i]-1;
      f[i]=query(1,0,100002)+1;
      ans=max(ans,f[i]);
      if (i-d>0)
        update(1,0,100002,a[i-d],f[i-d]);
	}
	printf("%d\n",ans);
  }
  return 0;
}
