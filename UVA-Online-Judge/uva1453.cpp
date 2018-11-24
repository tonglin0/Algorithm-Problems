#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MN 400100
using namespace std;

struct point{int x,y;point(int x=0,int y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,int b){return vec(a.x*b,a.y*b);}
int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}
int dist(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

point p[MN],poly[MN];

int find_poly(int n)
{
  sort(p+1,p+n+1,cmp);
  int m=0;
  for (int i=1;i<=n;i++)
  {
    while(m>1&&cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])>=0)
      m--;
    poly[m++]=p[i];
  }
  int k=m;
  for (int i=n-1;i>=1;i--)
  {
    while(m>k&&cross(p[i]-poly[m-2],poly[m-1]-poly[m-2])>=0)
      m--;
    poly[m++]=p[i];
  }
  if (n>1)
    m--;
  return m;
}

int main()
{
  freopen("1453.in","r",stdin);
  freopen("1453.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    int top=0;
    for (i=1;i<=n;i++)
    {
      int x,y,d;
      scanf("%d%d%d",&x,&y,&d);
      p[++top]=vec(x,y);
      p[++top]=vec(x+d,y);
      p[++top]=vec(x,y+d);
      p[++top]=vec(x+d,y+d);
	}
	m=find_poly(top);
	int ans=0;
	for (i=0;i<m;i++)
	{
	  j=(i+2)%m;
	  while(cross(poly[(i+1)%m]-poly[i],poly[(j+1)%m]-poly[i])>cross(poly[(i+1)%m]-poly[i],poly[j]-poly[i]))
	    j=(j+1)%m;
	  ans=max(ans,dist(poly[i],poly[j]));
	  ans=max(ans,dist(poly[(i+1)%m],poly[(j+1)%m]));
	}
	printf("%d\n",ans);
  }
  return 0;
}
