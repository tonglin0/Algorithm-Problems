#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
double max(double a,double b){return a>b?a:b;}
double min(double a,double b){return a<b?a:b;}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
typedef pair<double,double> pii;
vector<pii> l;
double x1l,x2l;

point llcross(point a,vec v,point b,vec w)
{
  vec u=a-b;
  return a+v*(cross(w,u)/cross(v,w));
}

void insert(point a,point b)
{
  bool flag=false;
  while(!flag)
  {
    flag=true;
    for (int i=0;i<l.size();i++)
      if (dcmp(l[i].first-a.x-eps)<0&&dcmp(l[i].second-b.x+eps)>0)
        break;
      else if (dcmp(l[i].first-a.x+eps)>0&&dcmp(l[i].second-b.x-eps)<0)
      {
        l.erase(l.begin()+i);
        flag=false;
        break;
      }
      else if (dcmp(l[i].first-a.x-eps)<0&&dcmp(l[i].second-a.x+eps)>0&&dcmp(l[i].second-b.x-eps)<0)
      {
        a.x=l[i].first;
        l.erase(l.begin()+i);
        flag=false;
        break;
      } 
      else if (dcmp(l[i].first-a.x+eps)>0&&dcmp(l[i].first-b.x-eps)<0&&dcmp(l[i].second-b.x+eps)>0)
      {
        b.x=l[i].second;
        l.erase(l.begin()+i);
        flag=false;
        break;
      }
  }
  if (a.x>=x2l||b.x<=x1l) return;
  l.push_back(make_pair(a.x,b.x));
}

int main()
{
  //freopen("2074.in","r",stdin);
  //freopen("2074.out","w",stdout);
  int n,i,j,k,m;
  double x1,x2,y,yl;
  scanf("%lf%lf%lf",&x1,&x2,&y);
  while(!(dcmp(x1)==0&&dcmp(x2)==0&&dcmp(y)==0))
  {
    l.clear();
    scanf("%lf%lf%lf",&x1l,&x2l,&yl);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      point a,b;
      scanf("%lf%lf%lf",&a.x,&b.x,&a.y);
      b.y=a.y;
      if (dcmp(a.y-y)>=0) continue;
      if (dcmp(a.y-yl)<=0) continue;
      //if (dcmp(fabs(a.y-y))==0) continue;
      point c=llcross(vec(x1l,yl),vec(x2l-x1l,0),vec(x2,y),vec(a-vec(x2,y)));
      point d=llcross(vec(x1l,yl),vec(x2l-x1l,0),vec(x1,y),vec(b-vec(x1,y)));
      insert(c,d);
    }
    double ans=-100000;
    sort(l.begin(),l.end());
    //for (i=0;i<l.size();i++)
      //printf("%.2lf %.2lf\n",l[i].first,l[i].second);
    if (l.size()==0)
      printf("%.2lf\n",x2l-x1l);
    else if (l.size()==1&&dcmp(l[0].first-x1l-eps)<0&&dcmp(l[0].second-x2l+eps)>0)
      printf("No View\n");
    else
    {
      for (i=1;i<l.size();i++)
        ans=max(ans,l[i].first-l[i-1].second);
      if (dcmp(l[0].first-x1l-eps)>0)
        ans=max(ans,l[0].first-x1l);
      if (dcmp(l[l.size()-1].second-x2l+eps)<0)
        ans=max(ans,x2l-l[l.size()-1].second);
      printf("%.2lf\n",ans);
    }
    scanf("%lf%lf%lf",&x1,&x2,&y);
  }
  return 0;
}

