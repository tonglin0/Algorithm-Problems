#include<iostream>
using namespace std;

int main()
{
	freopen("1089.in","r",stdin);
	int inh=0,dep=0,i,a;
	for (i=1;i<=12;i++)
	{
		cin>>a;
		inh+=300;
		if (inh<a)
		{
			cout<<"-"<<i<<endl;
			return 0;
		}
		dep+=((inh-a)/100*100);
		inh-=((inh-a)/100*100);
		inh-=a;
	}
	inh+=(dep*6/5);
	cout<<inh<<endl;
	return 0;
}
