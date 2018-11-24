#include<cstdio>
#include<cstring>
using namespace std;

char s[30];

int main()
{
	scanf("%s",s);
	int i,len=strlen(s);
	bool f1=false,f2=false,f3=false;
	if (strchr(s,'.')) f1=true;
	if (strchr(s,'/')) f2=true;
	if (strchr(s,'%')) f3=true;
	if ((!f1)&&(!f2)&&(!f3))
	{
		while(len-1>0&&s[len-1]=='0')
			len--;
		for (i=len-1;i>=0;i--)
			printf("%c",s[i]);
		printf("\n");
		return 0;
	}
	if (f1)
	{
		int p=strchr(s,'.')-s;
		int tmp=p;
		while(p-1>0&&s[p-1]=='0')
			p--;
		for (i=p-1;i>=0;i--)
			printf("%c",s[i]);
		printf(".");
		p=tmp+1;
		while(p<len-1&&s[p]=='0')
			p++;
		for (i=len-1;i>=p;i--)
			printf("%c",s[i]);
		printf("\n");
		return 0;
	}
	if (f2)
	{
		int p=strchr(s,'/')-s;
		int tmp=p;
		while(p-1>0&&s[p-1]=='0')
			p--;
		for (i=p-1;i>=0;i--)
			printf("%c",s[i]);
		printf("/");
		p=tmp+1;
		while(len-1>p&&s[len-1]=='0')
			len--;
		for (i=len-1;i>=p;i--)
			printf("%c",s[i]);
		printf("\n");
		return 0;
	}
	if (f3)
	{
		int p=strchr(s,'%')-s;
		while(p-1>0&&s[p-1]=='0')
			p--;
		for (i=p-1;i>=0;i--)
			printf("%c",s[i]);
		printf("%%\n");
		return 0;
	}
}
