#include<cstdio>
#include<cstring>
using namespace std;

char s[10004];

int main()
{
	int n,len;
	scanf("%d",&n);
	scanf("%s",s);
	len=strlen(s);
	for (int i=0;i<len;i++)
		s[i]=(s[i]-'a'+n)%26+'a';
	printf("%s\n",s);
	return 0;	
}

