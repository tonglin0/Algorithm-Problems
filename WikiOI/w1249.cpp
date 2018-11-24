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
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}

point p[205];

int main()
{
  freopen("1249.in","r",stdin);
  freopen("1249.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  memset(p,0,sizeof(p));
  for (i=0;i<n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
  double ans=0;
  for (i=1;i<n;i++)
    ans+=cross(p[i]-p[0],p[(i+1)%n]-p[0]);
  int d=(int)(fabs(ans)/2);
  printf("%d\n",d);
  return 0;
}
