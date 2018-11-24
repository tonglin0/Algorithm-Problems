#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}

bool between(point a,point b,point c)
{
  if (fabs(b.x-c.x)>fabs(b.y-c.y))
    return a.x>=min(b.x,c.x)&&a.x<=max(b.x,c.x);
  else
    return a.y>=min(b.y,c.y)&&a.y<=max(b.y,c.y);
}

bool segcross(point a,point b,point c,point d)
{
  double s1,s2,s3,s4;
  int d1,d2,d3,d4;
  d1=dcmp(s1=cross(b-a,c-a));
  d2=dcmp(s2=cross(b-a,d-a));
  d3=dcmp(s3=cross(d-c,a-c));
  d4=dcmp(s4=cross(d-c,b-c));
  if (d1*d2<0&&d3*d4<0) return true;
  if (d1==0&&between(c,a,b)||
      d2==0&&between(d,a,b)||
      d3==0&&between(a,c,d)||
      d4==0&&between(b,c,d)) 
  return true;
  return false;
}

bool istop[100003];
point l[100003][2];

int main()
{
  //freopen("2653.in","r",stdin);
  //freopen("2653.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(l,0,sizeof(l));
    memset(istop,1,sizeof(istop));
    for (i=1;i<=n;i++)
    {  point a,b;scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y); l[i][0]=a;
      l[i][1]=b;
    }       
    for (i=1;i<=n;i++)
    {
      //point a,b;
      //scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
      //istop[i]=true;
      //bool ff=true;
      for (j=i+1;j<=n;j++)
        if (segcross(l[j][0],l[j][1],l[i][0],l[i][1]))
          {istop[i]=false;break;}
    }
    printf("Top sticks: ");
    bool flag=true;
    for (i=1;i<=n;i++)
      if (istop[i])
        if (flag)
        {
          printf("%d",i);
          flag=false;
        }
        else
          printf(", %d",i);
    printf(".\n");
    scanf("%d",&n);
  }
  return 0;
}
