#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define LL long long 
#define MN 200009
using namespace std;

int ql,qr;
int s[MN];
int cnt[MN];
struct node{int x1,x2,y;bool isup;};
node q[MN];
bool cmp(node a,node b){return a.y<b.y;}

void build(int p,int l,int r)
{
  if (l==r)
  {
    s[p]=0;
    return;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=0;
}

void pushup(int p,int l,int r)
{
  if (cnt[p])
    s[p]=r-l+1;
  else if (l==r)
    s[p]=0;
  else 
    s[p]=s[p<<1]+s[p<<1|1];
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

int main()
{
  freopen("1389.in","r",stdin);
  freopen("1389.out","w",stdout);
  int n,i,j,k,xa,xb,ya,yb,m;
  scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
  node t;
  while(!(xa==-1&&xb==-1&&ya==-1&&yb==-1))
  {
    memset(q,0,sizeof(q));
    m=0;
    build(1,0,50000);
    t.x1=xa;t.x2=xb;t.y=ya;t.isup=false;
    q[++m]=t;
    t.y=yb;t.isup=true;
    q[++m]=t;
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    while(!(xa==-1&&xb==-1&&ya==-1&&yb==-1))
    {
      t.x1=xa;t.x2=xb;t.y=ya;t.isup=false;
      q[++m]=t;
      t.y=yb;t.isup=true;
      q[++m]=t;
      scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    }
    sort(q+1,q+m+1,cmp);
    LL ans=0;
    int prey=-1;
    for (i=1;i<=m;i++)
    {
      if (q[i].y!=prey)
      {
        ans+=s[1]*(q[i].y-prey);
        prey=q[i].y;
      }
      ql=q[i].x1;qr=q[i].x2-1;
      if (q[i].isup)
        update(1,0,50000,-1);
      else
        update(1,0,50000,1);
    }
    printf("%I64d\n",ans);
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
  }
  return 0;
}
