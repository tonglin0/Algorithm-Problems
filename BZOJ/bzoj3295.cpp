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
#define MN 100009
using namespace std;

int n;
int a[MN];
int po[MN];
int a1[MN],a2[MN];
int c[MN];
int root[MN];
int sum[5000005],ls[5000005],rs[5000005];
int tot=0;
int N,M;
int A[MN],B[MN];

int lowbit(int x){return x&(-x);}

int getans(int x)
{
  int ans=0;
  int i=x;
  while(i>0)
  {
    ans+=c[i];
    i-=lowbit(i);
  }
  return ans;
}

void modify(int x,int d)
{
  int i=x;
  while(i<=n)
  {
    c[i]+=d;
    i+=lowbit(i);
  }
}

void chair_update(int &k,int p,int l,int r,int d)
{
  if (!k)
    k=++tot;
  sum[k]++;
  if (l==r)
    return ;
  int mid=(l+r)>>1;
  if (p<=mid)
    chair_update(ls[k],p,l,mid,d);
  else
    chair_update(rs[k],p,mid+1,r,d);
}

void bit_update(int x,int p,int d)
{
  for (int i=x;i<=n;i+=lowbit(i))
    chair_update(root[i],p,1,n,d);
}

int chair_large(int l,int r,int p)
{
  if (l==r)
    return 0;
  int mid=(l+r)>>1;
  if (p<=mid)
  {
    lint ans=0;
    for (int i=1;i<=M;i++)
      ans+=(lint)sum[rs[B[i]]];
    for (int i=1;i<=N;i++)
      ans-=(lint)sum[rs[A[i]]];
    for (int i=1;i<=M;i++)
      B[i]=ls[B[i]];
    for (int i=1;i<=N;i++)
      A[i]=ls[A[i]];
    return ans+chair_large(l,mid,p);
  }
  else
  {
    for (int i=1;i<=N;i++)
      A[i]=rs[A[i]];
    for (int i=1;i<=M;i++)
      B[i]=rs[B[i]];
    return chair_large(mid+1,r,p);
  }
}

int query_large(int l,int r,int x)
{
  l--;
  N=M=0;
  for (int i=l;i>0;i-=lowbit(i))
    A[++N]=root[i];
  for (int i=r;i>0;i-=lowbit(i))
    B[++M]=root[i];
  return chair_large(1,n,x);
}

int chair_small(int l,int r,int x)
{
  if (l==r)
    return 0;
  lint ans=0;
  int mid=(l+r)>>1;
  if (x<=mid)
  {
    for (int i=1;i<=N;i++)
      A[i]=ls[A[i]];
    for (int i=1;i<=M;i++)
      B[i]=ls[B[i]];
    return chair_small(l,mid,x);
  }
  else
  {
    for (int i=1;i<=N;i++)
    {
      ans-=sum[ls[A[i]]];
      A[i]=rs[A[i]];
	}
	for (int i=1;i<=M;i++)
	{
	  ans+=sum[ls[B[i]]];
	  B[i]=rs[B[i]];
	}
	return ans+chair_small(mid+1,r,x);
  }
}

int query_small(int l,int r,int x)
{
  int i;
  N=M=0;
  l--;
  for (i=l;i>0;i-=lowbit(i))
    A[++N]=root[i];
  for (i=r;i>0;i-=lowbit(i))
    B[++M]=root[i];
  return chair_small(1,n,x);
}

int main()
{
  freopen("3295.in","r",stdin);
  freopen("3295.out","w",stdout);
  int ca,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  lint ans=0;
  memset(c,0,sizeof(c));
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    po[a[i]]=i;
    a1[i]=i-1-getans(a[i]);
    modify(a[i],1);
    ans+=(lint)a1[i];
  }
  memset(c,0,sizeof(c));
  for (i=n;i>=1;i--)
  {
    a2[i]=getans(a[i]-1);
    modify(a[i],1);
  }
  for (i=1;i<=m;i++)
  {
    int x;
    scanf("%d",&x);
    printf("%lld\n",ans);
	//cout<<ans<<endl;
	ans-=(lint)(a1[po[x]]+a2[po[x]]-query_large(1,po[x]-1,x)-query_small(po[x]+1,n,x));
	bit_update(po[x],x,1);
  }
  return 0;
}

