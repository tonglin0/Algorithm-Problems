#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define INF (int)1e9
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;

vec operator - (vec a,vec b)
{
  return vec(a.x-b.x,a.y-b.y);
}
vec operator + (vec a,vec b)
{
  return vec(a.x+b.x,a.y+b.y);
}
vec operator * (vec a,double b)
{
  return vec(a.x*b,a.y*b);
}

int dcmp(double a)
{
  if (fabs(a)<eps) return 0;
  return a<0?-1:1;
}

double cross(vec a,vec b)
{
  return a.x*b.y-b.x*a.y;
}

point linewithline(point a,vec v,point b,vec w)
{
  vec u=a-b;
  return a+v*(cross(w,u)/cross(v,w));
}

int main()
{
  //freopen("1269.in","r",stdin);
  //freopen("1269.out","w",stdout);
  int T,n,i,j,k,m;
  scanf("%d",&T);
  printf("INTERSECTING LINES OUTPUT\n");
  while(T--)
  {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    point a,b,c,d;
    a.x=x1;a.y=y1;b.x=x2;b.y=y2;
    c.x=x3;c.y=y3;d.x=x4;d.y=y4;
    vec v=b-a,w=d-c;
    if (dcmp(cross(v,w))==0)
    {
      if (dcmp(cross(c-a,v))==0)
        printf("LINE\n");
      else
        printf("NONE\n");
    }  
    else
    {
      printf("POINT ");
      point p=linewithline(a,v,c,w);
      printf("%.2lf %.2lf\n",p.x,p.y);
    }
  }
  printf("END OF OUTPUT\n");
  return 0;
}
