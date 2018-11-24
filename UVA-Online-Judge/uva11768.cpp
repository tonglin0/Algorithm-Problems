#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lint long long
using namespace std;

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("11768.in","r",stdin);
  freopen("11768.out","w",stdout);
  lint n,i,j,k,m,ca,x,y,xa,ya,xb,yb;
  scanf("%lld",&ca);
  while(ca--)
  {
  	double tx1,tx2,ty1,ty2;
    scanf("%lf%lf%lf%lf",&tx1,&ty1,&tx2,&ty2);
    xa=(lint)(tx1*10+0.5);
    xb=(lint)(tx2*10+0.5);
    ya=(lint)(ty1*10+0.5);
    yb=(lint)(ty2*10+0.5);
    if (xa==xb&&xa%10==0)
    {
      if (ya>yb) swap(ya,yb);
      ya=ceil((double)ya/10.0);
      yb=(lint)((double)yb/10.0);
      printf("%lld\n",yb-ya+1);
      continue;
	}
	else if (xa==xb)
	{
	  printf("0\n");
	  continue;
	}
	else if (ya==yb&&ya%10==0)
	{
	  if (xa>xb) swap(xa,xb);
	  xa=ceil(xa/10.0);
	  xb=(lint)(xb/10.0);
	  printf("%lld\n",xb-xa+1);
	  continue;
	}
	else if (ya==yb)
	{
	  printf("0\n");
	  continue;
	}
	if (xa>xb)
	{
	  swap(xa,xb);
	  swap(ya,yb);
	}
	lint a=yb-ya;
	lint b=xa-xb;
	lint c=xa*yb-xb*ya;
	lint ans=0;
	lint d;
	ex_gcd(a,b,d,x,y);
	x*=(c/d);
	y*=(c/d);
	lint b2=b/d;
	lint k1=((xa-x)/(double)b2)-1;
	lint k2=((xb-x)/(double)b2)+1;
	for (i=k1;i<=k2;i++)
	{
	  lint tx=x+i*b2;
	  lint ty=(c-a*tx)/b;
	  if (tx%10==0&&tx>=xa&&tx<=xb&&ty%10==0)
	    ans++;
	}
	printf("%lld\n",ans);
  }
  return 0;
}
