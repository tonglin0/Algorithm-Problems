#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

char s[20];

int main()
{
	int len,i,m=0,n=0;
	scanf("%s",s);
	len=strlen(s);
	for (i=0;i<len-2;i++)
		if (isdigit(s[i]))
		{
			n++;
			m=m+(s[i]-'0')*n;
		}
	m%=11;
	if ((m==10&&s[len-1]=='X')||(m<10&&(s[len-1]-'0')==m))
		printf("Right\n");
	else
	{
		for (i=0;i<len-1;i++)
			printf("%c",s[i]);
		if (m<10)
			printf("%d\n",m);
		else
			printf("X\n");
	}
	return 0;
}
