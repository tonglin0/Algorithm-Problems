#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-13
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){if (dcmp(a.x-b.x)!=0) return a.x<b.x;return a.y<b.y;}

point p[100003],poly[100004];

int find_poly(int n)
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])<=0) m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])<=0) m--;
    poly[m++]=p[i];
  }
  if (n>1) m--;
  return m;
}

int main()
{
  freopen("1462.in","r",stdin);
  freopen("1462.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
  n=find_poly(n);
  for (i=0;i<n;i++)
    printf("%.4lf %.4lf\n",poly[i].x,poly[i].y);
  return 0;
}
