#include<cstdio>
using namespace std;

bool vis[11];

int main()
{
	int i;
	for (i=192;i<=987;i++)
	{
		if (3*i>=1000) continue;
		for (int j=1;j<=9;j++)
			vis[j]=false;
		vis[i%10]=true;vis[i/10%10]=true;vis[i/100]=true;
		int a=i*2;
		vis[a%10]=true;vis[a/10%10]=true;vis[a/100]=true;
		a=i*3;
		vis[a%10]=true;vis[a/10%10]=true;vis[a/100]=true;
		bool flag=true;
		for (int j=1;j<=9;j++)
			if (!vis[j])
			{
				flag=false;
				break;
			}
		if (flag)
			printf("%d %d %d\n",i,i*2,i*3);
	}
	return 0;
}
