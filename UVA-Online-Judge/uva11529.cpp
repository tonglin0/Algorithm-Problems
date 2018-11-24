#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-8
#define lint long long
#define PI acos(-1.0)
using namespace std;

lint c2[1209];
lint c3[1209];

struct point{double x,y,ang;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){return a.ang<b.ang;}

point p[1209];
point q[2409];

int main()
{
  freopen("11529.in","r",stdin);
  freopen("11529.out","w",stdout);
  lint ii=0,n,i,j,k,m;
  c2[0]=c2[1]=0;
  c2[2]=1;
  for (i=3;i<=1200;i++)
    c2[i]=i*(i-1)/2;
  c3[0]=c3[1]=c3[2]=0;
  for (i=3;i<=1200;i++)
    c3[i]=i*(i-1)/2*(i-2)/3;
  while(scanf("%lld",&n)==1)
  {
    if (n==0) break;
    printf("City %lld: ",++ii);
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
    lint ans=0;
    for (i=1;i<=n;i++)
    {
      lint top=0;
	  for (j=1;j<=n;j++)
      {
        if (i==j) continue;
        q[top].x=p[j].x;
        q[top].y=p[j].y;
        q[top].ang=atan2((p[j]-p[i]).y,(p[j]-p[i]).x);
        if (q[top].ang<0)
          q[top].ang+=2*PI;
        top++;
	  }
	  sort(q,q+n-1,cmp);
	  lint k=1;
	  lint s=c3[n-1];
	  for (j=0;j<n-1;j++)
	  {
	    q[j+n-1]=q[j];
	    q[j+n-1].ang+=2*PI;
	  }
	  for (j=0;j<=n-2;j++)
	  {
	    while(dcmp(q[k].ang-q[j].ang-PI)<0)
	      k++;
	    s-=c2[k-j-1];
	  }
	  ans+=s;
	}
	printf("%.2lf\n",(double)ans/c3[n]);
  }
  return 0;
}
