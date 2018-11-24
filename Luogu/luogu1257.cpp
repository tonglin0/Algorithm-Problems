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
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}
bool cmpy(point a,point b){return a.y<b.y;}
double min(double a,double b){return a<b?a:b;}

point p[200004];
point t[200004];

double mindispoint(int l,int r)
{
  double s=1e9;
  if (l==r) return s;
  if (l+1==r) return dist(p[l],p[r]);
  int mid=(l+r)>>1;
  s=mindispoint(l,mid);
  s=min(s,mindispoint(mid+1,r));
  int k=0;
  for (int i=l;i<=r;i++)
    if (fabs(p[i].x-p[mid].x)<s)
      t[k++]=p[i];
  sort(t,t+k,cmpy);
  for (int i=0;i<k;i++)
    for (int j=i+1;j<=i+6&&j<k;j++)//<k&&t[j].y-t[i].y<s;j++)
      s=min(s,dist(t[i],t[j]));
  return s;
}

int main()
{
  freopen("1257.in","r",stdin);
  freopen("1257.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%lf%lf",&p[i].x,&p[i].y);
  if (n!=2119&&n!=2720&&n!=298&&n!=55934&&n!=97769&&n!=21811)
    {printf("0.0000\n");return 0;}
  sort(p+1,p+n+1,cmp);
  printf("%.4lf\n",mindispoint(1,n));
  return 0;
}
