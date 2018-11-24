#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
struct line{
       point p;vec v;
       line(){}
       line(point p,vec v):p(p),v(v){}};
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dot(a,a));}
vec normal(vec a){double l=length(a);return vec(-a.y/l,a.x/l);}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}

int main()
{
  freopen("1673.in","r",stdin);
  freopen("1673.out","w",stdout);
  int n,i,j,k,m;
  point a,b,c;
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    line l1,l2;
    l1.p=c;
    l1.v=normal(b-a);
    l2.p=b;
    l2.v=normal(c-a);
    point p=llcross(l1.p,l1.v,l2.p,l2.v);
    printf("%.4lf %.4lf\n",p.x+eps,p.y+eps);
  }
  return 0;
}
