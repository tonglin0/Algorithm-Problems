#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define PI acos(-1.0)
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
int dcmp(double a){if (fabs(a)<eps) return 0;return a>0?1:-1;}
bool cmp(point a,point b){if (dcmp(a.x-b.x)!=0) return a.x<b.x;return a.y<b.y;}

point p[2500];
point poly[2500];

int find_poly(int n)
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])>=0)
      m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])>=0)
      m--;
    poly[m++]=p[i];
  }
  if (n>1)
    m--;
  return m;
}

vec rotate(vec v,double ang)
{
  double x=v.x,y=v.y;
  return vec(x*cos(ang)-y*sin(ang),x*sin(ang)+y*cos(ang));
}

int main()
{
  freopen("10652.in","r",stdin);
  freopen("10652.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    int top=0;
    double s1=0;
    for (i=1;i<=n;i++)
    {
      double x,y,w,h,thita;
      scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&thita);
      double ang=-thita/180*PI;
      point o=vec(x,y);
	  p[++top]=o+rotate(vec(w/2,h/2),ang);
	  p[++top]=o+rotate(vec(w/2,-h/2),ang);
	  p[++top]=o+rotate(vec(-w/2,h/2),ang);
	  p[++top]=o+rotate(vec(-w/2,-h/2),ang);
	  s1+=w*h;
	}
	m=find_poly(top);
	double ans=0;
	for (i=1;i<m;i++)
	  ans+=cross(poly[i]-poly[0],poly[(i+1)%m]-poly[0]);
	ans=fabs(ans)/2.0;
	printf("%.1lf %\n",100*s1/ans);
  }
  return 0;
}
