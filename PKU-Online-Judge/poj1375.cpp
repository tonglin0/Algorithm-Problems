#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define INF (int)1e9
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
struct line{point a,b;};
typedef point vec;
struct circle{point c;double r;
              circle(point c=vec(0,0),double r=0):c(c),r(r){}
              point p(double a){return vec(c.x+r*cos(a),c.y+r*sin(a));}};
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
/*bool operator <= (double a,double b){return dcmp(a-b-eps)<0;}
bool operator >= (double a,double b){return dcmp(a-b+eps)>0;}
bool operator > (double a,double b){return dcmp(a-b-eps)>0;}
bool operator < (double a,double b){return dcmp(a-b+eps)<0;}*/
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
double cross(point a,point b){return a.x*b.y-a.y*b.x;}
double angle(point a){return atan2(a.y,a.x);}
point rotate(vec a,double b){return vec(a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b));}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dot(a,a));}

typedef pair<double,double> pii;
vector<pii> q;

bool cmp(pii a,pii b){return a.first<b.first;}
point llcross(point a,vec v,point b,vec w)
{
  vec u=a-b;
  return a+v*(cross(w,u)/cross(v,w));
}

pii tangent(point p,circle c)
{
  double dis=length(c.c-p);
  double del=asin(c.r/dis);
  vec u=c.c-p;
  vec v=rotate(u,del);
  pii x;
  x.second=llcross(vec(0.0,0.0),vec(1.0,0.0),p,v).x;
  v=rotate(u,-del);
  x.first=llcross(vec(0.0,0.0),vec(1.0,0.0),p,v).x;
  return x;
}

int main()
{
  //freopen("1375.in","r",stdin);
  //freopen("1375.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    point p;
    scanf("%lf%lf",&p.x,&p.y);
    q.clear();
    for (i=1;i<=n;i++)
    {
      circle c;
      scanf("%lf%lf%lf",&c.c.x,&c.c.y,&c.r);
      pii x=tangent(p,c);
      bool flag=false;
      while(!flag)
      {
        flag=true;
        for (j=0;j<q.size();j++)
          if (dcmp(q[j].first-x.first+eps)>0&&dcmp(q[j].second-x.second-eps)<0)
          {
            q.erase(q.begin()+j);
            flag=false;
            break;
          }
          else if (dcmp(q[j].first-x.first+eps)>0&&dcmp(q[j].first-x.second-eps)<0&&dcmp(q[j].second-x.second+eps)>0)
          {
            x.second=max(x.second,q[j].second);
            q.erase(q.begin()+j);
            flag=false;
            break;
          }
          else if (dcmp(q[j].first-x.first-eps)<0&&dcmp(q[j].second-x.first+eps)>0&&dcmp(q[j].second-x.second-eps)<0)
          {
            x.first=min(x.first,q[j].first);
            q.erase(q.begin()+j);
            flag=false;
            break;
          }
          else if (dcmp(q[j].first-x.first-eps)<0&&dcmp(q[j].second-x.second+eps)>0)
          {
            x.first=min(x.first,q[j].first);
            x.second=max(x.second,q[j].second);
            q.erase(q.begin()+j);
            flag=false;
            break;
          }          
      }
      q.push_back(x);
    }
    sort(q.begin(),q.end(),cmp);
    for (i=0;i<q.size();i++)
      printf("%.2lf %.2lf\n",q[i].first,q[i].second);
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}


