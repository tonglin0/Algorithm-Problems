#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}

vector<point> l[1000];
double s[100];
double p[100];
bool istop[1000];
int n;

bool cover(int k)
{
  bool flag=true;
  double h=l[k][0].y;
  double a=l[k][0].x,b=l[k][1].x;
  for (int i=1;i<=n;i++)
  {
    if (i==k) continue;
    if (dcmp(l[i][0].y-h-eps)<0) continue;
    if (dcmp(l[i][0].x-a-eps)<0&&dcmp(l[i][1].x-b+eps)>0)
    {
      flag=false;
      return true;
    }
    else if (dcmp(l[i][0].x-a-eps)<0&&dcmp(l[i][1].x-a+eps)>0&&dcmp(l[i][1].x-b-eps)<0)
      a=l[i][1].x;
    else if (dcmp(l[i][0].x-a+eps)>0&&dcmp(l[i][0].x-b-eps)<0&&dcmp(l[i][1].x-b+eps)>0)
      b=l[i][0].x;
  }
  if (dcmp(b-a)==0) return true;
  return false;
}

int main()
{
  //freopen("3347.in","r",stdin);
  //freopen("3347.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(s,0,sizeof(s));
    for (i=1;i<1000;i++) l[i].clear();
    for (i=1;i<=n;i++)
    {
      double d;
      scanf("%lf",&d);
      s[i]=d;
    }
    memset(p,0,sizeof(p));
    p[1]=sqrt(2.0)/2*s[1];
    for (i=2;i<=n;i++)
    {
      double d=-1;
      for (j=1;j<i;j++)
        d=max(d,sqrt(2.0)*(min(s[i],s[j]))+p[j]);
      p[i]=d;
    }
    for (i=1;i<=n;i++)
    {
      point a,b;
      double d=sqrt(2.0)/2.0*s[i];
      a.x=p[i]-d;
      a.y=d;
      b.x=p[i]+d;
      b.y=d;
      l[i].push_back(a);
      l[i].push_back(b); 
    }/*
    for (i=1;i<=n;i++)
      printf("%.3lf %.3lf\n",l[i][0].x,l[i][1].x);
    printf("\n");
    return 0;*/
    memset(istop,1,sizeof(istop));
    for (i=1;i<=n;i++)
      if (cover(i))
        istop[i]=false;
    bool flag=true;
    for (i=1;i<=n;i++)
      if (istop[i]&&flag)
      {
        printf("%d",i);
        flag=false;
      }
      else if (istop[i])
        printf(" %d",i);
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}
