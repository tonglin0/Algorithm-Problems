#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MN 320080
#define LL long long
using namespace std;

struct point{LL x1,x2,y;};
struct node{LL x,id;bool l;};
point q[MN];
LL hs[MN];
bool cmp(point a,point b){return a.y<b.y;}
bool cmp2(node a,node b){return a.x<b.x;}
node qs[MN];
LL s[MN];
LL add[MN];
int ql,qr;

void build(int p,int l,int r)
{
  if (l==r)
  {
    add[p]=0;
    s[p]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=add[p]=0;
}

void pushup(int p,int l,int r)
{
  if (add[p])
    s[p]=hs[r+1]-hs[l];
  else if (l==r)
    s[p]=0;
  else
    s[p]=s[p<<1]+s[p<<1|1];
}

void update(int p,int l,int r,int k)
{
  if (ql<=l&&qr>=r)
  {
    add[p]+=k;
    pushup(p,l,r);
    return ;
  }
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(p<<1,l,mid,k);
  if (qr>mid)
    update(p<<1|1,mid+1,r,k);
  pushup(p,l,r);
}

int main()
{
  freopen("3277.in","r",stdin);
  freopen("3277.out","w",stdout);
  int n,i,j,k,m,t=0;
  scanf("%d",&n);
  LL x1,x2,y;
  m=0;
  for (i=1;i<=n;i++)
  {
    scanf("%I64d%I64d%I64d",&q[i].x1,&q[i].x2,&q[i].y);
    node f;
    f.id=i;f.l=true;f.x=q[i].x1;
    qs[++m]=f;
    f.l=false;f.x=q[i].x2;
    qs[++m]=f;
  }
  sort(qs+1,qs+m+1,cmp2);
  t=0;
  int pre=-1;
  for (i=1;i<=m;i++)
  {
    if (qs[i].x!=pre)
    {
      pre=qs[i].x;
      hs[++t]=qs[i].x;
      qs[i].x=t;
    }
    else
    {
      qs[i].x=t;
    }
  }
  for (i=1;i<=m;i++)
  {
    if (qs[i].l)
      q[qs[i].id].x1=qs[i].x;
    else
      q[qs[i].id].x2=qs[i].x;
  }
  for(i=1;i<=n;i++)
  {
    q[i+n]=q[i];
    q[i+n].y=0;
  }
  build(1,1,t); 
  sort(q+1,q+n+n+1,cmp);
  LL ans=0;
  LL prey=-1;
  for (i=1;i<=n+n;i++)
  {
    if (q[i].y!=prey)
    {
      ans=ans+s[1]*(q[i].y-prey);
      prey=q[i].y;
    }
    ql=q[i].x1;qr=q[i].x2-1;
    if (q[i].y==0)
      update(1,1,t,1);
    else
      update(1,1,t,-1);
  }
  printf("%I64d\n",ans);
  return 0;
} 
