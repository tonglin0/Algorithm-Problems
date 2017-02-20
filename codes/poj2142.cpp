#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define LL int
using namespace std;

LL Abs(LL a){return a<0?-a:a;}

void ex_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
  if (b==0){d=a;x=1;y=0;}
  else {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("2142.in","r",stdin);
  freopen("2142.out","w",stdout);
  LL a,b,d,c,x,y;
  while(scanf("%d%d%d",&a,&b,&c),a|b|c)
  {
    bool flag=false;
    if (a<b) {swap(a,b);flag=true;}
    ex_gcd(a,b,d,x,y);
    x=x*(c/d);y=y*(c/d);
    LL t1=(LL)(y*d/a);
    LL t2=t1+1;
    LL t3=t1-1;
    LL x1=abs(x+b/d*t1),y1=abs(y-a/d*t1);
    LL x2=abs(x+b/d*t2),y2=abs(y-a/d*t2);
    LL x3=abs(x+b/d*t3),y3=abs(y-a/d*t3);
    LL t;
    if (((x1+y1<x2+y2)||(x1+y1==x2+y2&&a*x1+b*y1<a*x2+b*y2))&&((x1+y1<x3+y3)||(x1+y1==x3+y3&&a*x1+b*y1<a*x3+b*y3)))
      t=t1;
    else if (((x2+y2<x1+y1)||(x2+y2==x1+y1&&a*x2+b*y2<a*x1+b*y1))&&((x2+y2<x3+y3)||(x2+y2==x3+y3&&a*x2+b*y2<a*x3+b*y3)))
      t=t2;
    else
      t=t3;
    if (!flag)
      printf("%d %d\n",abs((x+b/d*t)),abs((y-a/d*t)));
    else
      printf("%d %d\n",abs((y-a/d*t)),abs((x+b/d*t)));   
  }
  return 0;
}
