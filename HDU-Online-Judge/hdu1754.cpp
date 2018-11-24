#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define MN 800004
using namespace std;

int sc[MN];
int mc[MN];
int ql,qr;
char ch[4];

void build(int p,int l,int r)
{
  if (l==r)
  {
    scanf("%d",&sc[p]);
    mc[p]=sc[p];
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  mc[p]=max(mc[p<<1],mc[p<<1|1]);
}

int query(int p,int l,int r)
{
  if (ql<=l&&qr>=r) return mc[p];
  int mid=(l+r)>>1;
  int ans=0;
  if (ql<=mid)
    ans=max(ans,query(p<<1,l,mid));
  if (qr>mid)
    ans=max(ans,query(p<<1|1,mid+1,r));
  return ans;
}

void update(int p,int l,int r,int q,int d)
{
  if (l==q&&r==q)
  {
    sc[p]=d;
    mc[p]=d;
    return ;
  }
  int mid=(l+r)>>1;
  if (q<=mid)
    update(p<<1,l,mid,q,d);
  else
    update(p<<1|1,mid+1,r,q,d);
  mc[p]=max(mc[p<<1],mc[p<<1|1]);
}

int main()
{
  freopen("1754.in","r",stdin);
  freopen("1754.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    build(1,1,n);
    for (i=1;i<=m;i++)
    {
      scanf("%s",ch);
      if (ch[0]=='Q')
      {
        scanf("%d%d",&ql,&qr);
        printf("%d\n",query(1,1,n));
      }
      else
      {
        scanf("%d%d",&k,&j);
        update(1,1,n,k,j);
      }
    }
  }
  return 0;
}
