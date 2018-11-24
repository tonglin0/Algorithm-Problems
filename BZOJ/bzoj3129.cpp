#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lint long long
using namespace std;

lint MOD;
lint a[20];
lint pi[23],pc[23],ci[23],mi[23];
int top=0;
lint st[23];
lint aa[23];
lint t[100005];

lint pow_mod(lint a,lint b,lint c)
{
	lint ans=1,t=a%c;
	while(b)
	{
		if (b&1)
			ans=ans*t%c;
		t=t*t%c;
		b>>=1;
	}
	return ans;
}

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

void gen_mod(lint p)
{
	lint tmpp=p;
	lint m=(lint)sqrt(p+0.5);
	for (int i=2;i<=m&&p>1;i++)
		if (p%i==0)
		{
			st[++top]=i;
			pi[top]=i;
			while(p%i==0)
			{
				ci[top]++;
				p/=i;
			}
		}
	if (p>1)
	{
		st[++top]=p;
		pi[top]=p;
		ci[top]=1;
	}
	p=tmpp;
	for (int i=1;i<=top;i++)
		mi[i]=pc[i]=pow_mod(pi[i],ci[i],p+1);
}

lint gen_times(lint n,lint p)
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
	if (n==0) return 1;
	t[0]=t[1]=1;
	for (int i=2;i<=pc;i++)
		if (i%pi==0)
			t[i]=t[i-1];
	    else
			t[i]=t[i-1]*i%pc;
	lint tmpa=t[pc],tmpb=t[n%pc];
	return pow_mod(tmpa,n/pc,pc)*tmpb%pc*find(n/pi,pi,pc)%pc;
}

lint cmod(lint n,lint m,lint p)
{
	if (n<m) return 0;
	for (int i=1;i<=top;i++)
	{
		lint times=0;
		times+=gen_times(n,pi[i]);
		times-=gen_times(m,pi[i]);
		times-=gen_times(n-m,pi[i]);
		lint s=pow_mod(pi[i],times,pc[i]);
		s=s*find(n,pi[i],pc[i])%pc[i];
		s=s*rev(find(m,pi[i],pc[i]),pc[i])%pc[i];
		s=s*rev(find(n-m,pi[i],pc[i]),pc[i])%pc[i];
		aa[i]=s;
	}
	lint ans=0;
	for (int i=1;i<=top;i++)
	{
		lint x,y,d;
		lint w=MOD/mi[i];
		ex_gcd(w,mi[i],d,x,y);
		x=(x%mi[i]+mi[i])%mi[i];
		ans=(ans+w*x%MOD*aa[i]%MOD)%MOD;
	}
	return (ans%MOD+MOD)%MOD;
}

int main()
{
	freopen("3129.in","r",stdin);
	freopen("3129.out","w",stdout);
	lint ca,n,i,m,n1,n2;
	scanf("%lld%lld",&ca,&MOD);
	gen_mod(MOD);
	while(ca--)
	{
		scanf("%lld%lld%lld%lld",&n,&n1,&n2,&m);
		for (i=1;i<=n1+n2;i++)
			scanf("%lld",&a[i]);
		for (i=n1+1;i<=n1+n2;i++)
			m-=(a[i]-1);
		lint full=(1<<n1)-1;
		lint tmpm=m;
		lint ans=0;
		for (i=1;i<=n1;i++)
			a[i]++;
		for (lint s=0;s<=full;s++)
		{
			m=tmpm;
			int d=0;
			for (i=0;i<n1;i++)
				if (s&(1<<i))
				{
					d++;
					m-=(a[i+1]-1);
				}
			lint op=1;
			if (d&1)
				op=-1;
			ans=((ans+op*cmod(m-1,n-1,MOD)%MOD)%MOD+MOD)%MOD;
		}
		printf("%lld\n",(ans+MOD)%MOD);
	}
	return 0;
}