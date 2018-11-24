#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

string a[22];

bool cmp(string a,string b)
{
	return (a+b)>(b+a);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++)
		cout<<a[i];
	printf("\n");
	return 0;
}
