#include<cstdio>
#include<cstring>
using namespace std;

bool vis[10];
int s[910];

bool rep(int x)
{
	int a=x%10,b=x/100,c=x/10%10;
	if (a*b*c==0)
		return true;
	if (a==b||b==c||a==c) 
		return true;
	return false;
}

bool rep2(int s,int t)
{
	int a=s%10,b=s/10%10,c=s/100;
	int x=t%10,y=t/10%10,z=t/100;
	if (a==x||a==y||a==z||b==x||b==y||b==z||c==x||c==y||c==z)
		return true;
	return false;
}

int main()
{
	freopen("1618.out","w",stdout);
	int top=0,a,b,c,i,j,k;
	bool flag=false;
	scanf("%d%d%d",&a,&b,&c);
	for (i=123;i<=987;i++)
		if (!rep(i))
			s[++top]=i;
	for (i=1;i<=top;i++)
		if (s[i]%a==0)
			for (j=1;j<=top;j++)
				if ((s[j]%b==0)&&(b*s[i]==a*s[j]))
					if (!rep2(s[i],s[j]))
					{
						for (k=1;k<=top;k++)
							if (s[k]%c==0&&(b*s[k]==c*s[j])&&(a*s[k]==c*s[i])&&(!rep2(s[i],s[k]))&&(!rep2(s[j],s[k])))
								printf("%d %d %d\n",s[i],s[j],s[k]),flag=true;
					}
	if (!flag)
		printf("No!!!\n");
	return 0;
}
