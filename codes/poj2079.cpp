#include<cstdio>
#include<cstdlib>
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
int dcmp(double a){if (fabs(a)<0) return 0;return a<0?-1:1;}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}

point p[50006],poly[50006];
int n;

int find_poly(int n)
{
  int m=0;
  sort(poly+1,poly+n+1,cmp);
  for (int i=1;i<=n;i++)
  {
    while(m>1&&dcmp(cross(poly[i]-p[m-2],p[m-1]-p[m-2]))>=0)m--;
    p[m++]=poly[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&dcmp(cross(poly[i]-p[m-2],p[m-1]-p[m-2]))>=0)m--;
    p[m++]=poly[i];
  }
  if (n>1) m--;
  return m;
}

int main()
{
  freopen("2079.in","r",stdin);
  freopen("2079.out","w",stdout);
  int m,i,j,k;
  scanf("%d",&n);
  while(n!=-1)
  {
    memset(p,0,sizeof(p));
    memset(poly,0,sizeof(poly));
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&poly[i].x,&poly[i].y);
    if (n<3)
    {
      printf("0.00\n");
      scanf("%d",&n);
      continue;
    }
    else if (n==3)
    {
      printf("%.2lf\n",fabs(cross(poly[3]-poly[2],poly[1]-poly[2]))/2.0);
      scanf("%d",&n); 
      continue;
    }
    m=find_poly(n);
    if (m==3)
    {
      printf("%.2lf\n",fabs(cross(p[2]-p[1],p[0]-p[1]))/2.0);
      scanf("%d",&n);
      continue;
    }
    double ans=-1.0;
    for (i=0;i<m;i++)
    {
      j=(i+1)%m;
      k=(j+1)%m;
      while(j!=i)
      {
        while(dcmp(cross(p[(k+1)%m]-p[j],p[i]-p[j])-cross(p[k]-p[j],p[i]-p[j]))>=0) 
          k=(k+1)%m;
        ans=max(ans,fabs(cross(p[k]-p[j],p[i]-p[j])));
        j=(j+1)%m;
      }
    }
    printf("%.2lf\n",ans/2.0);
    scanf("%d",&n);
  }
  return 0;
}
