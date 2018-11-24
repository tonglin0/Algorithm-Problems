#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a;
	double ans=0;
	cin>>a;
	if (a<=150)
	{
		ans=a*0.4463;
		//cout<<ans<<endl;
		printf("%.1lf\n",ans);
		return 0;
	}
	ans+=150*0.4463;
	if (a<=400)
	{
		ans+=(a-150)*0.4663;
		printf("%.1lf\n",ans);
		//cout<<ans<<endl;
		return 0;
	}
	ans+=250*0.4663;
	ans+=(a-400)*0.5663;
	printf("%.1lf\n",ans);
	//cout<<ans<<endl;
	return 0;
}
