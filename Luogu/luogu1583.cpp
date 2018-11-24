#include<cstdio>
#include<algorithm>
using namespace std;

struct node{int id,w;};
int e[13];
node a[20003];
bool cmp(node a,node b)
{
	if (a.w!=b.w)
		return a.w>b.w;
	return a.id<b.id;
}

int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for (i=1;i<=10;i++)
		scanf("%d",&e[i]);
	for (i=1;i<=n;i++)
	{
		a[i].id=i;
		scanf("%d",&a[i].w);
	}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++)
		a[i].w+=e[(i-1)%10+1];
	sort(a+1,a+n+1,cmp);
	for (i=1;i<m;i++)
		printf("%d ",a[i].id);
	printf("%d\n",a[m].id);
	return 0;
}
