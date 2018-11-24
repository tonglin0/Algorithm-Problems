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

point p[2005];
point poly[2005];
bool cmp(point a,point b){if (dcmp(a.x-b.x)!=0) return dcmp(a.x-b.x)<0;return dcmp(a.y-b.y)<0;}

int getpoly(int n)
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>=0)
      m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>=0)
      m--;
    poly[m++]=p[i];
  }
  if (n>1)
    m--;
  return m;
}

int main()
{
  freopen("1069.in","r",stdin);
  freopen("1069.out","w",stdout);
  int n,m,i,j,k;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
  m=getpoly(n);
  n=m;
  double ans=0;
  for (i=0;i<n;i++)
  {
    int l=(i+1)%n,r=(i+3)%n;
    j=(i+2)%n;
    for (;j<n;j++)
    {
      while(dcmp(fabs(cross(poly[(l+1)%n]-poly[i],poly[j]-poly[i]))-fabs(cross(poly[l]-poly[i],poly[j]-poly[i]))>0))
        l=(l+1)%n;
      while(dcmp(fabs(cross(poly[(r+1)%n]-poly[i],poly[j]-poly[i]))-fabs(cross(poly[r]-poly[i],poly[j]-poly[i]))>0))
        r=(r+1)%n;
      ans=max(ans,fabs(cross(poly[l]-poly[i],poly[j]-poly[i]))+fabs(cross(poly[r]-poly[i],poly[j]-poly[i])));
	}
  }
  printf("%.3lf\n",ans/2.0);
  return 0;
}

