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

int sum[MN*20],ls[MN*20],rs[MN*20];
int a[MN],b[MN];
int root[MN];
int tot;

int build(int l,int r)
{
  int k=++tot;
  sum[k]=0;
  if (l==r)
    return k;
  int mid=(l+r)>>1;
  ls[k]=build(l,mid);
  rs[k]=build(mid+1,r);
  return k;
}

int change(int o,int p,int l,int r)
{
  int k=++tot;
  ls[k]=ls[o];rs[k]=rs[o];sum[k]=sum[o];
  sum[k]++;
  if (l==r)
    return k;
  int mid=(l+r)>>1;
  if (p<=mid)
    ls[k]=change(ls[o],p,l,mid);
  else
    rs[k]=change(rs[o],p,mid+1,r);
  return k;
}

int query(int a,int b,int k,int l,int r)
{
  if (l==r)
    return l;
  int res=sum[ls[b]]-sum[ls[a]];
  int mid=(l+r)>>1;
  if (k<=res)
    return query(ls[a],ls[b],k,l,mid);
  else
    return query(rs[a],rs[b],k-res,mid+1,r);
}

int main()
{
  freopen("2665.in","r",stdin);
  freopen("2665.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d",&ca);
  while(ca--)
  {
    tot=0;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for (j=1,i=2;i<=n;i++)
	  if (b[j]!=b[i])
	    b[++j]=b[i];
	root[0]=build(1,j);
	for (i=1;i<=n;i++)
	{
	  int p=lower_bound(b+1,b+j+1,a[i])-b;
	  root[i]=change(root[i-1],p,1,j);
	}
	while(m--)
	{
	  int qa,qb;
	  scanf("%d%d%d",&qa,&qb,&k);
	  printf("%d\n",b[query(root[qa-1],root[qb],k,1,j)]);
	}
  }
  return 0;
}

