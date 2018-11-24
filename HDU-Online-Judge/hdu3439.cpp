#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lint long long
using namespace std;

int p;
lint st[15];
lint ci[15];
lint mi[15],a[15];
lint f[100005];

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

lint rev(lint a,lint n)
{
  lint x,y,d;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

lint pow_mod(lint a,lint b,lint c)
{
  lint ans=1,t=a%c;
  while(b)
  {
    if (b&1)
      ans=ans*t%c;
    b>>=1;
    t=t*t%c;
  }
  return ans;
}

lint get_times(lint n,lint p)
{
  lint ans=0;
  while(n)
  {
    ans+=n/p;
    n/=p;
  }
  return ans;
}

lint find(lint n,lint pi,lint pc)
{
  if (n==0)
    return 1;
  lint ans=find(n/pi,pi,pc);
  f[0]=1;
  for (lint i=1;i<=pc;i++)
    if (i%pi==0)
      f[i]=f[i-1];
    else
      f[i]=f[i-1]*i%pc;
  ans=ans*pow_mod(f[pc],n/pc,pc)%pc*f[n%pc]%pc;
  return ans;
}

lint cmod(lint n,lint m,lint p)
{
  lint i,j,k;
  lint top=0;
  lint tp=p;
  lint tmp=(lint)sqrt(p+0.5);
  memset(ci,0,sizeof(ci));
  for (i=2;i<=tmp;i++)
    if (tp%i==0)
    {
      st[++top]=i;
      while(tp%i==0)
      {
        ci[top]++;
        tp/=i;
	  }
	}
  if (tp>1)
  {
    st[++top]=tp;
    ci[top]=1;
  }
  for (i=1;i<=top;i++)
  {
    lint pi=st[i];
    lint pc=pow_mod(pi,ci[i],p+1);
    mi[i]=pc;
    lint ptime=0;
    ptime+=get_times(n,pi);
    ptime-=get_times(m,pi);
    ptime-=get_times(n-m,pi);
    lint ans=pow_mod(pi,ptime,pc);
    if (ans==0)
    {
      a[i]=0;
      continue;
	}
	ans=(ans*(find(n,pi,pc))%pc);
    ans=ans*(rev(find(m,pi,pc),pc))%pc;
    ans=ans*(rev(find(n-m,pi,pc),pc))%pc;
    a[i]=ans;
  }
  lint M=p;
  lint ans=0;
  for (i=1;i<=top;i++)
  {
    lint Mi=M/mi[i];
    lint x,y,d;
    ex_gcd(Mi,mi[i],d,x,y);
    x=(x%mi[i]+mi[i])%mi[i];
    ans=(ans+Mi*x%p*a[i]%p)%p;
  }
  return ans;
}

lint g(lint n)
{
  lint ans=0;
  bool flag;
  if (n&1)
    flag=false;
  else
    flag=true;
  lint pre=1;
  for (lint i=n;i>=n/p*p;i--)
  {
    if (flag)
      ans=(ans+pre)%p;
    else
      ans=(ans-pre)%p;
    pre=pre*i%p;
    flag=(!flag);
  }
  return (int)((ans+p)%p);
}

int main()
{
  freopen("3439.in","r",stdin);
  freopen("3439.out","w",stdout);
  int ii,ca,i,j,k,m,n;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
  	scanf("%d%d%d",&n,&k,&p);
    printf("Case %d: ",ii);
    printf("%d\n",(int)((lint)cmod(n,k,p)*(lint)g(n-k)%p));
  }
  return 0;
}
