#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;

int a[30];
char st[100];

int main()
{
	freopen("1598.in","r",stdin);
	freopen("1598.out","w",stdout);
	memset(a,0,sizeof(a));
	int i;
	while(scanf("%s",st)==1)
	{
		int len=strlen(st);
		for (i=0;i<len;i++)
			if (isalpha(st[i]))
				a[st[i]-'A'+1]++;
	}
	int ms=0;
	for (i=1;i<=26;i++)
		ms=max(ms,a[i]);
	while(ms)
	{
		int r=0;
		for (i=1;i<=26;i++)
			if (a[i]==ms)
				r=i;
		if (r==26)
		{
			for (i=1;i<=25;i++)
			{
				if (a[i]==ms)
					printf("*"),a[i]--;
				else
					printf(" ");
				printf(" ");
			}
			printf("*\n");
			a[26]--;
			ms--;
		}
		else
		{
			for (i=1;i<=r;i++)
			{
				if (a[i]==ms)
					printf("*"),a[i]--;
				else
					printf(" ");
				if (i==r)
					printf("\n");
				else
					printf(" ");	
			}
			ms--;
		}
	}
	for (i=1;i<=25;i++)
		printf("%c ",'A'+i-1);
	printf("Z\n");
	return 0;
}

