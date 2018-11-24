#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
struct line{
       point p;vec v;double ang;int id;};
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool onleft(point p,line l){return dcmp(cross(l.v,p-l.p))>0;}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dot(a,a));}
vec rotate(vec a){double l=length(a);return vec(-a.y/l,a.x/l);}
bool cmp(line a,line b){return a.ang<b.ang;}
struct node{int v,w;};
vector<node> g[3609];

typedef pair<int,int> pii;
line l[3609],q[3609];
point p[3609],o[3609];
int top;
point st;
int S,T;
int dis[3609];
bool vis[3609];

bool inside(point a,int l,int r)
{
  int wn=0;
  point t[3609];
  int n=r-l+1;
  for (int i=0;i<n;i++)
    t[i]=p[l+i];
  for (int i=0;i<n;i++)
  {
    int d1=dcmp(cross(t[(i+1)%n]-t[i],a-t[i]));
    int s1=dcmp(t[(i+1)%n].y-a.y);
    int s2=dcmp(t[i].y-a.y);
    if (d1>0&&s1>0&&s2<=0)
      wn++;
    if (d1<0&&s1<0&&s2>=0)
      wn--;
  }
  if (wn==0)
    return false;
  else
    return true;
}

void halfplane(int k,int n)
{
  int f=0,r=0;
  q[0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(r>f&&!onleft(p[r-1],l[i]))r--;
    while(r>f&&!onleft(p[f],l[i]))f++;
    q[++r]=l[i];
    if (dcmp(cross(l[i].v,q[r-1].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
    }
    if (r>f) p[r-1]=llcross(q[r-1].p,q[r-1].v,q[r].p,q[r].v);
  }
  while(r>f&&!onleft(p[r-1],q[f]))r--;
  p[r]=llcross(q[r].p,q[r].v,q[f].p,q[f].v);
  node t;
  for (int i=f;i<=r;i++)
  {
    t.v=q[i].id;
    if (q[i].id!=T)
      t.w=1;
    else
      t.w=0;
    g[k].push_back(t);
  }
  if (inside(st,f,r))
    S=k;
}

int main()
{
  freopen("3199.in","r",stdin);
  freopen("3199.out","w",stdout);
  int ca,n,i,j,k,m;
  double xa,ya,x0,y0;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    if (n==0)
    {
      printf("0\n");
      continue;
    }
    for (i=0;i<3609;i++)
      g[i].clear();
    scanf("%lf%lf%lf%lf",&xa,&ya,&st.x,&st.y);
    for (i=1;i<=n;i++)
      scanf("%lf%lf",&o[i].x,&o[i].y);
    T=n+1;
    for (i=1;i<=n;i++)
    {
      top=0;
      line t;
      t.p=vec(0,0);t.v=vec(xa,0);t.id=T;l[++top]=t;
      t.p=vec(xa,0);t.v=vec(0,ya);t.id=T;l[++top]=t;
      t.p=vec(xa,ya);t.v=vec(-xa,0);l[++top]=t;
      t.p=vec(0,ya);t.v=vec(0,-ya);l[++top]=t;
      for (j=1;j<=n;j++)
      {
        if (i==j) continue;
        t.p=vec((o[i].x+o[j].x)/2.0,(o[i].y+o[j].y)/2.0);
        t.v=rotate(o[j]-o[i]);
        t.id=j;
        l[++top]=t;
      }
      for (j=1;j<=top;j++)
        l[j].ang=atan2(l[j].v.y,l[j].v.x);
      sort(l+1,l+top+1,cmp);
      halfplane(i,top);
    }
    priority_queue<pii,vector<pii>,greater<pii> > q;
    memset(vis,0,sizeof(vis));
    for (i=0;i<=T+2;i++)
      dis[i]=(int)1e9;
    dis[S]=1;
    q.push(make_pair(1,S));
    while(!q.empty())
    {
      pii x=q.top();q.pop();
      int u=x.second;
      if (vis[u]) continue;
      vis[u]=true;
      if (u==T) break;
      for (i=0;i<g[u].size();i++)
        if (!vis[g[u][i].v]&&dis[u]+g[u][i].w<dis[g[u][i].v])
          q.push(make_pair(dis[g[u][i].v]=dis[u]+g[u][i].w,g[u][i].v));
    }
    printf("%d\n",dis[T]);
  }
  return 0;
}
