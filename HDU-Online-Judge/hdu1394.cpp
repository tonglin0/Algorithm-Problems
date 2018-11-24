#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define MN 20004
using namespace std;
int qr,ql;
int s[MN];
int a[MN];
int anss[MN];
/*
void build(int p,int l,int r)
{
  if (l==r)
  {
    scanf("%d",&a[p]);
    return;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1+1,mid+1,r);
}*/

void update(int p,int l,int r,int q)
{
  if(l==q&&r==q)
  {
    s[p]=1;
    return ;
  }
  int mid=(r+l)>>1;
  if (q<=mid)
    update(p<<1,l,mid,q);
  else
    update(p<<1|1,mid+1,r,q);
  s[p]=s[p<<1]+s[p<<1|1];
}

int query(int p,int l,int r,int ql,int qr)
{
  if (ql<=l&&qr>=r)
    return s[p];
  int mid=(l+r)>>1;
  int ans=0;
  if (ql<=mid)
    ans+=query(p<<1,l,mid,ql,qr);
  if (qr>mid)
    ans+=query(p<<1|1,mid+1,r,ql,qr);
  return ans;
}

int main()
{
  freopen("1394.in","r",stdin);
  freopen("1394.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    memset(anss,0,sizeof(anss));
    memset(s,0,sizeof(s));
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      update(1,0,n,a[i]);
      if (a[i]==n)
        anss[i]=0;
      else
        anss[i]=query(1,0,n,a[i]+1,n);
    }
    int ans=0;
    for (i=1;i<=n;i++)
      ans+=anss[i];
    int minans=ans;
    for(i=1;i<=n-1;i++)
    {
      ans=ans-(a[i])+n-a[i]-1;
      minans=min(minans,ans);
    }
    printf("%d\n",minans);
  }
  return 0;
}
