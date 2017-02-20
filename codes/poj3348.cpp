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
vec operator * (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,int b){return vec(a.x*b,a.y*b);}
int dcmp(int a){if (abs(a)<eps) return 0;return a<0?-1:1;}
int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
int n;

point p[10005],poly[10005];

bool cmp(point a,point b)
{
  if (a.x!=b.x) return a.x<b.x;
  return a.y<b.y;
}

int find_poly()
{
  sort(poly+1,poly+n+1,cmp);
  int m=0;
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

int main()
{
  //freopen("3348.in","r",stdin);
  //freopen("3348.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  memset(p,0,sizeof(p));
  memset(poly,0,sizeof(poly));
  for (i=1;i<=n;i++)
    scanf("%d%d",&poly[i].x,&poly[i].y);
  m=find_poly();
  //printf("%d\n",m);
  int ans=0;
  for (i=1;i<m;i++)
    ans+=cross(p[i-1],p[i]);
  ans+=cross(p[m-1],p[0]);
  //printf("%d\n",ans/2);
  printf("%d\n",abs(ans)/100);
  return 0;
}

