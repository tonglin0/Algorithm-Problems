#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define eps 1e-8
using namespace std;

struct point{int x,y;point(int x=0,int y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,int b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}

int gcd(int a,int b)
{
  int t;
  while(b!=0)
  {
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}

int main()
{
  //freopen("1265.in","r",stdin);
  //freopen("1265.out","w",stdout);
  int n,i,j,k,m,ii,T;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    scanf("%d",&n);
    int L=0,E=0;
    int s=0;
    point a=vec(0,0);
    int x,y;
    scanf("%d%d",&x,&y);
    point b=vec(a.x+x,a.y+y);
    L+=gcd(abs(x),abs(y));
    for (i=2;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      L+=gcd(abs(x),abs(y));
      a=vec(b.x+x,b.y+y);
      s+=cross(b,a);
      b=a;
    }
    printf("Scenario #%d:\n",ii);
    E=s-L+2;
    E=E>>1;
    double S=(double)s;
    S=S/2.0;
    printf("%d %d %.1lf\n\n",E,L,S);
  }
  return 0;
}
