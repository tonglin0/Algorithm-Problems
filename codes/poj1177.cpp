#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define LL long long
#define MN 81009
using namespace std;

struct node{int x1,x2,y;bool isup;};
node q[MN];
struct node2{int y1,y2,x;bool isleft;};
node2 q2[MN];
int s[MN],cnt[MN];
int ql,qr;
bool cmp(node a,node b){if (a.y!=b.y) return a.y<b.y;if (a.isup) return false;return true;}
bool cmp2(node2 a,node2 b){if (a.x!=b.x) return a.x<b.x;if (a.isleft) return true;return false;}

void build(int p,int l,int r)
{
  if (l==r)
  {
    s[p]=cnt[p]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=cnt[p]=0;
}

void pushup(int p,int l,int r)
{
  if (cnt[p]>0)
    s[p]=r-l+1;
  else if (l==r)
    s[p]=0;
  else s[p]=s[p<<1]+s[p<<1|1];
}

void update(int p,int l,int r,int k)
{
  if (ql<=l&&qr>=r)
  {
    cnt[p]+=k;
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

LL query(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return (LL)s[p];
  if (cnt[p]>0)
    return (LL)(min(qr,r)-max(ql,l)+1);
  int mid=(l+r)>>1;
  LL ans=0;
  if (ql<=mid)
    ans=query(p<<1,l,mid);
  if (qr>mid)
    ans=ans+query(p<<1|1,mid+1,r);
  return ans;
}

int main()
{
  freopen("1177.in","r",stdin);
  freopen("1177.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1){
  build(1,-10000,10000);
  node t;
  m=0;
  node2 t2;
  int m2=0;
  int xa,xb,ya,yb;
  for (i=1;i<=n;i++)
  {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    t.x1=xa;t.x2=xb;t.y=ya;t.isup=false;
    q[++m]=t;
    t.y=yb;t.isup=true;
    q[++m]=t;
    t2.y1=ya;t2.y2=yb;t2.x=xa;t2.isleft=true;
    q2[++m2]=t2;
    t2.x=xb;t2.isleft=false;
    q2[++m2]=t2;
  }
  sort(q+1,q+m+1,cmp);
  sort(q2+1,q2+m2+1,cmp2);
  LL ans=0;
  LL temp;
  int prey=q[1].y;
  for (i=1;i<=m;i++)
  {
    if (!q[i].isup)
    {
      ql=q[i].x1;qr=q[i].x2-1;
      temp=query(1,-10000,10000);
      ans=ans+(q[i].x2-q[i].x1-temp);
      update(1,-10000,10000,1);
    }
    else
    {
      ql=q[i].x1;qr=q[i].x2-1;
      update(1,-10000,10000,-1);
      temp=query(1,-10000,10000);
      ans=ans+q[i].x2-q[i].x1-temp;
    }
  }
  build(1,-10000,10000);
  int prex=q2[1].x;
  for (i=1;i<=m2;i++)
  {
    if (q2[i].isleft)
    {
      ql=q2[i].y1;qr=q2[i].y2-1;
      temp=query(1,-10000,10000);
      ans=ans+(q2[i].y2-q2[i].y1-temp);
      update(1,-10000,10000,1);
    }
    else
    {
      ql=q2[i].y1;qr=q2[i].y2-1;
      update(1,-10000,10000,-1);
      temp=query(1,-10000,10000);
      ans=ans+q2[i].y2-q2[i].y1-temp;
    }
  }
  printf("%I64d\n",ans);}
  return 0;
}
