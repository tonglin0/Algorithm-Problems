#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-8
using namespace std;

struct point{double x,y,ang;point(double x=0,double y=0):x(x),y(y){}};
//             bool operator < (point b) const {return ang<b.ang;}};
typedef point vec;
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
bool cmp(point a,point b)
{
  return dcmp(cross(a,b))>0;
}

point p[100];

int main()
{
  //freopen("2007.in","r",stdin);
  //freopen("2007.out","w",stdout);
  memset(p,0,sizeof(p));
  int n,i,j,k,m;
  n=0;
  double x,y;
  while(scanf("%lf%lf",&x,&y)==2)
  {
    p[n]=point(x,y);
    n++;
  }
  double xx=(p[0].x+p[1].x)/2;
  double yy=(p[0].y+p[1].y)/2;
  //while(scanf("%lf%lf",&p[n].x,&p[n].y)==2)
  //  n++;
  //for (i=1;i<n;i++)
    //p[i].ang=atan2(p[i].y-yy,p[i].x-xx);
  sort(p+1,p+n,cmp);
  for (i=0;i<n;i++)
    printf("(%d,%d)\n",(int)floor(p[i].x+0.5),(int)floor(p[i].y+0.5));
  return 0;
}
