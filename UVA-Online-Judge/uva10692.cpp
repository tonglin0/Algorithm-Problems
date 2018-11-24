#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define lint long long
using namespace std;

lint a[20];
lint n;
lint phi[10009];

lint pow_mod(lint a,lint b,lint c)
{
  lint ans=1;
  lint t=a%c;
  while(b)
  {
    if (b&1) ans=ans*t%c;
    b>>=1;
    t=t*t%c;
  }
  return ans;
}

lint super_pow_mod(lint k,lint c)
{
  if (k==n)
    return a[k]%c;
  lint p=phi[c];
  lint b=super_pow_mod(k+1,p);
  return pow_mod(a[k]%c,b+p,c);
}

int main()
{
  freopen("10692.in","r",stdin);
  freopen("10692.out","w",stdout);
  lint b,c,i,ii=0,j,k,m;
  memset(phi,0,sizeof(phi));
  phi[1]=1;
  for (i=2;i<=10000;i++)
    if (!phi[i])
      for (j=i;j<=10000;j+=i)
      {
        if (!phi[j])
          phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
	  }
  while(scanf("%lld%lld",&c,&n)==2)
  {
    printf("Case #%lld: ",++ii);
	for (i=1;i<=n;i++)
      scanf("%lld",&a[i]);
    printf("%lld\n",super_pow_mod(1,c)%c);
  }
  return 0;
}
