#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 50006
#define LL long long
using namespace std;

LL s[MN<<3];
int cnt[MN<<3];
int ql,qr;
struct node{int x1,x2,y;bool up;};
node q[MN<<3];
bool cmp(node a,node b){return a.y<b.y;}

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
  if (cnt[p])
    s[p]=r-l+1;
  else if (l==r)
    s[p]=0;
  else
    s[p]=s[p<<1]+s[p<<1|1];
}

void update(int p,int l,int r,int k)
{
  if (ql>qr) return ;
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
  freopen("3832.in","r",stdin);
  freopen("3832.out","w",stdout);
  int n,i,j,k,m=0,a1,a2,a3,a4,b1,b2,b3,b4;
  scanf("%d",&n);
  while(n)
  {
    m=0;
    build(1,0,50000);
    node t;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3,&a4,&b4);
      t.x1=a1;t.x2=a3;t.y=b1;t.up=false;
      q[++m]=t;
      t.y=b2;t.up=true;
      q[++m]=t;
      
      t.x1=a3;t.x2=a4;t.y=b1;t.up=false;
      q[++m]=t;
      t.y=b3;t.up=true;
      q[++m]=t;
      
      t.x1=a3;t.x2=a4;t.y=b4;t.up=false;
      q[++m]=t;
      t.y=b2;t.up=true;
      q[++m]=t;
      
      t.x1=a4;t.x2=a2;t.y=b1;t.up=false;
      q[++m]=t;
      t.y=b2;t.up=true;
      q[++m]=t;
    }
    sort(q+1,q+m+1,cmp);
    LL ans=0;
    int prey=q[1].y;
    for (i=1;i<=m;i++)
    {
      if (q[i].y!=prey)
      {
        ans+=s[1]*(q[i].y-prey);
        prey=q[i].y;
      }
      ql=q[i].x1;qr=q[i].x2-1;
      if (!q[i].up)
        update(1,0,50000,1);
      else
        update(1,0,50000,-1);
    }
    printf("%I64d\n",ans);
    scanf("%d",&n);
  }
  return 0;
}
