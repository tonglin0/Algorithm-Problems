#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

struct node{int id;string s;};
node a[22];
bool cmp(node a,node b)
{
	if (a.s.size()!=b.s.size())
		return a.s.size()<b.s.size();
	return a.s<b.s;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	printf("%d\n",a[n].id);
	cout<<a[n].s<<endl;
	return 0;
}
