#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define PI acos(-1.0)
#define eps 1e-8
#define MN 40009
using namespace std;

int deg[MN];
int ql,qr;
double dx[MN],dy[MN];
int da[MN];

void build(int p,int l,int r)
{
  da[p]=0;
  dx[p]=0;
  if (l==r)
  {
    scanf("%lf",&dy[p]);
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  dy[p]=dy[p<<1]+dy[p<<1|1];
}

void rotate(int p,int k)
{
  double ang=k/180.0*PI;
  double x=dx[p]*cos(ang)-dy[p]*sin(ang);
  double y=dx[p]*sin(ang)+dy[p]*cos(ang);
  dx[p]=x;dy[p]=y;
}

void pushdown(int p,int l,int r)
{
  rotate(p<<1,da[p]);
  rotate(p<<1|1,da[p]);
  da[p<<1]+=da[p];
  da[p<<1|1]+=da[p];
  da[p]=0;
}

void update(int p,int l,int r,int k)
{
  if (ql<=l&&qr>=r)
  {
    da[p]+=k;
    rotate(p,k);
    return ;
  }
  if (da[p]!=0)
    pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(p<<1,l,mid,k);
  if (qr>mid)
    update(p<<1|1,mid+1,r,k);
  dx[p]=dx[p<<1]+dx[p<<1|1];
  dy[p]=dy[p<<1]+dy[p<<1|1];
}

int main()
{
  freopen("2991.in","r",stdin);
  freopen("2991.out","w",stdout);
  int n,i,j,k,m;
  bool first=true;
  while(scanf("%d%d",&n,&m)==2)
  {
    for (i=1;i<=n;i++)
      deg[i]=180;
    if (!first)
      printf("\n");
    first=false;
    build(1,1,n);
    while(m--)
    {
      scanf("%d%d",&ql,&j);
      qr=n;
      ql++;
      update(1,1,n,j-deg[ql]);
      deg[ql]=j;
      printf("%.2lf %.2lf\n",dx[1]+eps,dy[1]+eps);
    }
  }
  return 0;
}
