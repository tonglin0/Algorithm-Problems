#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define MN 200006
using namespace std;

struct node{int id,x,y,l,r,u,d,xs,xl,ys,yl,zx,zs,yx,ysh;};
node a[MN],b[MN];
int c[MN];
int n,tx,ty;
bool cmp1(node a,node b){if (a.x!=b.x)return a.x<b.x;return a.y<b.y;}
bool cmp2(node a,node b){if (a.y!=b.y)return a.y<b.y;return a.x<b.x;}
bool cmp3(node a,node b){if (a.x!=b.x)return a.x<b.x;return a.y>b.y;}
vector<int> anss;

int low(int x){return x&(-x);}

void add(int x,int d)
{
  int i=x;
  while(i<=ty)
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
  freopen("2464.in","r",stdin);
  freopen("2464.out","w",stdout);
  int m,i,j,k,x,y;
  scanf("%d",&n);
  while(n)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&a[i].x,&a[i].y);
      a[i].id=i;
    }
    sort(a+1,a+n+1,cmp1);               // x-y <
    int pre=51118321;
    tx=0;                           // ÀëÉ¢x×ø±ê 
    for (i=1;i<=n;i++)
      if (a[i].x!=pre)
      {
        pre=a[i].x;
        a[i].x=++tx;
      }
      else
        a[i].x=tx;
    a[1].xs=0;
    a[1].d=0;                         // find XS and down
    for (i=2;i<=n;i++)
    {
      if (a[i].x!=a[i-1].x)
      {
        a[i].xs=i-1;
        a[i].d=0;
      }
      else
      {
        a[i].xs=a[i-1].xs;
        a[i].d=a[i-1].d+1;
      }
    }
    a[n].xl=0;                         // find XL and up
    a[n].u=0;
    for (i=n-1;i>=1;i--)
      if (a[i].x!=a[i+1].x)
      {
        a[i].xl=n-i;
        a[i].u=0;
      }
      else
      {
        a[i].xl=a[i+1].xl;
        a[i].u=a[i+1].u+1;
      }
    for (i=1;i<=n;i++)
      b[a[i].id]=a[i];
    for (i=1;i<=n;i++)
      a[i]=b[i];
    sort(a+1,a+n+1,cmp2);             // y-x <  
    pre=12315165;
    ty=0;
    for (i=1;i<=n;i++)                //ÀëÉ¢y×ø±ê 
      if (a[i].y!=pre)
      {
        pre=a[i].y;
        a[i].y=++ty;
      }
      else
        a[i].y=ty;
    a[1].ys=0;
    a[1].l=0;
    for (i=2;i<=n;i++)                // find YS and l
      if (a[i].y!=a[i-1].y)
      {
        a[i].ys=i-1;
        a[i].l=0;
      }
      else
      {
        a[i].ys=a[i-1].ys;
        a[i].l=a[i-1].l+1;
      }
    a[n].yl=0;
    a[n].r=0;
    for (i=n-1;i>=1;i--)              // find YL and r
      if (a[i].y!=a[i+1].y)
      {
        a[i].yl=n-i;
        a[i].r=0;
      }
      else
      {
        a[i].yl=a[i+1].yl;
        a[i].r=a[i+1].r+1;
      }
    for (i=1;i<=n;i++)
      b[a[i].id]=a[i];
    for (i=1;i<=n;i++)
      a[i]=b[i];
    sort(a+1,a+n+1,cmp3);
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
    {
      a[i].zx=find(a[i].y-1);
      add(a[i].y,1);
      a[i].zs=a[i].xs-a[i].zx-a[i].l;
      a[i].yx=a[i].ys-a[i].zx-a[i].d;
      a[i].ysh=a[i].xl-a[i].yx-a[i].r;
    }
    int ans=-1;
    anss.clear();
    i=1;
    while(i<=n)
    {
      j=i;
      while((j+1)<=n&&a[j+1].x==a[i].x) j++;
      int minj=(int)1e9;
      int maxj=-1;
      for (k=i;k<=j;k++)
      {
        if (a[k].zx+a[k].ysh<minj)
          minj=a[k].zx+a[k].ysh;
        if (a[k].zs+a[k].yx>maxj)
          maxj=a[k].zs+a[k].yx;
      }
      if (minj>ans)
      {
        ans=minj;
        anss.clear();
        anss.push_back(maxj);
      }
      else if (minj==ans)
        anss.push_back(maxj);
      i=j+1;
    }
    sort(anss.begin(),anss.end());
    printf("Stan: %d; ",ans);
    printf("Ollie:");
    for (i=0;i<anss.size();i++)
      if (i==0||(i>0&&anss[i]!=anss[i-1]))
        printf(" %d",anss[i]);
    printf(";\n");
    scanf("%d",&n);
  }
  return 0;
}
