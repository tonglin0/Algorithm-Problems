#include<iostream>
using namespace std;

int main()
{
	freopen("1085.in","r",stdin);
	int ms=-1,ans=0;
	for (int i=1;i<=7;i++)
	{
		int a,b;
		cin>>a>>b;
		if (a+b<=8)
			continue;
		if (a+b>ms)
		{
			ms=a+b;
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
