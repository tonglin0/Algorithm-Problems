#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{int x,y;point(int x=0,int y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator - (vec a,int b){return vec(a.x*b,a.y*b);}
int dcmp(int a){if (abs(a)<eps) return 0;return a<0?-1:1;}
int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
int dist(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}

point poly[50004],p[50004];
int n;

int find_polyhull()
{
  int m=0;
  sort(poly+1,poly+1+n,cmp);
  for (int i=1;i<=n;i++)
  {
    while(m>1&&cross(p[m-1]-p[m-2],poly[i]-p[m-2])<=0) m--;
    p[m++]=poly[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&cross(p[m-1]-p[m-2],poly[i]-p[m-2])<=0) m--;
    p[m++]=poly[i];
  }
  if (m>1) m--;
  return m;
}

int rotating_caliper()
{
  int q=1,ans=0;
  for (int i=0;i<n;i++)
  {
    while(cross(p[q+1]-p[i+1],p[i]-p[i+1])>cross(p[q]-p[i+1],p[i]-p[i+1]))
      q=(q+1)%n;
    ans=max(ans,max(dist(p[i],p[q]),dist(p[i+1],p[q+1])));
  }
  return ans;
}

int main()
{
  //freopen("2187.in","r",stdin);
  //freopen("2187.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  memset(poly,0,sizeof(poly));
  memset(p,0,sizeof(p));
  for (i=1;i<=n;i++)
    scanf("%d%d",&poly[i].x,&poly[i].y);
  n=find_polyhull();
  int ans=rotating_caliper();
  printf("%d\n",ans);
  return 0;
}
