#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 800006
using namespace std;

int s[MN];
int f[MN],v[MN];
int ans[MN];

void build(int p,int l,int r)
{
  if (l==r)
  {
    s[p]=1;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=s[p<<1]+s[p<<1|1];
}

int query(int p,int l,int r,int k)
{
  if (r==l)
  {
    s[p]--;
    return l;
  }
  int t,mid=(l+r)>>1;
  if (k<=s[p<<1])
  {
    t=query(p<<1,l,mid,k);
    s[p]=s[p<<1]+s[p<<1|1];
    return t;
  }
  else
  {
    k-=s[p<<1];
    t=query(p<<1|1,mid+1,r,k);
    s[p]=s[p<<1]+s[p<<1|1];
    return t;
  }
}

int main()
{
  freopen("2828.in","r",stdin);
  freopen("2828.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    build(1,1,n);
    memset(ans,0,sizeof(ans));
    for (i=1;i<=n;i++)
      scanf("%d%d",&f[i],&v[i]);
    for (i=n;i>=1;i--)
    {
      k=query(1,1,n,f[i]+1);
      ans[k]=v[i];
    }
    for (i=1;i<=n;i++)
      printf("%d ",ans[i]);
    printf("\n");
  }
  return 0;
}
