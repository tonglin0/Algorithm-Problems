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

struct node{
	int l,r,rs,ls,sum;
};
node t[MN*20];
int a[MN],b[MN];
int root[MN];
int tot=0;

int build(int l,int r)
{
  int k=++tot;
  t[k].l=l;t[k].r=r;t[k].sum=0;
  if (l==r)
    return k;
  int mid=(l+r)>>1;
  t[k].ls=build(l,mid);
  t[k].rs=build(mid+1,r);
  return k;
}

int change(int o,int p)
{
  int k=++tot;
  t[k]=t[o];
  t[k].sum++;
  if (t[k].l==p&&t[k].r==p)
    return k;
  int mid=(t[k].l+t[k].r)>>1;
  if (p<=mid)
    t[k].ls=change(t[o].ls,p);
  else
    t[k].rs=change(t[o].rs,p);
  return k;
}

int query(int l,int r,int k)
{
  if (t[l].l==t[l].r)
    return t[l].l;
  int cnt=t[t[r].ls].sum-t[t[l].ls].sum;
  if (cnt>=k)
    return query(t[l].ls,t[r].ls,k);
  else
    return query(t[l].rs,t[r].rs,k-cnt);
}

int main()
{
  freopen("2104.in","r",stdin);
  freopen("2104.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b+1,b+n+1);
  for (j=1,i=2;i<=n;i++)
    if (b[i]!=b[j])
      b[++j]=b[i];
  root[0]=build(1,j);
  for (i=1;i<=n;i++)
  {
    int p=lower_bound(b+1,b+j+1,a[i])-b;
    root[i]=change(root[i-1],p);
  }
  while(m--)
  {
    int ql,qr;
    scanf("%d%d%d",&ql,&qr,&k);
    printf("%d\n",b[query(root[ql-1],root[qr],k)]);
  }
  return 0;
}

