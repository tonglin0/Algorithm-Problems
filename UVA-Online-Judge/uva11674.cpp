#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define eps 2e-5
#define PI acos(-1.0)
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
struct node{double sa,sb,ta,tb,l;};
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
point point_on_circle(point o,double r,double ang){return vec(o.x+r*cos(ang),o.y+r*sin(ang));}
bool cmp(node a,node b){if (dcmp(a.sa-b.sa)!=0) return a.sa<b.sa;return a.sb<b.sb;}
double atan2(vec v){return atan2(v.y,v.x);}

vector<node> anss;
bool swaped=false;

int find_tangent(point a,double r1,point b,double r2)
{
  if (dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0&&dcmp(r1-r2)==0)
    return -1;                              //重合 
  point c,e;double r3;
  if (dcmp(r1-r2)<0){swaped=true;c=a;a=b;b=c;r3=r1;r1=r2;r2=r3;} 
  double d=dist(a,b);
  if (dcmp(d-(r1-r2))<0) 
    return 0;                               //内含 
  if (dcmp(d-(r1-r2))==0)                   //内切 
  {
    vec u=b-a;
    double ang=atan2(u);
    c=point_on_circle(a,r1,ang);
    node t;
    t.sa=c.x;t.sb=c.y;t.ta=c.x;t.tb=c.y;t.l=0.0;
    anss.push_back(t);
    return 1; 
  }
  if (dcmp(d-(r1-r2))>0&&dcmp(d-(r1+r2))<0)//相交 
  {
    vec u=b-a;
    double ang=atan2(u);
    double an=atan2(a-b);
    double ro=acos((r1-r2)/d);
    double ro2=asin((r1-r2)/d);
    double ang1=ang+ro;
    double ang2=an-ro2-PI/2.0;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    node t;t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    ang1=ang-ro;
    ang2=an+ro2+PI/2.0;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    return 2;
  }
  if (dcmp(d-(r1+r2))==0)                 //外切
  {
    vec u=b-a;
    double ang=atan2(u);
    c=point_on_circle(a,r1,ang);
    node t;
    t.sa=c.x;t.sb=c.y;t.ta=c.x;t.tb=c.y;t.l=0.0;
    anss.push_back(t);
    double an=atan2(a-b);
    double ro=acos((r1-r2)/d);
    double ro2=asin((r1-r2)/d);
    double ang1=ang+ro;
    double ang2=an-ro2-PI/2.0;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    ang1=ang-ro;
    ang2=an+ro2+PI/2.0;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    return 3;
  } 
  if (dcmp(d-(r1+r2))>0)                              //外离
  {
    vec u=b-a;
    double ang=atan2(u);
    double an=atan2(a-b);
    double ro=acos((r1-r2)/d);
    double ro2=asin((r1-r2)/d);
    double ang1=ang+ro;
    double ang2=an-ro2-PI/2.0;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    node t;t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    ang1=ang-ro;
    ang2=an+ro2+PI/2.0;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    ro=acos((r1+r2)/d);
    ang1=ang+ro;
    ang2=an+ro;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    ang1=ang-ro;
    ang2=an-ro;
    c=point_on_circle(a,r1,ang1);
    e=point_on_circle(b,r2,ang2);
    t.sa=c.x;t.sb=c.y;t.ta=e.x;t.tb=e.y;t.l=dist(c,e);
    anss.push_back(t);
    return 4;
  } 
}

int main()
{
  freopen("10674.in","r",stdin);
  freopen("10674.out","w",stdout);
  int n,i,j,k,m;
  double xa,ya,xb,yb,r1,r2;
  //printf("%.10lf\n",eps);
  scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&r1,&xb,&yb,&r2);
  while(!(dcmp(xa)==0&&dcmp(xb)==0&&dcmp(r1)==0&&dcmp(ya)==0&&dcmp(yb)==0&&dcmp(r2)==0))
  {
    anss.clear();
    swaped=false;
    m=find_tangent(vec(xa,ya),r1,vec(xb,yb),r2);
    printf("%d\n",m);
    if (swaped)
      for (i=0;i<anss.size();i++)
      {
        double x,y;
        x=anss[i].sa;anss[i].sa=anss[i].ta;anss[i].ta=x;
        y=anss[i].sb;anss[i].sb=anss[i].tb;anss[i].tb=y;
      }
    if (m>1) 
      sort(anss.begin(),anss.end(),cmp);
    for (i=0;i<anss.size();i++)
      printf("%.5lf %.5lf %.5lf %.5lf %.5lf\n",anss[i].sa,anss[i].sb,anss[i].ta,anss[i].tb,anss[i].l);
    scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&r1,&xb,&yb,&r2);
  }
  return 0;
}
