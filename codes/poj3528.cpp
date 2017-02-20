#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct point{double x,y,z;point(double x=0,double y=0,double z=0):x(x),y(y),z(z){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y,a.z-b.z);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y,a.z+b.z);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b,a.z*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
vec cross(vec a,vec b){return vec(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y+a.z*b.z;}
double length(vec a){return sqrt(fabs(dot(a,a)));}
double min(double a,double b){return a<b?a:b;}
struct face{
       int v[3];
       point normal(point *p){return cross(p[v[1]]-p[v[0]],p[v[2]]-p[v[0]]);}
       int cansee(point *p,int i) 
       {
         return dot(p[i]-p[v[0]],normal(p))>0?1:0;
       }};

point p[1020];
vector<face> cur;
int vis[520][520];

int main()
{
  freopen("3528.in","r",stdin);
  freopen("3528.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  k=0;
  memset(vis,0,sizeof(vis));
  for (i=0;i<n;i++)
  {
    double x,y,z;
    scanf("%lf%lf%lf",&x,&y,&z);
    bool flag=true;
    for (j=0;j<k;j++)
      if (dcmp(x-p[j].x)==0&&dcmp(y-p[j].y)==0&&dcmp(z-p[j].z)==0)
        flag=false;
    if (flag) p[k++]=vec(x,y,z);
  }
  n=k;  
  if (n<=2)
  {
    printf("0\n");
    return 0;
  }
  if (n==3)
  {
    double ans=length(cross(p[2]-p[0],p[1]-p[0]))/2.0;
    printf("%.3lf\n",ans);
    return 0;
  }
  face f;
  f.v[0]=0;f.v[1]=1;f.v[2]=2;
  cur.push_back(f);
  f.v[0]=2;f.v[1]=1;f.v[2]=0;
  cur.push_back(f);
  for (i=3;i<n;i++)
  {
    vector<face> next;
    for (j=0;j<cur.size();j++)
    {
      f=cur[j];
      int res=f.cansee(p,i);
      if (!res) next.push_back(f);
      for (k=0;k<3;k++) vis[f.v[k]][f.v[(k+1)%3]]=res;
    }
    for (j=0;j<cur.size();j++)
      for (k=0;k<3;k++)
      {
        int a=cur[j].v[k];
        int b=cur[j].v[(k+1)%3];
        if (vis[a][b]!=vis[b][a]&&vis[a][b])
        {
          face ff;
          ff.v[0]=a;ff.v[1]=b;ff.v[2]=i;
          next.push_back(ff);
        }
      }
    cur=next;
  }
  double ans=0;
  for (i=0;i<cur.size();i++)
    ans+=fabs(length(cross(p[cur[i].v[0]]-p[cur[i].v[1]],p[cur[i].v[2]]-p[cur[i].v[1]])));
  ans=ans/2.0;
  printf("%.3lf\n",ans);
  return 0;
} 
