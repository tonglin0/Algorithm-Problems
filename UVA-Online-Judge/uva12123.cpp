#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define PI acos(-1.0)
using namespace std;

struct point{int x,y;double ang;point(int x=0,int y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
int dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
bool cmp(point a,point b){return a.ang<b.ang;}

point p[5909],q[5909];

int C(int n,int m)
{
  if (n<m) return 0;
  int ans=1;
  for (int i=0;i<m;i++)
    ans*=(n-i);
  for (int i=2;i<=m;i++)
    ans/=i;
  return ans;
}

int main()
{
  freopen("12123.in","r",stdin);
  freopen("12123.out","w",stdout);
  int n,i,j,k,m,ii=0;
  while(scanf("%d",&n)==1)
  {
    if (n==0) break;
    printf("Scenario %d:\n",++ii);
    for (i=1;i<=n;i++)
    {
	  scanf("%d%d",&p[i].x,&p[i].y);
	  p[i].x*=100;p[i].y*=100;
    }
    int ans=-2*C(n,3);
    for (i=1;i<=n;i++)
    {
      int top=0;
      for (j=1;j<=n;j++)
      {
        if (i==j) continue;
        top++;
        q[top]=p[j];
        q[top].ang=atan2((double)(p[j]-p[i]).y,(double)(p[j]-p[i]).x);
        if (q[top].ang<0)
          q[top].ang+=2*PI;
	  }
	  sort(q+1,q+n,cmp);
	  for (j=1;j<=n-1;j++)
	  {
	    q[j+n-1]=q[j];
	    q[j+n-1].ang+=2*PI;
	  }
	  int s=0;
	  k=2;
	  for (j=1;j<=n-1;j++)
	  {
	    while(dcmp(q[k].ang-q[j].ang-PI/2.0)<0)         // WA if change < into <=
	      k++;
	    s+=k-j-1;
	  }
	  ans+=s;
	}
	printf("There are %d sites for making valid tracks\n",ans);
  }
  return 0;
}
