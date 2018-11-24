#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
struct line{
	point p;vec v;
	double ang;
	line(){}
	line(point p,vec v):p(p),v(v){}
};
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool onleft(point p,line l){return dcmp(cross(l.v,p-l.p)>0);}

point p[305],poly[305];
line l[310],q[310];

int main()
{
  freopen("1038.in","r",stdin);
  freopen("1038.out","w",stdout);
  int n,m,i,j,k;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%lf",&poly[i].x);
  for (i=1;i<=n;i++)
    scanf("%lf",&poly[i].y);
  int top=0;
  line t;
  t.p=vec(0,0);t.v=vec(1,0);
  l[++top]=t;
  t.p=vec(poly[n].x,0);t.v=vec(0,1);
  l[++top]=t;
  t.p=vec(poly[n].x,inf);t.v=(-1,0);
  l[++top]=t;
  t.p=(0,0);
  
}

