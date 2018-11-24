#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector>
#define eps 1e-9
using namespace std;

struct point{double x,y,z;point(double x=0,double y=0,double z=0):x(x),y(y),z(z){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y,a.z-b.z);}
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y,a.z+b.z);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
vec cross(vec a,vec b){return vec(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
double dot(vec a,vec b){return a.x*b.x+a.y*b.y+a.z*b.z;}
double length(vec a){return sqrt(dot(a,a));}
struct face{
       int v[3];};

point p[204],o[204];
bool vis[204][204];

double random2()
{
  return (rand()/(double)RAND_MAX-0.5)*eps;
}

void addnoise(point &p)
{
  p.x+=random2();
  p.y+=random2();
  p.z+=random2();
}

vec normal(point a,point b,point c){return cross(b-a,c-a);}
bool cansee(face f,point a){return dcmp(dot(normal(p[f.v[0]],p[f.v[1]],p[f.v[2]]),a-p[f.v[0]]))>0;}

int main()
{
  freopen("1209.in","r",stdin);
  freopen("1209.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  srand(time(NULL));
  for (i=1;i<=n;i++)
    scanf("%lf%lf%lf",&o[i].x,&o[i].y,&o[i].z);
  for (i=1;i<=n;i++)
    p[i]=o[i];
  for (i=1;i<=n;i++)
    addnoise(p[i]);
  vector<face> cur;
  face t;
  t.v[0]=1;t.v[1]=2;t.v[2]=3;
  cur.push_back(t);
  t.v[0]=3;t.v[2]=1;
  cur.push_back(t);
  for (i=4;i<=n;i++)
  {
    vector<face> next;
    for (j=0;j<cur.size();j++)
    {
      face &f=cur[j];
      int res=cansee(f,p[i]);
      if (!res)
        next.push_back(f);
      for (k=0;k<3;k++)
        vis[f.v[k]][f.v[(k+1)%3]]=res;
    }
    for (j=0;j<cur.size();j++)
    {
      for (k=0;k<3;k++)
      {
        int a=cur[j].v[k];
        int b=cur[j].v[(k+1)%3];
        if (vis[a][b]!=vis[b][a]&&vis[a][b])
        {
          face tmp;
          tmp.v[0]=a;
          tmp.v[1]=b;
          tmp.v[2]=i;
          next.push_back(tmp);
        }
      }
    }
    cur=next;
  }
  double ans=0;
  for (i=0;i<cur.size();i++)
    ans+=length(cross(o[cur[i].v[0]]-o[cur[i].v[2]],o[cur[i].v[1]]-o[cur[i].v[2]]));
  printf("%.6lf\n",ans/2.0);
  return 0;
}
