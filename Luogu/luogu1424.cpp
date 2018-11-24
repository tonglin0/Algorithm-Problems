#include<cstdio>
using namespace std;

int main()
{
	int n,i,x,ans=0;
	scanf("%d%d",&x,&n);
	x%=7;
	while(n--)
	{
		if (!((x==0||x==6)))
			ans+=250;
		x=(x+1)%7;
	}
	printf("%d\n",ans);
	return 0;
}
