#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

double c[4005];

double pows(double a,int f)
{
  double ans=1;
  for (int i=1;i<=f;i++)
    ans=ans*a;
  return ans;
}

int main()
{
  freopen("1319.in","r",stdin);
  freopen("1319.out","w",stdout);
  int a,b,m,p,i,j,k,n;
  while(scanf("%d%d%d%d",&m,&p,&a,&b)==4)
  {
    if (m==1)
    {
      printf("%d\n",(int)pows(b*sqrt(1.0*a),p));
      continue;
	}
	double tar=b*sqrt(1.0*a);
	double s=0;
	double l=-1/sqrt(1.0*a);
	double r=sqrt(1.0*a);
	for (i=1;i<=m-1;i++)
	  if ((m-i)*l+s+r<=tar)
	  {
	    c[i]=r;
	    s+=r;
	  }
	  else
	  {
	    c[i]=l;
	    s+=l;
	  }
	c[m]=tar-s;
	double ans=0;
	for (i=1;i<=m;i++)
	  ans+=pows(c[i],p);
	int f=(int)(ans+0.5);
	printf("%d\n",f);
  }
  return 0;
}
