#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 10000009
using namespace std;

int c[MN];
struct point{int x,y;bool flag;int aid,po;};
int ans[500009];
point a[5*500009];
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;if (a.y!=b.y) return a.y<b.y;return a.flag;}

int low(int x){return x&(-x);}

void add(int x,int d)
{
  int i=x;
  while(i<MN)
  {
    c[i]+=d;
    i+=low(i);
  }
}

int find(int x)
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
  freopen("1935.in","r",stdin);
  freopen("1935.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  k=0;
  for (i=1;i<=n;i++)
  {
    point t;
    scanf("%d%d",&t.x,&t.y);
    t.flag=true;
    a[++k]=t;
  }
  for (i=1;i<=m;i++)
  {
    point t;
    int xa,xb,ya,yb;
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    t.flag=false;
    t.x=xa-1;t.y=ya-1;t.aid=i;t.po=0;
    a[++k]=t;
    t.y=yb;t.po=1;
    a[++k]=t;
    t.x=xb;t.y=ya-1;t.po=2;
    a[++k]=t;
    t.y=yb;t.po=3;
    a[++k]=t;
  }
  n=k;
  for (i=1;i<=n;i++)
  {
    a[i].x++;
    a[i].y++;
  }
  sort(a+1,a+n+1,cmp);
  memset(c,0,sizeof(c));
  for(i=1;i<=n;i++)
  {
    if (a[i].flag)
      add(a[i].y,1);
    else
    {
      if (a[i].po==0||a[i].po==3)
        ans[a[i].aid]+=find(a[i].y);
      else
        ans[a[i].aid]-=find(a[i].y);
    }
  }
  for (i=1;i<=m;i++)
    printf("%d\n",ans[i]);
  return 0;
}
