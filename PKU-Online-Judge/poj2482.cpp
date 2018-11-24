#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 850009
#define LL long long
using namespace std;

LL Max(LL a,LL b){return a>b?a:b;}
struct node{LL x1,x2,y,c;bool up;};
node q[MN];
struct point{LL x;int id;bool l;};
point qs[MN];
bool cmp(point a,point b){return a.x<b.x;}
LL hs[MN];
bool cmp2(node a,node b){if (a.y!=b.y)return a.y<b.y;if (a.up) return true;return false;}
LL ms[MN];
LL set[MN];
int ql,qr;

void pushup(int p,int l,int r)
{
  ms[p]=Max(ms[p<<1],ms[p<<1|1]);
}

void pushdown(int p,int l,int r)
{
  if (set[p])
  {
    set[p<<1]+=set[p];
    ms[p<<1]+=set[p];
    set[p<<1|1]+=set[p];
    ms[p<<1|1]+=set[p];
    set[p]=0;
  }
}

void update(int p,int l,int r,LL k)
{
  if (ql<=l&&qr>=r)
  {
    ms[p]+=(LL)k;
    set[p]+=(LL)k;
    //pushup(p,l,r);
    return ;
  }
  pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(p<<1,l,mid,k);
  if (qr>mid)
    update(p<<1|1,mid+1,r,k);
  pushup(p,l,r);
}

int main()
{
  LL i,j,k,m;
  LL a,b,n;
  freopen("2482.in","r",stdin);
  freopen("2482.out","w",stdout);
  while(scanf("%I64d%I64d%I64d",&n,&a,&b)==3)
  {
    node t;
    point p;
    LL x,y,z;
    m=0;
    LL top=0;
    for (i=1;i<=n;i++)
    {
      scanf("%I64d%I64d%I64d",&x,&y,&z);
      t.c=z;t.y=y-b;t.up=false;
      q[++m]=t;
      p.x=x-a+1;p.id=m;p.l=true;
      qs[++top]=p;
      p.x=x;p.l=false;
      qs[++top]=p;
      t.y=y;t.up=true;
      q[++m]=t;
    }
    sort(qs+1,qs+top+1,cmp);
    LL prex=-1;
    LL temp=0;
    for (i=1;i<=top;i++)
      if (qs[i].x!=prex)
      {
        hs[++temp]=qs[i].x;
        prex=qs[i].x;
        qs[i].x=temp;
      }
      else
        qs[i].x=temp;
    for (i=1;i<=top;i++)
      if (qs[i].l)
        q[qs[i].id].x1=q[qs[i].id+1].x1=qs[i].x;
      else
        q[qs[i].id].x2=q[qs[i].id+1].x2=qs[i].x;
    sort(q+1,q+m+1,cmp2);
    LL ans=0;
    memset(set,0,sizeof(set));
    memset(ms,0,sizeof(ms));//build(1,1,temp);
    for (i=1;i<=m;i++)
    {
      ans=Max(ans,ms[1]);
      ql=q[i].x1;qr=q[i].x2;
      if (q[i].up)
        update(1,1,temp,-q[i].c);
      else
        update(1,1,temp,q[i].c);
    }
    printf("%I64d\n",ans);
  }
  return 0;
}
