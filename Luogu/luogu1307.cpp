#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;

char s[20];

int main()
{
	int n,i,len;
	scanf("%d",&n);
	if (n<0) printf("-");
	n=abs(n);
	sprintf(s,"%d",n);
	len=strlen(s)-1;
	while(len>0&&s[len]=='0')
		len--;
	while(len>=0)
	{
		printf("%c",s[len]);//putchar(s[len]);
		len--;
	}
	return 0;
}
