#include<cstdio>
#include<iostream>
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
#define MN 200001
using namespace std;

int sum[MN*30],ls[MN*30],rs[MN*30];
int a[MN],b[MN];
int tot=0;
int root[MN];

void pushup(int p,int l,int r)
{
  sum[p]=sum[ls[p]]+sum[rs[p]];
}

void build(int &k,int l,int r)
{
  k=++tot;
  if (l==r)
  {
    sum[k]=ls[k]=rs[k]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(ls[k],l,mid);
  build(rs[k],mid+1,r);
  pushup(k,l,r);
}

void update(int &k,int o,int l,int r,int p)
{
  k=++tot;
  sum[k]=sum[o]+1;ls[k]=ls[o];rs[k]=rs[o];
  if (l==r)
    return ;
  int mid=(l+r)>>1;
  if (p<=mid)
    update(ls[k],ls[o],l,mid,p);
  else
    update(rs[k],rs[o],mid+1,r,p);
}

int query(int ql,int qr,int l,int r,int k)
{
  if (l==r)
    return l;
  int cnt=sum[ls[qr]]-sum[ls[ql]];
  int mid=(l+r)>>1;
  if (cnt>=k)
    return query(ls[ql],ls[qr],l,mid,k);
  else
    return query(rs[ql],rs[qr],mid+1,r,k-cnt);
}

int main()
{
  freopen("2761.in","r",stdin);
  freopen("2761.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b+1,b+n+1);
  int cnt=unique(b+1,b+n+1)-b-1;
  build(root[0],1,cnt);
  for (i=1;i<=n;i++)
  {
    int p=lower_bound(b+1,b+cnt+1,a[i])-b;
    update(root[i],root[i-1],1,cnt,p);
  }
  for (i=1;i<=m;i++)
  {
    int l,r;
    scanf("%d%d%d",&l,&r,&k);
    printf("%d\n",b[query(root[l-1],root[r],1,cnt,k)]);
  }
  return 0;
}


