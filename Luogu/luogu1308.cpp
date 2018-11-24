#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

char s[1000003];
char st[13];
int b[1000003];

int main()
{
	freopen("1308.in","r",stdin);
	freopen("1308.out","w",stdout);
	int len,l,i,j,k;
	scanf("%s",st);
	gets(s);
	gets(s);
	len=strlen(st);
	l=strlen(s);
	for (i=l;i>=1;i--)
		s[i]=s[i-1];
	s[0]=' ';s[l+1]=' ';s[l+2]='\0';l+=2;
	for (i=0;i<len;i++)
		if (st[i]>='A'&&st[i]<='Z')
			st[i]=tolower(st[i]);
	int n=0;
	for (i=0;i<l;i++)
		if (s[i]>='A'&&s[i]<='Z')
			s[i]=tolower(s[i]);
		else if (s[i]==' ')
			b[++n]=i;
	int ans=0,fst;
	for (i=1;i<n;i++)
	{
		if (b[i+1]-b[i]-1!=len) continue;
		bool flag=true;
		for (j=0;j<len;j++)
			if (st[j]!=s[b[i]+j+1])
			{
				flag=false;
				break;
			}
		if (flag)
		{
			ans++;
			if (ans==1)
				fst=b[i];
		}
	}
	if (ans==0)
		printf("-1\n");
	else
		printf("%d %d\n",ans,fst);
	return 0;
}
