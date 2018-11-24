#include<cstdio>
using namespace std;

int a[13];

int main()
{
	int n,i,ans=0;
	for (i=1;i<=10;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for (i=1;i<=10;i++)
		if (n+30>=a[i])
			ans++;
	printf("%d\n",ans);
	return 0; 
}
