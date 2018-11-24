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
#define MN 100009
using namespace std;

int q[MN][4];
int a[MN],b[MN<<1];
int root[MN],sum[MN*30],ls[MN*30],rs[MN*30];
int tot;

void pushup(int p,int l,int r)
{
  sum[p]=sum[ls[p]]+sum[rs[p]];
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

void update(int &k,int o,int l,int r,int p)
{
  k=++tot;
  sum[k]=sum[o];ls[k]=ls[o];rs[k]=rs[o];
  if (l==r)
  {
    sum[k]++;
    return ;
  }
  int mid=(l+r)>>1;
  if (p<=mid)
    update(ls[k],ls[o],l,mid,p);
  else
    update(rs[k],rs[o],mid+1,r,p);
  pushup(k,l,r);
}

int query(int ql,int qr,int l,int r,int p)
{
  if (l==r)
    return sum[qr]-sum[ql];
  int mid=(l+r)>>1;
  if (p>mid)
    return sum[ls[qr]]-sum[ls[ql]]+query(rs[ql],rs[qr],mid+1,r,p);
  else
    return query(ls[ql],ls[qr],l,mid,p);
}

int main()
{
  freopen("4417.in","r",stdin);
  freopen("4417.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
  	tot=0;
    printf("Case %d:\n",ii);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      b[i]=a[i];
    }
    int tmpn=n;
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&q[i][1],&q[i][2],&q[i][3]);
      q[i][1]++;q[i][2]++;
      b[++n]=q[i][3];
	}
    sort(b+1,b+n+1);
    int cnt=unique(b+1,b+n+1)-b-1;
    build(root[0],1,cnt);
    for (i=1;i<=tmpn;i++)
    {
      int p=lower_bound(b+1,b+cnt+1,a[i])-b;
      update(root[i],root[i-1],1,cnt,p);
	}
	for (i=1;i<=m;i++)
	{
	  int p=lower_bound(b+1,b+cnt+1,q[i][3])-b;
	  printf("%d\n",query(root[q[i][1]-1],root[q[i][2]],1,cnt,p));
	}
  }
  return 0;
}

