#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}

point p[1004],poly[1004];
int n;

int find_poly()
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>=0)m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>=0)m--;
    poly[m++]=p[i];
  }
  if (m>1) m--;
  return m;
}

int main()
{
  //freopen("3201.in","r",stdin);
  //freopen("3201.out","w",stdout);
  int m,i,j,k;
  memset(p,0,sizeof(p));
  memset(poly,0,sizeof(poly));
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
  m=find_poly();
  double ans=0;
  for (i=0;i<m;i++)
    ans+=dist(poly[i],poly[(i+1)%m]);
  printf("%.2lf\n",ans);
  return 0;
}
