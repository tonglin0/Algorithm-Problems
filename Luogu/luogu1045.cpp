#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

struct bign
{
	int s[504],len;
	bign(){len=0;memset(s,0,sizeof(s));}
};

bign operator * (bign a,bign b)
	{
		bign c;
		for (int i=1;i<=min(a.len,500);i++)
			for (int j=1;j<=min(b.len,500);j++)
				if (i+j-1<=500)
					c.s[i+j-1]+=a.s[i]*b.s[j];
		for (int i=1;i<=500;i++)
		{
			c.s[i+1]+=c.s[i]/10;
			c.s[i]%=10;
		}
		c.len=500;
		while(c.s[c.len]==0)
			c.len--;
		return c;
	}

int main()
{
	int p,i,j;
	scanf("%d",&p);
	printf("%d\n",(int)(p*log(0.0+2)/log(10.0)+1));
	bign a;a.s[1]=2;a.len=1;
	bign ans;ans.s[1]=1;ans.len=1;
	bign t;t=a;
	bign tmp;
	while(p)
	{
		if (p&1)
		{
			tmp=ans*t;
			ans=tmp;
		}
		p>>=1;
		tmp=t*t;
		t=tmp;
	}
	ans.s[1]--;
	for (i=500;i>=1;i--)
	{
		printf("%d",ans.s[i]);
		if (i%50==1)
			printf("\n");
	}
	return 0;
}
