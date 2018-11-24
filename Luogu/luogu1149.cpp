#include<cstdio>
#include<cstring>
using namespace std;

const int a[]={6,2,5,5,4,5,6,3,7,6};

int num(int n)
{
	if (n==0) return 6;
	int s=0;
	while(n)
	{
		s+=a[n%10];
		n/=10;
	}
	return s;
}

int main()
{
	int n,i,j;
	int ans=0,k;
	scanf("%d",&n);
	n-=4;
	for (i=0;i<=2111;i++)
		for (j=0;j<=711;j++)
		{
			k=i+j;
			if (num(i)+num(j)+num(k)==n)
				ans++;//printf("%d %d\n",i,j);
		}
	printf("%d\n",ans);
	return 0;
}
