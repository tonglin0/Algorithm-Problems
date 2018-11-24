#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
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
       point p;vec v;double ang;
       line(){}
       line(point p,vec v):p(p),v(v){}};
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dot(a,a));}
vec normal(vec a){double l=length(a);return vec(-a.y/l,a.x/l);}
vec oppo(vec v){return vec(-v.x,-v.y);}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}

point p[400],q[400];
char ch[100];
bool flag=false;
int n;

void cut(point u,vec v,int &n)
{
  int m=0;
  memset(q,0,sizeof(q));
  for (int i=0;i<n;i++)
  {
    int d1=dcmp(cross(p[i]-u,v));
    int d2=dcmp(cross(p[(i+1)%n]-u,v));
    if (d1<=0)
      q[m++]=p[i];
    if (d1*d2<0)
    {
      point c=llcross(p[i],p[(i+1)%n]-p[i],u,v);
      q[m++]=c;
    }
  }
  memset(p,0,sizeof(p));
  for (int i=0;i<m;i++)
    p[i]=q[i];
  n=m;
}

int main()
{
  freopen("2540.in","r",stdin);
  freopen("2540.out","w",stdout);
  int i,j,k,m;
  memset(p,0,sizeof(p));
  p[0].x=0;p[0].y=0;
  p[1].x=10;p[1].y=0;
  p[2].x=10;p[2].y=10;
  p[3].x=0;p[3].y=10;
  n=4;
  point a,b;
  a=vec(0,0);
  while(scanf("%lf%lf",&b.x,&b.y)==2)
  {
    memset(ch,0,sizeof(ch));
    scanf("%s",ch);
    if (flag)
    {
      printf("0.00\n");
      continue;
    }
    if (ch[0]=='S')
    {
      flag=true;
      printf("0.00\n");
      continue;
    }
    vec v=normal(b-a);
    if (ch[0]=='H')
      v=oppo(v);
    point u=vec((a.x+b.x)/2,(a.y+b.y)/2);
    cut(u,v,n);
    double ans=0;
    for (i=1;i<n;i++)
      ans+=cross(p[i]-p[0],p[(i+1)%n]-p[0]);
    ans=fabs(ans)/2;
    if (dcmp(ans)==0)
    {
      printf("0.00\n");
      flag=true;
      continue;
    }
    printf("%.2lf\n",ans);
    a=b;
  }
  return 0;
}
