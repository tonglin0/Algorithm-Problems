#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define MN 50009
#define llu unsigned long long
using namespace std;

struct point{int id;double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
struct line{
	int id;
	point p;vec v;
	line(){}
	line(point p,vec v):p(p),v(v){}
};
bool onleft(point p,line l){return dcmp(cross(l.v,p-l.p))>0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool vis[MN];

point p[MN];
point a[MN];
line l[MN],q[MN];
bool cmp(point a,point b){return a.x<b.x;}

void halfplane(int n)
{
  int f=0,r=0;
  q[0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i])) r--;
    //while(f<r&&!onleft(p[f],l[i])) f++;
    q[++r]=l[i];
    if (dcmp(cross(l[i].v,q[r-1].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
	}
	if (f<r) p[r-1]=llcross(q[r-1].p,q[r-1].v,q[r].p,q[r].v);
  }
  memset(vis,0,sizeof(vis));
  //while(f<r&&!onleft(p[r-1],q[f])) r--;
  for (int i=f;i<=r;i++)
    vis[q[i].id]=true;
}

int main()
{
  freopen("1007.in","r",stdin);
  freopen("1007.out","w",stdout);
  int ca,n,m,i,j,k,ii=0;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%lf%lf",&a[i].x,&a[i].y),a[i].id=i;
  sort(a+1,a+n+1,cmp);
  for (i=1;i<=n;i++)
  {
    line t;
    t.p=vec(0.0,a[i].y);
    t.v=vec(1.0,a[i].x);
    t.id=a[i].id;
    l[i]=t;
  }
  halfplane(n);
  for (i=1;i<=n;i++)
    if (vis[i])
      printf("%d ",i);
  return 0;
}

