#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#define INF (int)1e9
#define eps 1e-8
using namespace std;

struct point
{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
};
typedef pair<int,int> pii;
typedef point vec;
int sum[5003],s[5003];
point box[5004][4];
pii p[5004];

bool cmp(pii a,pii b)
{
  if (a.first!=b.first) return a.first<b.first;
  return a.second<b.second;
}

int dcmp(double x)
{
  if (fabs(x)<eps)
    return 0;
  return x>0?1:-1;
}

double cross(point a,point b,point c)
{
  return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int main()
{
  //freopen("2398.in","r",stdin);
  //freopen("2398.out","w",stdout);
  int n,i,j,k,m,xa,xb,ya,yb;
  scanf("%d",&n);
  while(n)
  {
    scanf("%d%d%d%d%d",&m,&xa,&ya,&xb,&yb);
    memset(sum,0,sizeof(sum));
    memset(box,0,sizeof(box));
    int x1,x2,y1,y2;
    box[0][0]=vec(xa,ya);
    box[0][1]=vec(xa,yb);
    memset(p,0,sizeof(p));
    for (i=1;i<=n;i++)
      scanf("%d%d",&p[i].first,&p[i].second);
    sort(p+1,p+n+1,cmp);
    //for (i=1;i<=n;i++)
      //printf("x1=%d x2=%d\n",p[i].first,p[i].second);
    for (i=1;i<=n;i++)
    {
      box[i-1][2]=vec(p[i].first,ya);
      box[i-1][3]=vec(p[i].second,yb);
      box[i][0]=vec(p[i].first,ya);
      box[i][1]=vec(p[i].second,yb);
    }
    box[n][2]=vec(xb,ya);
    box[n][3]=vec(xb,yb);
    for (i=1;i<=m;i++)
    {
      point u;
      int x,y;
      scanf("%d%d",&x,&y);
      u.x=x;u.y=y;
      int l=0,r=n;
      bool flag=true;
      while(flag)
      {
        int mid=(l+r)>>1;
        point a=box[mid][0],b=box[mid][1],c=box[mid][2],d=box[mid][3];
        int s1=dcmp(cross(u,a,b));
        int s2=dcmp(cross(u,c,d));
        if (s1>0&&s2>0)
          l=mid+1;
        else if (s1<0&&s2<0)
          r=mid-1;
        else if (s1>0&&s2<0)
        {
          sum[mid]++;
          flag=false;
        }
      }
    }
    memset(s,0,sizeof(s));
    /*for (i=0;i<=n;i++)
      printf("%d ",sum[i]);
    printf("\n");*/
    for (i=0;i<=n;i++)
      if (sum[i]>0)
        s[sum[i]]++;
    printf("Box\n");
    for (i=1;i<=m;i++)
      if (s[i]>0)
        printf("%d: %d\n",i,s[i]);
    scanf("%d",&n);
  }
  return 0;
}
