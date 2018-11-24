#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){} };
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
double max(double a,double b){return a>b?a:b;}

point p[200][2];
vec l[200][2];
int n;

bool check(point a,point b)
{
  double y1=a.y,x1=a.x,x2=b.x,y2=b.y;
  if (fabs(x1-x2)==0) return false;
  double y=(y1-y2)*(p[1][0].x-x1)/(x1-x2)+y1;
  if (dcmp(y-p[1][0].y)<=0&&dcmp(y-p[1][1].y)>=0)
    return true;
  else
    return false;
}

bool check2(point a,point b)
{
  double y1=a.y,x1=a.x,x2=b.x,y2=b.y;
  if (fabs(x1-x2)==0) return false;
  double y=(y1-y2)*(p[n][0].x-x1)/(x1-x2)+y1;
  if (dcmp(y-p[n][0].y)<=0&&dcmp(y-p[n][1].y)>=0)
    return true;
  else
    return false;
}

double angle(vec a)
{
  return atan2(a.y,a.x);
}

bool slcross(point a,point b,point c,point d,point &po)
{
  double s1,s2;
  int d1,d2;
  d1=dcmp(s1=cross(d-c,a-c));
  d2=dcmp(s2=cross(d-c,b-c));
  if (d1*d2<0)
  {
    vec v=b-a;
    vec w=d-c;
    vec u=a-c;
    po=a+v*(cross(w,u)/cross(v,w));
    return true;    
  }
  else
  {  
    double an1,an2;
    if (d.x>c.x)
      an1=angle(d-c);
    else
      an1=angle(c-d);
    an2=angle(b-a);
    if (d1==0&&dcmp(an1-an2)>0)
    {
      po=vec(a.x,a.y);
      return true;
    }
    return false;
  }
}

bool slcross2(point a,point b,point c,point d,point &po)
{
  double s1,s2;
  int d1,d2;
  d1=dcmp(s1=cross(d-c,a-c));
  d2=dcmp(s2=cross(d-c,b-c));
  if (d1*d2<0)
  {
    vec v=b-a;
    vec w=d-c;
    vec u=a-c;
    po=a+v*(cross(w,u)/cross(v,w));
    return true;    
  }
  else
  {  
    double an1,an2;
    if (d.x>c.x)
      an1=angle(d-c);
    else
      an1=angle(c-d);
    an2=angle(b-a);
    if (d1==0&&dcmp(an1-an2)<0)
    {
      po=vec(a.x,a.y);
      return true;
    }
    return false;
  }
}


int main()
{
  //freopen("1039.in","r",stdin);
  //freopen("1039.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(p,0,sizeof(p));
    memset(l,0,sizeof(l));
    double x,y;
    scanf("%lf%lf",&x,&y);
    p[1][0]=vec(x,y);
    p[1][1]=vec(x,y-1);
    for (i=2;i<=n;i++)
    {
      scanf("%lf%lf",&p[i][0].x,&p[i][0].y);
      p[i][1]=vec(p[i][0].x,p[i][0].y-1);
      vec a=p[i-1][0];
      vec b=p[i][0];
      l[2*(i-1)-1][0]=a;
      l[2*(i-1)-1][1]=b;
      a=p[i-1][1];
      b=p[i][1];
      l[2*(i-1)][0]=a;
      l[2*(i-1)][1]=b;
    }
    double ans=-1e9;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
        point a=p[i][0];
        point b=p[j][1];
        if (check(a,b))
        {
          bool flag=true;
          point po;
          for (k=1;k<=2*(n-1);k++)
          {
          if (k&1==1)
          {
            if (slcross(l[k][0],l[k][1],a,b,po))
            {
              ans=max(ans,po.x);
              flag=false;
              break;
            }
          }
          else
          {
            if (slcross2(l[k][0],l[k][1],a,b,po))
            {
              ans=max(ans,po.x);
              flag=false;
              break;
            }
          }
          }
          if (flag&&check2(a,b))
            ans=1e9;
        }
      }
    if (dcmp(fabs(ans-1e9))==0)
      printf("Through all the pipe.\n");
    else
      printf("%.2lf\n",ans);
    scanf("%d",&n);
  }
  return 0;
}
