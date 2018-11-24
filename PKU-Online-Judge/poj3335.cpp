#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
struct line{
         point p;
         vec v;
         double ang;
         line(){}
         line(point p,vec v):p(p),v(v){}
       };
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(line a,line b) {return a.ang<b.ang;}

point p[203],anss[203];
line q[1000];
line l[203];
int n;

bool onleft(point p,line l)
{
  return dcmp(cross(l.v,p-l.p))<=0;
}

point llcross(point a,vec v,point b,vec w)
{
  vec u=a-b;
  return a+v*(cross(w,u)/cross(v,w));
}

int halfplane()
{
  int last,first;
  q[first=last=0]=l[1];
  for (int i=2;i<=n;i++)
  {
    while(last>first&&!onleft(p[last-1],l[i])) last--;
    while(last>first&&!onleft(p[first],l[i])) first++;
    q[++last]=l[i];
    if (dcmp(cross(q[last-1].v,l[i].v))==0)
    {
      last--;
      if (onleft(l[i].p,q[last]))
        q[last]=l[i];
    }
    if (last>first) p[last-1]=llcross(q[last-1].p,q[last-1].v,q[last].p,q[last].v);
  }
  while(last>first&&!onleft(p[last-1],q[first])) last--;
  if (last-first<=1) return 0;
  p[last]=llcross(q[last].p,q[last].v,q[first].p,q[first].v);
  return last-first+1;
}

int main()
{
  //freopen("3335.in","r",stdin);
  //freopen("3335.out","w",stdout);
  int m,i,j,k,T;
  scanf("%d",&T);
  while(T--)
  {
    memset(p,0,sizeof(p));
    memset(anss,0,sizeof(anss));
    memset(q,0,sizeof(q));
    memset(l,0,sizeof(l));
    scanf("%d",&n);
    point a,b,c;
    for (i=1;i<=n;i++)
    {
      scanf("%lf%lf",&a.x,&a.y);
      if (i==1) {b=a;c=a;continue;}
      line x=line(b,a-b);
      l[i-1]=x;
      b=a;
    }
    l[n]=line(a,c-a);
    for (i=1;i<=n;i++)
      l[i].ang=atan2(l[i].v.y,l[i].v.x);
    sort(l+1,l+1+n,cmp);
    int ans=halfplane();
    //printf("%d\n",ans);
    if (ans==0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
