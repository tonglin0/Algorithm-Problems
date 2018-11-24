#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char s1[103],s2[103],s[103];
int v[30];
bool vis[30];

int main()
{
	int n,l,len,i;
	scanf("%s",s1);
	scanf("%s",s2);
	memset(v,-1,sizeof(v));
	memset(vis,0,sizeof(vis));
	l=strlen(s1);
	for (i=0;i<l;i++)
	{
		int c=s1[i]-'A';
		int d=s2[i]-'A';
		if (v[c]>=0&&v[c]!=d)
		{
			printf("Failed\n");
			return 0;
		}
		v[c]=d;
	}
	for (i=0;i<=25;i++)
		if (v[i]==-1)
		{
			printf("Failed\n");
			return 0;
		}
		else
		{
			if (vis[v[i]])
			{
				printf("Failed\n");
				return 0;
			}
			vis[v[i]]=true;
		}
	scanf("%s",s);
	len=strlen(s);
	for (i=0;i<len;i++)
		printf("%c",'A'+v[s[i]-'A']);
	printf("\n");
	return 0;
}
