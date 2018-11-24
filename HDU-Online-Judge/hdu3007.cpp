#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-6
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}
bool cmpy(point a,point b){return a.y<b.y;}
double min(double a,double b){return a<b?a:b;}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
vec rotate(vec v){return vec(-v.y,v.x);}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}

point p[1506];

void find_circle(point a,point b,point c,point &o,double &r)
{
  /*if (dcmp(dot(b-a,c-a))<=0)
  {
    o=vec((b.x+c.x)/2.0,(b.y+c.y)/2.0);
    r=dist(o,c);
    return ;
  }
  if (dcmp(dot(c-b,a-b))<=0)
  {
    o=vec((a.x+c.x)/2.0,(a.y+c.y)/2.0);
    r=dist(a,o);
    return ;
  }
  if (dcmp(dot(a-c,b-c))<=0)
  {
    o=vec((b.x+a.x)/2.0,(a.y+b.y)/2.0);
    r=dist(a,o);
    return;
  }*/         //                                          Wrong Answer if not delete this paragraph
  point e=vec((a.x+b.x)/2.0,(a.y+b.y)/2.0);
  vec u=rotate(b-a);
  point d=vec((a.x+c.x)/2.0,(a.y+c.y)/2.0);
  vec v=rotate(c-a);
  o=llcross(e,u,d,v);
  r=dist(o,a);
}

void mincircle(int n,point &o,double &r)
{
  o=p[1];
  r=0;
  for (int i=2;i<=n;i++)
    if (dcmp((dist(p[i],o)-r))>0)
    {
      o=p[i];
      r=0;
      for (int j=1;j<i;j++)
        if (dcmp((dist(p[j],o)-r))>0)
        {    
          o=vec((p[j].x+p[i].x)/2.0,(p[j].y+p[i].y)/2.0);     //  Wrong Answer if repalce this line with
                                                              //  o=vec((p[j].x+o.x)/2.0,(p[j].y+o.y)/2.0);
          r=dist(p[j],o);
          for (int k=1;k<j;k++)
            if (dcmp((dist(p[k],o)-r))>0)
              find_circle(p[i],p[j],p[k],o,r);
        }
    }
}

int main()
{
  freopen("3007.in","r",stdin);
  freopen("3007.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(p,0,sizeof(p));
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    point o;double r;
    mincircle(n,o,r);
    printf("%.2lf %.2lf %.2lf\n",o.x,o.y,r);
    scanf("%d",&n);
  }
  return 0;
}
