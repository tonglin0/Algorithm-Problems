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
       point p;point v;double ang;
       line(){}
       line(point p,vec v):p(p),v(v){}
       };
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool onleft(point a,line l){return dcmp(cross(l.v,a-l.p))>0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool cmp(line a,line b){return a.ang<b.ang;}

line l[55],q[155];
point p[55];
int n;

int halfplane()
{
  sort(l+1,l+1+n,cmp);
  int f,la;
  q[f=la=0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<la&&!onleft(p[la-1],l[i]))la--;
    while(f<la&&!onleft(p[f],l[i]))f++;
    q[++la]=l[i];
    if (dcmp(cross(l[i].v,q[la-1].v))==0)
    {
      la--;
      if (onleft(l[i].p,q[la]))
        q[la]=l[i];
    }
    if (la>f) 
      p[la-1]=llcross(q[la-1].p,q[la-1].v,q[la].p,q[la].v);
  }
  while(la>f&&!onleft(p[la-1],q[f]))la--;
  if (la-f<=1) return 0;
  return la-f+1;
}

int main()
{
  //freopen("3130.in","r",stdin);
  //freopen("3130.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(l,0,sizeof(l));
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));
    point a,b,c;
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf",&a.x,&a.y);
      if (i==1){c=a;b=a;continue;}
      l[i-1].p=b;
      l[i-1].v=a-b;
      b=a;
    }
    l[n].p=a;
    l[n].v=c-a;
    for (i=1;i<=n;i++)
      l[i].ang=atan2(l[i].v.y,l[i].v.x);
    m=halfplane();
    if (m==0)
      printf("0\n");
    else
      printf("1\n");
    scanf("%d",&n);
  }
  return 0;
}
