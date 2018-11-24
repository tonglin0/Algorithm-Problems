#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define MN 16030
using namespace std;

struct node{int x1,x2;double y;bool up;};
node p[4012];
struct point{double x;int nx,id;bool left;};
point q[8120];
bool cmpx(point a,point b){return a.x<b.x;}
bool cmpy(node a,node b){return a.y<b.y;}
int ql,qr;
int cnt[MN];
double s1[MN],s2[MN];
double hash[MN];
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}

void build(int p,int l,int r)
{
  if (l==r)
  {
    cnt[p]=0;
    s2[p]=s1[p]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  cnt[p]=0;
  s1[p]=s2[p]=0;
}

void pushup(int p,int l,int r)
{
  if (l==r)
  {
    if (cnt[p]>=2)
    {
      s2[p]=hash[r+1]-hash[l];
      s1[p]=0;
    }
    else if (cnt[p]==1)
    {
      s1[p]=hash[r+1]-hash[l];
      s2[p]=0;
    }
    else
    {
      s1[p]=s2[p]=0;
    }
    return ;
  }
  if (cnt[p]>=2)
  {
    s2[p]=hash[r+1]-hash[l];
    s1[p]=0;
  }
  else if (cnt[p]==1)
  {
    s2[p]=s2[p<<1]+s2[p<<1|1]+s1[p<<1]+s1[p<<1|1];
    s1[p]=hash[r+1]-hash[l]-s2[p];
  }
  else
  {
    s2[p]=s2[p<<1]+s2[p<<1|1];
    s1[p]=s1[p<<1]+s1[p<<1|1];
  }
}

void update(int p,int l,int r,int d)
{
  if (ql<=l&&qr>=r)
  {
    cnt[p]+=d;
    pushup(p,l,r);
    return ;
  }
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(p<<1,l,mid,d);
  if (qr>mid)
    update(p<<1|1,mid+1,r,d);
  pushup(p,l,r);
}

int main()
{
  freopen("1255.in","r",stdin);
  freopen("1255.out","w",stdout);
  int T,n,i,j,k,m;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&n);
    double xa,ya,xb,yb;
    int top=0;k=0;
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
      node tmp;
      tmp.y=ya;tmp.up=false;
      p[++k]=tmp;
      tmp.y=yb;tmp.up=true;
      p[++k]=tmp;
      point t;
      t.x=xa;t.id=k-1;t.left=true;
      q[++top]=t;
      t.x=xb;t.id=k-1;t.left=false;
      q[++top]=t;
    }
    sort(q+1,q+top+1,cmpx);
    int t=0;
    for (i=1;i<=top;i++)
      if (i==1||dcmp(q[i].x-q[i-1].x)!=0)
      {
        q[i].nx=++t;
        hash[t]=q[i].x;
      }
      else
        q[i].nx=t;
    for (i=1;i<=top;i++)
      if (q[i].left)
      {
        p[q[i].id].x1=q[i].nx;
        p[q[i].id+1].x1=q[i].nx;
      }
      else
      {
        p[q[i].id].x2=q[i].nx;
        p[q[i].id+1].x2=q[i].nx;
      }
    n=k;
    t++;
    sort(p+1,p+k+1,cmpy);
    double ans=0;
    double pre;
    build(1,1,t);
    for (i=1;i<=n;i++)
    {
      if (dcmp(p[i].y-pre)!=0)
      {
        ans+=(p[i].y-pre)*s2[1];
        pre=p[i].y;
      }
      ql=p[i].x1;qr=p[i].x2-1;
      if (p[i].up)
        update(1,1,t,-1);
      else
        update(1,1,t,1);
    }
    printf("%.2lf\n",ans);
  }
  return 0;
}
