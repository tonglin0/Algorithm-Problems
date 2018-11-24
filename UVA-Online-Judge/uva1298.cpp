#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-17
#define M 10000.0
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
	line(point p,vec v):p(p),v(v){}
};
bool onleft(point p,line l){return dcmp(cross(l.v,p-l.p))>0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool cmp(line a,line b){return a.ang<b.ang;}

double u[205],v[205],w[205];
line l[205],q[205];
point p[205],poly[205];

int halfplane(int n)
{
  sort(l+1,l+n+1,cmp);
  int f=0,r=0;
  q[0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i]))
      r--;
    while(f<r&&!onleft(p[f],l[i]))
      f++;
    q[++r]=l[i];
    if (dcmp(cross(l[i].v,q[r-1].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
	}
	if (f<r)
	  p[r-1]=llcross(q[r-1].p,q[r-1].v,q[r].p,q[r].v);
  }
  while(f<r&&!onleft(p[r-1],q[f]))
    r--;
  if (r-f<=1)
    return 0;
  p[r]=llcross(q[r].p,q[r].v,q[f].p,q[f].v);
  int m=0;
  for (int i=f;i<=r;i++)
    poly[m++]=p[i];
  return m;
}

int main()
{
  freopen("1298.in","r",stdin);
  freopen("1298.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    for (i=1;i<=n;i++)
      scanf("%lf%lf%lf",&u[i],&v[i],&w[i]);
    for (i=1;i<=n;i++)
    {
      bool ok=true;
      for (j=1;j<=n;j++)
      {
        if (i==j)
          continue;
        if (dcmp(u[j]-u[i])>=0&&dcmp(v[j]-v[i])>=0&&dcmp(w[j]-w[i])>=0)
        {
          ok=false;
          break;
		}
	  }
	  if (!ok)
	  {
	    printf("No\n");
	    continue;
	  }
	  int top=0;
	  line t;
	  t=line(vec(0.0,0.0),vec(1.0,0.0));
	  l[++top]=t;
	  t=line(vec(1.0,0.0),vec(-1.0,1.0));
	  l[++top]=t;
	  t=line(vec(0.0,1.0),vec(0.0,-1.0));
	  l[++top]=t;
	  for(j=1;j<=n;j++)
	  {
        if (i==j)
          continue;
        if (dcmp(u[i]-u[j])>=0&&dcmp(v[i]-v[j])>=0&&dcmp(w[i]-w[j])>=0)
          continue;
        double a=M/w[i]+M/u[j]-M/u[i]-M/w[j];
        double b=M/w[i]+M/v[j]-M/v[i]-M/w[j];
        vec tmpv=vec(b,-a);
        double c=-(M/w[j]-M/w[i])/b;
        double dd=-(M/w[j]-M/w[i])/a;
        if (fabs(c)>fabs(dd))
          l[++top]=line(vec(0.0,c),tmpv);
        else
          l[++top]=line(vec(dd,0.0),tmpv);
	  }
	  for (j=1;j<=top;j++)
	    l[j].ang=atan2(l[j].v.y,l[j].v.x);
	  m=halfplane(top);
	  if (m==0)
	  {
	    printf("No\n");
	    continue;
	  }
	  double s=0;
	  for (j=1;j<m-1;j++)
	    s+=cross(poly[j]-poly[0],poly[j+1]-poly[0]);
	  if (fabs(s)<eps)
	    printf("No\n");
	  else
	    printf("Yes\n");
	}
  }
  return 0;
}
