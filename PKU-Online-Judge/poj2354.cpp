#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define PI acos(-1)
#define R 6875.0/2.0
using namespace std;

struct point3{double x,y,z;point3(double x=0,double y=0,double z=0):x(x),y(y),z(z){}};
typedef point3 vec3;
double dist(point3 a,point3 b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
double acos(int a){return acos((double)a);}

char s[1000];

int main()
{
  freopen("2354.in","r",stdin);
  freopen("2354.out","w",stdout);
  point3 a,b;
  int n,i;
  //for (i=1;i<=9;i++)
    //scanf("%s",s);
while(scanf("%s",s)&&s[0]=='M')
{
  for (i=1;i<=3;i++)
    gets(s);
  double d,f,m;
  scanf("%lf^%lf'%lf\"",&d,&f,&m);
  d=d+(f/60.0+m/3600.0);
  d=d/180.0*PI;
  //scanf("%s",s);
  scanf("%s",s);
  if (s[0]=='S')
    d=-d;
  a.z=R*sin(d);
  double w,j;
  w=d;
  scanf("%s",s);
  scanf("%lf^%lf'%lf\"",&d,&f,&m);
  d=d+(f/60.0+m/3600.0);
  //scanf("%s",s);  
  scanf("%s",s);
  if (s[0]=='W')
    d=-d;
  j=d;
  j=j/180.0*PI;
  a.x=R*cos(w)*sin(j);
  a.y=R*cos(w)*cos(j);
  gets(s);
  gets(s);
  scanf("%lf^%lf'%lf\"",&d,&f,&m);
  d=d+(f/60.0+m/3600.0);
  d=d/180.0*PI;
  //scanf("%s",s);
  scanf("%s",s);
  if (s[0]=='S')
    d=-d;
  b.z=R*sin(d);
  w=d;
  scanf("%s",s);
  scanf("%lf^%lf'%lf\"",&d,&f,&m);
  d=d+(f/60.0+m/3600.0);
  //scanf("%s",s);
  scanf("%s",s);
  if (s[0]=='W')
    d=-d;
  j=d;
  j=j/180.0*PI;
  b.x=R*cos(w)*sin(j);
  b.y=R*cos(w)*cos(j);
  double dis=dist(a,b);
  //double ang=acos((double)(R*R+R*R-dis*dis)/(2.0*R*R));
  double ang=2*asin(dis/(2.0*R));
  double ans=fabs(ang*R);
  printf("The distance to the iceberg: %.2lf miles.\n",ans);
  //int xx=(int)floor(ans+0.5);
  ans=(int)(ans+0.005);
  if (ans<100)
    printf("DANGER!\n");
  gets(s);
  gets(s);
}
  return 0;
}
