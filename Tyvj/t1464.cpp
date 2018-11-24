#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define MN 100040
#define ll long long
using namespace std;

struct point{ll x,y;point(ll x=0,ll y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
//vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
point p[MN],poly[MN];
//int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
bool cmp(point a,point b){if (a.x-b.x!=0) return a.x<b.x;return a.y<b.y;}
ll cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
ll dist(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
//double max(double a,double b){return a>b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}

int find_poly(int n)
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&(cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])>=0)) m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])>=0) m--;
    poly[m++]=p[i];
  }
  if (n>1) m--;
  return m;
}

int main()
{
  freopen("1464.in","r",stdin);
  freopen("1464.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%lld%lld",&p[i].x,&p[i].y);
  n=find_poly(n);
  int q=1;
  ll ans=0;
  for (i=0;i<n;i++)
  {
    while(cross(poly[(i+1)%n]-poly[i],poly[(q+1)%n]-poly[i])>cross(poly[(i+1)%n]-poly[i],poly[q]-poly[i]))
      q=(q+1)%n;
    ans=max(ans,max(dist(poly[i],poly[q]),dist(poly[(i+1)%n],poly[(q+1)%n])));
  }
  printf("%lld\n",ans);
  //printf("%d\n",(int)(ans+0.5));
  return 0;
}
