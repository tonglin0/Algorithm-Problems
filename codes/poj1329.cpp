#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define PI 4.0*atan(1.0)
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
vec rotate(vec a,double b){return vec(a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b));}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dot(a,a));}

point llcross(point a,vec v,point b,vec w)
{
  vec u=a-b;
  return a+v*(cross(w,u)/cross(v,w));
}

int main()
{
  freopen("1329.in","r",stdin);
  freopen("1329.out","w",stdout);
  point a,b,c;
  while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)==6)
  {
    point ab=vec((a.x+b.x)/2.0,(a.y+b.y)/2.0);
    vec u=rotate(b-a,PI/2.0);
    point bc=vec((b.x+c.x)/2.0,(b.y+c.y)/2.0);
    vec v=rotate(c-b,PI/2.0);
    point o=llcross(ab,u,bc,v);
    double r=length(o-a);
    char c1,c2;
    if (o.x>0) c1='-';
      else c1='+';
    if (o.y>0) c2='-';
      else c2='+';
    char c3;
    double z=o.x*o.x+o.y*o.y-r*r;
    if (z>0) c3='+';
      else c3='-';
    printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",c1,fabs(o.x),c2,fabs(o.y),fabs(r));
    printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",c1,2*fabs(o.x),c2,2*fabs(o.y),c3,fabs(z));
    printf("\n");
  }
  return 0;
}
