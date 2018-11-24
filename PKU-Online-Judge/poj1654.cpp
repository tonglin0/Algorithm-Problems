#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define eps 1e-8
using namespace std;

struct point{__int64 x,y;point(__int64 x=0,__int64 y=0):x(x),y(y){}};
typedef point vec;
vec operator - (vec a,vec b){return vec(a.x-b.x,a.y-b.y);}
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
__int64 cross(point a,point b){return a.x*b.y-a.y*b.x;}
__int64 abs(__int64 a){if (a>0) return a;return -a;}

char s[1000005];

int main()
{
  int n,i,j,k,m,T;
  scanf("%d",&T);
  while(T--)
  {
    memset(s,0,sizeof(s));
    scanf("%s",s);
    if (strlen(s)<=3)
    {
      printf("0\n");
      continue;
    }
    __int64 ans=0;
    point a=vec(0,0);
    point b=a;
    for (i=0;s[i]!='5';i++)
    {
      int d=s[i]-'0';
      if (d>=7) a.y++;
      if (d<=3) a.y--;
      if (d%3==0) a.x++;
      if (d%3==1) a.x--;
      ans=ans+cross(b,a);
      b=a;
    }
    if (ans%2==0)
      printf("%I64d\n",abs(ans/2));
    else
      printf("%I64d.5\n",abs(ans/2));
  }
  return 0;
}

