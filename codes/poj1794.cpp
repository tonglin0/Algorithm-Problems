#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MN 60011
using namespace std;

struct point{int x,y;bool isr;};
point a[MN];
int r[MN],b[MN];
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}

int low(int x){return x&(-x);}

void add(int *c,int x,int d)
{
  int i=x;
  while(i<MN)
  {
    c[i]+=d;
    i+=low(i);
  }
}

int find(int *c,int x)
{
  int ans=0,i=x;
  while(i>0)
  {
    ans+=c[i];
    i-=low(i);
  }
  return ans;
}

int main()
{
  freopen("1794.in","r",stdin);
  freopen("1794.out","w",stdout);
  int n,i,j,k,m,T,ii;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    scanf("%d%d",&n,&m);
    memset(r,0,sizeof(r));
    memset(b,0,sizeof(b));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&a[i].x,&a[i].y);
      a[i].isr=true;
    }
    for (i=1;i<=m;i++)
    {
      scanf("%d%d",&a[i+n].x,&a[i+n].y);
      a[i+n].isr=false;
    }
    for (i=1;i<=n+m;i++)
      a[i].y=MN-a[i].y;
    sort(a+1,a+n+m+1,cmp);
    int ans=0;
    for (i=1;i<=n+m;i++)
      if (a[i].isr)
      {
        ans+=find(b,a[i].y);
        add(r,a[i].y,1);
      }
      else
      {
        ans+=find(r,a[i].y);
        add(b,a[i].y,1);
      }
    printf("Scenario #%d:\n",ii);
    printf("%d\n\n",ans);
  }
  return 0;
}
