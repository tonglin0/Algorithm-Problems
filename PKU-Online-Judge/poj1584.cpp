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
bool cmp(point a,point b){if (a.x!=b.x)return a.x<b.x;return a.y<b.y;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double psdist(point p,point a,point b){return fabs(cross(p-a,b-a)/dist(a,b));}

point p[10003],poly[10003];
int n;

int find_poly(int n)
{
  int m=0;
  sort(p+1,p+n+1,cmp);
  for (int i=1;i<=n;i++)
  {
    while(m>1&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>0) m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))>0)m--;
    poly[m++]=p[i];
  }
  if (n>1) m--;
  return m;
}

int main()
{
  freopen("1584.in","r",stdin);
  freopen("1584.out","w",stdout);
  int m,i,j,k;
  double cr,cx,cy;
  scanf("%d",&n);
  while(n>=3)
  {
    memset(p,0,sizeof(p));
    memset(poly,0,sizeof(poly));
    scanf("%lf%lf%lf",&cr,&cx,&cy);
    point c;
    c.x=cx;c.y=cy;
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    m=find_poly(n);
    if (m!=n)
      printf("HOLE IS ILL-FORMED\n");
    else
    {
      bool flag=true;
      int wn=0;
      for (i=0;i<n;i++)
      {
        double s1=cross(poly[i]-c,poly[(i+1)%n]-c);
        int d1=dcmp(poly[i].y-c.y);
        int d2=dcmp(poly[(i+1)%n].y-c.y);
        if (dcmp(s1)>=0&&d1<=0&&d2>0) wn++;
        if (dcmp(s1)<=0&&d1>=0&&d2<0) wn--;
      }
      if (wn%2==0)
        flag=false;
      else
      {
        for (i=0;i<n;i++)
          if (dcmp(cr-psdist(c,poly[i],poly[(i+1)%n]))>0)
          {
            flag=false;
            break;
          }
      }
      if (flag)
        printf("PEG WILL FIT\n");
      else
        printf("PEG WILL NOT FIT\n");
    }
    scanf("%d",&n);           
  }
  return 0;
}
