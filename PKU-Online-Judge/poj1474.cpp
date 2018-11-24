#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
struct line{
       point p;vec v;double ang;
       line(){}
       line(point p,vec v):p(p),v(v){}
       };
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool onleft(point a,line b){return dcmp(cross(b.v,a-b.p))>=0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool cmp(line a,line b){return a.ang<b.ang;}

int n;
line l[103],q[203];
point p[104];

int halfplane()
{
  sort(l+1,l+1+n,cmp);  
  int r=0,f=0;
  q[r]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i]))r--;
    while(f<r&&!onleft(p[f],l[i]))f++;
    q[++r]=l[i];
    if (dcmp(cross(q[r-1].v,l[i].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
    }
    if (r>f) p[r-1]=llcross(q[r-1].p,q[r-1].v,q[r].p,q[r].v);
  }
  while(f<r&&!onleft(p[r-1],q[f]))r--;
  if (r-f<=1) return 0;
  return r-f+1;
  p[r]=llcross(q[f].p,q[f].v,q[r].p,q[r].v);
}

int main()
{
  //freopen("1474.in","r",stdin);
  //freopen("1474.out","w",stdout);
  int i,j,k,m,ii;
  ii=0;
  scanf("%d",&n);
  while(n)
  {
    ii++;
    memset(l,0,sizeof(l));
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));
    point a,b,c;
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf",&a.x,&a.y);
      if (i==1) {b=a;c=a;continue;}
      l[i-1].p=a;
      l[i-1].v=b-a;
      b=a;
    }
    l[n].p=c;
    l[n].v=a-c;
    for (i=1;i<=n;i++)
      l[i].ang=atan2(l[i].v.y,l[i].v.x);
    m=0;
    m=halfplane();
    if (m==0)
      printf("Floor #%d\nSurveillance is impossible.\n\n",ii);
    else
      printf("Floor #%d\nSurveillance is possible.\n\n",ii);
    scanf("%d",&n);
    //printf("%d\n",m);
  }
  return 0;
}
