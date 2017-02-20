#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;bool c;};
typedef point vec;
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){if (a.x!=b.x)return a.x<b.x;return a.y<b.y;}
bool cmpy(point a,point b){return a.y<b.y;}
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double min(double a,double b){return a<b?a:b;}

point p[200005],t[2000005];

double mindispoint(int l,int r)
{
  double s=1e12;
  if (l==r) return s;
  if (l+1==r) {
    if (p[l].c!=p[r].c)
      return dist(p[l],p[r]);
    else 
      return s;}
  int mid=(l+r)>>1;
  s=min(s,mindispoint(l,mid));
  s=min(s,mindispoint(mid+1,r));
  int k=0;
  for (int i=l;i<=r;i++)
    if (dcmp(fabs(p[i].x-p[mid].x)-s+eps)<0)
      t[k++]=p[i];
  sort(t,t+k,cmpy);
  for (int i=0;i<k;i++)
    for (int j=i+1;j<k&&dcmp(t[j].y-t[i].y-s+eps)<0;j++)
      if (t[j].c!=t[i].c)
        s=min(s,dist(t[j],t[i]));
  return s;
}

int main()
{
  freopen("3714.in","r",stdin);
  freopen("3714.out","w",stdout);
  int T,n,i,j,k,m;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    for (i=n+1;i<=n+n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    for (i=1;i<=n;i++)
      p[i].c=true;
    for (i=n+1;i<=n+n;i++)
      p[i].c=false;
    sort(p+1,p+n+n+1,cmp);
    n=n+n;
    printf("%.3lf\n",mindispoint(1,n));
  }
  return 0;
}
