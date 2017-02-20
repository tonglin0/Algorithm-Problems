#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-17
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
struct line{
       point p;vec v;double ang;
       line(){}
       line(point p,vec v):p(p),v(v){}};
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps)return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool onleft(point a,line l){return dcmp(cross(l.v,a-l.p))>0;}
point llcross(point a,vec v,point b,vec w){vec u=a-b;return a+v*(cross(w,u)/cross(v,w));}
bool cmp(line a,line b){return a.ang<b.ang;}

line l[103],q[303];
point p[203],poly[103];
int n;
int ui[103],vi[103],wi[103];

int halfplane()
{
  sort(l+1,l+n+1,cmp);
  int f=0,r=0;
  q[0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(f<r&&!onleft(p[r-1],l[i]))r--;
    while(f<r&&!onleft(p[f],l[i]))f++;
    q[++r]=l[i];
    if (dcmp(cross(l[i].v,q[r-1].v))==0)
    {
      r--;
      if (onleft(l[i].p,q[r]))
        q[r]=l[i];
    }
    if (r>f) p[r-1]=llcross(q[r-1].p,q[r-1].v,q[r].p,q[r].v);
  }
  while(f<r&&!onleft(p[r-1],q[f]))r--;
  if (r-f<=1) return 0;
  p[r]=llcross(q[r].p,q[r].v,q[f].p,q[f].v);
  memset(poly,0,sizeof(poly));
  int m=0;
  for (int i=f;i<=r;i++)
    poly[m++]=p[i];
  return m;      
}

int main()
{
  freopen("1755.in","r",stdin);
  freopen("1755.out","w",stdout);
  int N,i,j,k,m;
  scanf("%d",&N);
  memset(ui,0,sizeof(ui));
  memset(vi,0,sizeof(vi));
  memset(wi,0,sizeof(wi));
  for (i=1;i<=N;i++)
    scanf("%d%d%d",&ui[i],&vi[i],&wi[i]);
  for (i=1;i<=N;i++)
  {
    memset(l,0,sizeof(l));
    memset(q,0,sizeof(q));
    memset(p,0,sizeof(p));
    n=0;
    bool flag=true;
    for (j=1;j<=N;j++)
    {
      if (i==j) continue;
      line a;
      if (ui[j]>=ui[i]&&vi[j]>=vi[i]&&wi[j]>=wi[i])
      {
        flag=false;
        break;
      }
      else if (ui[i]>ui[j]&&vi[i]>vi[j]&&wi[i]>wi[j])
        continue;
      double A,B,C;
      A=(1.0/ui[j])-(1.0/ui[i])+(1.0/wi[i])-(1.0/wi[j]);
      B=1.0/vi[j]-1.0/vi[i]+1.0/wi[i]-1.0/wi[j];
      C=1.0/wi[j]-1.0/wi[i];
      a.v=vec(B,-A);
      if (fabs(A)<fabs(B))
        a.p=vec(-C/A,0);
      else
        a.p=vec(0,-C/B);
      l[++n]=a;
    }
    l[++n]=line(vec(0,0),vec(1,0));
    l[++n]=line(vec(0,0),vec(0,-1));
    l[++n]=line(vec(0,1),vec(-1,1));
    for (j=1;j<=n;j++)
      l[j].ang=atan2(l[j].v.y,l[j].v.x);
    m=halfplane();
    double ans=0;
    for (j=1;j<m-1;j++)
      ans+=cross(poly[j]-poly[0],poly[(j+1)%m]-poly[0]);
    if (!flag) {printf("No\n");continue;}
    if (dcmp(ans)==0) printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}
