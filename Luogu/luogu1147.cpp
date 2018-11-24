#include<cstdio>
#define lint long long
using namespace std;

lint s[1000009];

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int m=(n+1)>>1;
	s[0]=0;
	for (i=1;i<=m;i++)
		s[i]=s[i-1]+i;
	i=0;j=1;
	while(i<=m&&j<=m)
	{
		if (s[j]-s[i]==n)
		{
			printf("%d %d\n",i+1,j);
			i++;j++;
		}
		else if (s[j]-s[i]>n)
			i++;
		else 
			j++;
	}
	return 0;
}
