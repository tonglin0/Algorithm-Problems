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
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}

point p[1004],poly[1004];
int n;

void find_poly(int n)
{
  int m=0;
  sort(poly+1,poly+n+1,cmp);
  for (int i=1;i<=n;i++)
  {
    while(m>1&&dcmp(cross(poly[i]-p[m-2],p[m-1]-p[m-2]))>0) m--;
    p[m++]=poly[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&dcmp(cross(poly[i]-p[m-2],p[m-1]-p[m-2]))>0) m--;
    p[m++]=poly[i];
  }
}

int main()
{
  freopen("1228.in","r",stdin);
  freopen("1228.out","w",stdout);
  int i,j,m,T;
  scanf("%d",&T);
  while(T--)
  {
    memset(p,0,sizeof(p));
    memset(poly,0,sizeof(poly));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&poly[i].x,&poly[i].y);
    find_poly(n);
    bool flag=true;
    for (i=0;i<n;i++)
    {
      int d1=dcmp(cross(p[(i+1)%n]-p[i],p[(i+2)%n]-p[(i+1)%n]));
      int d2=dcmp(cross(p[(i+2)%n]-p[(i+1)%n],p[(i+3)%n]-p[(i+2)%n]));
      if (d1>0&&d2>0)
      {
        flag=false;
        break;
      }
    }
    if (n<6) flag=false;
    if (flag)
      printf("YES\n");
    else 
      printf("NO\n");
  }
  return 0;
}
