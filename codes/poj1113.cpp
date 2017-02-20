#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#define eps 1e-8
#define PI acos(-1.0)
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp(point a,point b){if (dcmp(fabs(a.x-b.x))!=0) return dcmp(a.x-b.x)<0;return dcmp(a.y-b.y)<0;} 

point ch[1003],p[1003];
int n;

int find_poly(point* p)
{
  sort(p,p+n,cmp);
  int m=0;
  for (int i=0;i<n;i++)
  {
    while(m>1&&cross(ch[m-2]-ch[m-1],ch[m-2]-p[i])<=0) m--;
    ch[m++]=p[i];
  }
  int k=m;
  for (int i=n-2;i>=0;i--)
  {
    while(m>k&&cross(ch[m-2]-ch[m-1],ch[m-2]-p[i])<=0) m--;
    ch[m++]=p[i];
  }
  if (n>1) m--;
  return m;
}

int main()
{
  int i,r,j,m,k;
  scanf("%d%d",&n,&r);
  memset(ch,0,sizeof(ch));
  memset(p,0,sizeof(p));
  for (i=0;i<n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
  m=find_poly(p);
  double ans=PI*2*r;
  for (i=0;i<m;i++)
    ans+=dist(ch[i],ch[(i+1)%m]);
  printf("%d\n",(int)floor(ans+0.5));
  return 0;
}
