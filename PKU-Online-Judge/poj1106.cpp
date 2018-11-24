#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define PI acos(-1.0)
using namespace std;

struct point{double x,y,ang;point(double x=0,double y=0,double ang=0):x(x),y(y),ang(ang){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}

vector<vec> l;

double dist(double x1,double y1,double x2,double y2)
{
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool cmp(vec a,vec b)
{
  return dcmp(a.ang-b.ang+eps)<0;
}

int main()
{
  //freopen("1106.in","r",stdin);
  //freopen("1106.out","w",stdout);
  int i,j,k,m,n;
  double x,y,r;
  scanf("%lf%lf%lf",&x,&y,&r);
  while(r>0)
  {
    scanf("%d",&n);
    l.clear();
    r=r*r;
    for (i=1;i<=n;i++)
    {
      double x1,y1;
      scanf("%lf%lf",&x1,&y1);
      if (dcmp(dist(x,y,x1,y1)-r-eps)<0)
        l.push_back(vec(x1-x,y1-y));
    }
    /*for (i=0;i<l.size();i++)
      l[i].ang=atan2(l[i].y,l[i].x);
    sort(l.begin(),l.end(),cmp);
    int ans=0;
    if (l[0].ang<=0)
    {
      for (i=0;i<l.size()&&l[i].ang<=0;i++)
      {
        int s=1;
        for (j=i+1;j<l.size()&&l[j].ang<=l[i].ang+PI;j++)
          s++;
        if (s>ans) ans=s;
      }
    }
    if (i!=l.size())
    {
      k=i;
      for (i=k;i<l.size()&&l[i].ang>0;i++)
      {
        int s=1;
        for (j=1;j<l.size()&&(l[j].ang>=l[i].ang||(l[j].ang<0&&l[j].ang<=l[i].ang-PI));j++)
          s++;
        if (s>ans) ans=s;
      }
    }*/
    int ans=0;
    for (i=0;i<l.size();i++)
    {
      int s=1;
      for (j=0;j<l.size();j++)
      {
        if (i==j) continue;
        if (dcmp(cross(l[i],l[j]))>=0)
          s++; 
      }
      if (s>ans) ans=s;
    }
    printf("%d\n",ans);
    scanf("%lf%lf%lf",&x,&y,&r);
  }
  return 0;
}
