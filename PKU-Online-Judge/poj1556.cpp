#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define INF (int)1e9
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
struct seg{point a,b;};
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
typedef pair<double,int> pii;
struct node{int v;double w;};
double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

vector<point> p;
vector<seg> l;
bool vis[1000];
vector<node> g[1000];
double dis[1000];

bool sscross(point a,point b,point c,point d)
{
  double s1,s2,s3,s4;
  int d1,d2,d3,d4;
  d1=dcmp(s1=cross(b-a,c-a));
  d2=dcmp(s2=cross(b-a,d-a));
  d3=dcmp(s3=cross(d-c,a-c));
  d4=dcmp(s4=cross(d-c,b-c));
  if (d1*d2<0&&d3*d4<0)
    return true;
  else
    return false;
}

int main()
{
  freopen("1556.in","r",stdin);
  freopen("1556.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n!=-1)
  {
    l.clear();
    for (i=0;i<1000;i++) g[i].clear();
    p.clear();
    p.push_back(vec(0.0,5.0));
    p.push_back(vec(10.0,5.0));
    for (i=1;i<=n;i++)
    {
      double x,y1,y2,y3,y4;
      scanf("%lf%lf%lf%lf%lf",&x,&y1,&y2,&y3,&y4);
      p.push_back(vec(x,y1));
      p.push_back(vec(x,y2));
      p.push_back(vec(x,y3));
      p.push_back(vec(x,y4));
      seg s;
      s.a=vec(x,0);s.b=vec(x,y1);l.push_back(s);
      s.a=vec(x,y2);s.b=vec(x,y3);l.push_back(s);
      s.a=vec(x,y4);s.b=vec(x,10);l.push_back(s);
    }
    for (i=0;i<p.size();i++)
      for (j=i+1;j<p.size();j++)
      {
        bool flag=true;
        for (k=0;k<l.size();k++)
          if (sscross(l[k].a,l[k].b,p[i],p[j]))
          {
            flag=false;
            break;
          }
        if (flag)
        {
          node x;
          x.w=dist(p[i],p[j]);
          x.v=j;
          g[i].push_back(x);
          x.v=i;
          g[j].push_back(x);
        }
      }
    for (i=0;i<p.size();i++)
      dis[i]=INF;
    dis[0]=0;
    memset(vis,0,sizeof(vis));
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
      pii x=q.top();q.pop();
      int u=x.second;
      if (vis[u]) continue;
      vis[u]=true;
      if (u==1) break;
      for (i=0;i<g[u].size();i++)
        if (!vis[g[u][i].v]&&dcmp(dis[u]+g[u][i].w-dis[g[u][i].v])<0)
          q.push(make_pair(dis[g[u][i].v]=dis[u]+g[u][i].w,g[u][i].v));
    }
    printf("%.2lf\n",dis[1]);
    scanf("%d",&n);
  }
  return 0;
}

