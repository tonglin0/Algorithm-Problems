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
double cross(vec a,vec b){return (a.x*b.y-a.y*b.x);}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmpy(point a,point b){return a.y<b.y;}

point p[100005];
point t[100005];

double mindispoint(int l,int r)
{
  double s=1e9;
  if (l==r) return s;
  if (l+1==r) return dist(p[l],p[r]);
  int mid=(r+l)>>1;
  double dl=mindispoint(l,mid);
  double dr=mindispoint(mid+1,r);
  s=min(dl,dr);
  //memset(t,0,sizeof(t));              TLE because of this line
  int k=0;
  for (int i=l;i<=r;i++)
    if (fabs(p[i].x-p[mid].x)-s<0)
      t[k++]=p[i];
  sort(t,t+k,cmpy);
  for (int i=0;i<k;i++)
    for (int j=i+1;j<k&&t[j].y-t[i].y-s<0;j++)
      s=min(s,dist(t[i],t[j]));
  return s;
}

int main()
{
  freopen("2107.in","r",stdin);
  freopen("2107.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(p,0,sizeof(p));
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,cmp);
    printf("%.2lf\n",mindispoint(1,n)/2.0);
    scanf("%d",&n);
  }
  return 0;
} 
