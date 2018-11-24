#include<cstdio>
#include<cstring>
using namespace std;

char s1[10],s2[10];

int main()
{
	scanf("%s%s",s1,s2);
	int m1=1,m2=1,i,len1,len2;
	len1=strlen(s1);
	len2=strlen(s2);
	for (i=0;i<len1;i++)
		m1=m1*(s1[i]-'A'+1)%47;
	for (i=0;i<len2;i++)
		m2=m2*(s2[i]-'A'+1)%47;
	if (m1==m2)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}

