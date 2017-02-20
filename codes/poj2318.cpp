#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#define INF (int)1e9
#define eps 1e-10
using namespace std;

struct point
{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
};
typedef point vec;

int dcmp(double x)
{
  if (fabs(x)<eps) return 0;
  return x>0?1:-1;
}

int sum[10000];
point box[5005][4];

double cross(point a,point b,point c)
{
  return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int main()
{
  bool flag=false;
  //freopen("2318.in","r",stdin);
  //freopen("2318.out","w",stdout);
  int n,i,j,k,m,xa,ya,xb,yb;
  scanf("%d",&n);
  while(n)
  {
    if (flag) printf("\n");
    flag=true;
    scanf("%d%d%d%d%d",&m,&xa,&ya,&xb,&yb);
    memset(sum,0,sizeof(sum));
    memset(box,0,sizeof(box));
    box[0][0]=vec(xa,ya);
    box[0][1]=vec(xa,yb);
    int x1,x2;
    scanf("%d%d",&x1,&x2);
    box[0][2]=vec(x1,ya);
    box[0][3]=vec(x2,yb);
    for (i=1;i<=n-1;i++)
    {
      box[i][0]=box[i-1][2];
      box[i][1]=box[i-1][3];
      scanf("%d%d",&x1,&x2);
      box[i][2]=vec(x1,ya);
      box[i][3]=vec(x2,yb);
    }
    box[n][0]=box[n-1][2];
    box[n][1]=box[n-1][3];
    box[n][2]=vec(xb,ya);
    box[n][3]=vec(xb,yb);
    int l=0,r=n;
    for (i=1;i<=m;i++)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      l=0;r=n;
      bool f=false;
      while(!f)
      {
        int mid=(l+r)>>1;
        point a=box[mid][0],b=box[mid][1],c=box[mid][2],d=box[mid][3];
        point p=vec(x,y);
        int s1=dcmp(cross(p,a,b));
        int s2=dcmp(cross(p,c,d));
        if (s1<0&&s2<0)
          r=mid-1;
        else if (s2>0&&s2>0)
          l=mid+1;
        else if (s1>=0&&s2<=0)
        {
          sum[mid]++;
          f=true;
        }
      }
    }
    for (i=0;i<=n;i++)
      printf("%d: %d\n",i,sum[i]);
    scanf("%d",&n);
  }
  return 0;
}
