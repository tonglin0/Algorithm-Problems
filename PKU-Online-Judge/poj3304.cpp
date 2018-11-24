#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#define eps 1e-8
using namespace std;

struct point{double x,y;point(double x=0,double y=0):x(x),y(y){}};
typedef point vec;
vec operator + (vec a,vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
vec operator * (vec a,double b){return vec(a.x*b,a.y*b);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool slcross(point a,point b,point c,point d)
{
  double s1,s2;
  int d1,d2;
  d1=dcmp(s1=cross(d-c,a-c));
  d2=dcmp(s2=cross(d-c,b-c));
  if (d1*d2<=0)
    return true;
  return false;
}

point l[200][2];

int main()
{
  //freopen("3304.in","r",stdin);
  //freopen("3304.out","w",stdout);
  int T,n,i,j,k,m;
  scanf("%d",&T);
  while(T--)
  {
    memset(l,0,sizeof(l));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%lf%lf%lf%lf",&l[i][0].x,&l[i][0].y,&l[i][1].x,&l[i][1].y);
    bool flag=false;
    if (n==1||n==2)
      {printf("Yes!\n");continue;}
    for (i=1;i<=n&&!flag;i++)
      for (j=1;j<i&&!flag;j++)
        for (k=0;k<=1;k++)
          for (m=0;m<=1;m++)
          {
            point a,b;
            a=l[i][k];
            b=l[j][m];
            if (fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps) continue;
            bool fl=true;
            for (int ii=1;ii<=n;ii++)
              if (!slcross(l[ii][0],l[ii][1],a,b))
              {
                fl=false;
                break;
              }
            if (fl){flag=true;break;}
          }
    if (flag)
      printf("Yes!\n");
    else 
      printf("No!\n");
  }
  return 0; 
}
