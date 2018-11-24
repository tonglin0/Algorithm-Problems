#include<cstdio>
#include<cstring>
using namespace std;

int a[103];

int main()
{
	int t=0,n,m,i,k;
	memset(a,-1,sizeof(a));
	scanf("%d%d",&m,&n);
	int ans=0;
	while(n--)
	{
		bool flag=false;
		scanf("%d",&k);
		for (i=0;i<m;i++)
			if (a[i]==k)
			{
				flag=true;
				break;
			}
		if (flag) continue;
		a[t]=k;
		ans++;
		t=(t+1)%m;
	}
	printf("%d\n",ans);
	return 0; 
}
