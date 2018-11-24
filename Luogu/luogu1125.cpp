#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

char s[103];
int a[27];

bool isprime(int x)
{
	if (x<=1) return false;
	int m=(int)(sqrt(x)+0.01);
	for (int i=2;i<=m;i++)
		if (x%i==0)
			return false;
	return true;
}

int main()
{
	scanf("%s",s);
	int len=strlen(s);
	memset(a,0,sizeof(a));
	for (int i=0;i<len;i++)
		a[s[i]-'a']++;
	int ms=0,mi=101;
	for (int i=0;i<26;i++)
	{
		if (a[i]==0) continue;
		ms=max(ms,a[i]);
		mi=min(mi,a[i]);
	}
	if (isprime(ms-mi))
	{
		printf("Lucky Word\n");
		printf("%d\n",ms-mi);
	}
	else
	{
		printf("No Answer\n");
		printf("0\n");
	}
	return 0;
}
