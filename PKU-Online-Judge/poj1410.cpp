#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define INF (int)1e9
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}

point l[5][2];

bool inpoly(point a,double x1,double y1,double x2,double y2)
{
  return a.x<=x2&&a.x>=x1&&a.y<=y2&&a.y>=y1;
}

bool between(point a,point b,point c)
{
  if (fabs(c.y-b.y)>fabs(c.x-b.x))
    return a.y<=max(c.y,b.y)&&a.y>=min(c.y,b.y);
  else
    return a.x<=max(b.x,c.x)&&a.x>=min(c.x,b.x);
}

bool sscross(point a,point b,point c,point d)
{
  double s1,s2,s3,s4;
  int d1,d2,d3,d4;
  d1=dcmp(s1=cross(b-a,c-a));
  d2=dcmp(s2=cross(b-a,d-a));
  d3=dcmp(s3=cross(d-c,a-c));
  d4=dcmp(s4=cross(d-c,b-c));
  if (d1*d2<0&&d3*d4<0) return true;
  if (d1==0&&between(c,a,b)||
      d2==0&&between(d,a,b)||
      d3==0&&between(a,c,d)||
      d4==0&&between(b,c,d))
  return true;
  return false; 
}

int main()
{
  //freopen("1410.in","r",stdin);
  //freopen("1410.out","w",stdout);
  int T,n,i,j,k,m;
  scanf("%d",&T);
  while(T--)
  {
    point a,b;
    scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
    double x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    if (dcmp(x1-x2)>0) swap(x1,x2);
    if (dcmp(y1-y2)>0) swap(y1,y2);
    memset(l,0,sizeof(l));
    l[0][0]=vec(x1,y1);
    l[0][1]=vec(x1,y2);
    l[1][0]=vec(x1,y2);
    l[1][1]=vec(x2,y2);
    l[2][0]=vec(x2,y2);
    l[2][1]=vec(x2,y1);
    l[3][0]=vec(x2,y1);
    l[3][1]=vec(x1,y1);
    if (inpoly(a,x1,y1,x2,y2)||inpoly(b,x1,y1,x2,y2))
      printf("T\n");
    else
    {
      bool flag=false;
      for (i=0;i<=3;i++)
        if (sscross(a,b,l[i][0],l[i][1]))
        {
          flag=true;
          break;
        }
      if (flag)
        printf("T\n");
      else
        printf("F\n");
    }
  }
  return 0;
}

