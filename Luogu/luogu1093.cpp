#include<cstdio>
#include<algorithm>
using namespace std;

struct node{int a,b,c,s,id;};
node a[200003];

bool cmp(node a,node b)
{
	if (a.s!=b.s)
		return a.s>b.s;
	if (a.a!=b.a)
		return a.a>b.a;
	return a.id<b.id;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		a[i].s=a[i].a+a[i].b+a[i].c;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=5;i++)
		printf("%d %d\n",a[i].id,a[i].s);
	return 0;
}
