#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 1200020
#define LL long long
using namespace std;

LL s[MN];
LL add[MN];
int ql,qr,al,ar;
char ch[4];

void build(int p,int l,int r)
{
  if (l==r)
  {
    add[p]=0;
    scanf("%I64d",&s[p]);
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=s[p<<1]+s[p<<1|1];
  add[p]=0;
}

void pushdown(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  int mid=(l+r)>>1;
  add[lc]+=add[p];
  add[rc]+=add[p];
  s[lc]+=(LL)(mid-l+1)*add[p];
  s[rc]+=(LL)(r-mid)*add[p];
  add[p]=0;
}

void update(int p,int l,int r,int k)
{
  if (al<=l&&ar>=r)
  {
    s[p]+=(LL)(r-l+1)*(LL)k;
    add[p]+=k;
    return ;
  }
  if (add[p])
    pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (al<=mid)
    update(p<<1,l,mid,k);
  if (ar>mid)
    update(p<<1|1,mid+1,r,k);
  s[p]=s[p<<1]+s[p<<1|1];
}

LL query(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return s[p];
  pushdown(p,l,r);
  int mid=(l+r)>>1;
  LL ans=0;
  if (ql<=mid)
    ans+=query(p<<1,l,mid);
  if (qr>mid)
    ans+=query(p<<1|1,mid+1,r);
  //s[p]=s[p<<1]+s[p<<1|1];
  return ans;
}

int main()
{
  freopen("3468.in","r",stdin);
  freopen("3468.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  build(1,1,n);
  while(m--)
  {
    scanf("%s",ch);
    if (ch[0]=='Q')
    {
      scanf("%d%d",&ql,&qr);
      printf("%I64d\n",query(1,1,n));
    }
    else
    {
      scanf("%d%d%d",&al,&ar,&k);
      update(1,1,n,k);
    }
  }
  return 0;
}
