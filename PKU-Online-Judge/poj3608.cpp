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
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){if (dcmp(a.x-b.x)!=0) return a.x<b.x;return a.y<b.y;}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}

point P[20500],Q[20500];
point poly[20500];

int find_poly(point *p,int n)
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))<=0) m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&dcmp(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2]))<=0) m--;
    poly[m++]=p[i];
  }
  if (n>1) m--;
  for (int i=0;i<m;i++)
    p[i]=poly[i];
  return m;
}

double psdist(point p,point a,point b)
{
  if (dcmp(dot(b-a,p-a))<=0)
    return dist(p,a);
  if (dcmp(dot(b-a,p-b))>=0)
    return dist(p,b);
  return fabs(cross(b-a,p-a)/dist(a,b));
}

double ssdist(point a,point b,point c,point d)
{
  double ans1=min(psdist(a,c,d),psdist(b,c,d));
  double ans2=min(psdist(c,a,b),psdist(d,a,b));
  return min(ans1,ans2);
}

double rc(point *P,int n,point *Q,int m)
{
  int minp,maxq;
  minp=0;
  for (int i=1;i<n;i++)
    if (dcmp(P[i].y-P[minp].y)<0)
      minp=i;
  maxq=0;
  for (int i=1;i<m;i++)
    if (dcmp(Q[i].y-Q[maxq].y)>0)
      maxq=i;
  P[n]=P[0];Q[m]=Q[0];
  double ans=dist(P[minp],Q[maxq]);
  double t;
  for (int i=0;i<n;i++)
  {
    //while(dcmp(t=cross(Q[(maxq+1)%m]-P[(minp+1)%n],P[minp]-P[(minp+1)%n])-cross(Q[maxq]-P[(minp+1)%n],P[minp]-P[(minp+1)%n]))>0)
    while(dcmp(t=cross(Q[(maxq+1)%m]-P[(minp+1)%n],P[minp]-P[(minp+1)%n])-cross(Q[maxq]-P[(minp+1)%n],P[minp]-P[(minp+1)%n]))<0) 
      maxq=(maxq+1)%m;
    if (dcmp(t)<0)
      ans=min(ans,psdist(Q[maxq],P[minp],P[(minp+1)%n]));
    else
      ans=min(ans,ssdist(P[minp],P[(minp+1)%n],Q[maxq],Q[(maxq+1)%m]));
    minp=(minp+1)%n;
  }
  return ans;
}

int main()
{
  freopen("3608.in","r",stdin);
  freopen("3608.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    if (n==0&&m==0) break;
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&P[i].x,&P[i].y);
    for (i=1;i<=m;i++)
      scanf("%lf%lf",&Q[i].x,&Q[i].y);
    n=find_poly(P,n);
    m=find_poly(Q,m);
    //for (i=0;i<n;i++)
      //printf("%.2lf %.2lf\n",P[i].x,P[i].y);
    //for (i=0;i<m;i++)
      //printf("%.2lf %.2lf\n",Q[i].x,Q[i].y);
    //return 0;
    printf("%.5lf\n",min(rc(P,n,Q,m),rc(Q,m,P,n)));
  }
  return 0;
} 
