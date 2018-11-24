#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

lint gcd(lint a,lint b)
{
  lint t;
  while(b)
  {
    t=a;
    a=b;
    b=t%b;
  }
  return a;
}

int main()
{
  freopen("12075.in","r",stdin);
  freopen("12075.out","w",stdout);
  lint ii=0,n,i,j,k,m;
  while(scanf("%lld%lld",&n,&m)==2)
  {
    if (n==0&&m==0) break;
	m++;n++;
	printf("Case %lld: ",++ii);
    unsigned long long s1,s2,s3;
    if (m*n<3)
	  s1=0;
	else
	  s1=m*n*(m*n-1)/2*(m*n-2)/3;
    if (m<3)
	  s2=0;
	else
	  s2=n*m*(m-1)*(m-2)/6;
	if (n<3)
	  s3=0;
	else
	  s3=m*n*(n-1)*(n-2)/6;
	lint s4=0;
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	    s4+=2*(n-i)*(m-j)*(gcd(i,j)-1);
	lint ans=s1-s2-s3-s4;
	printf("%lld\n",ans);
  }
  return 0;
}
