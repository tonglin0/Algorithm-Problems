#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{int id,x;};
node a[5003];
bool cmp(node a,node b)
{
	if (a.x!=b.x)
		return a.x>b.x;
	return a.id<b.id;
}

int main()
{
	int n,i,m,s=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d%d",&a[i].id,&a[i].x);
	sort(a+1,a+n+1,cmp);
	m=(int)(1.5*m+0.1);
	for (i=1;i<=n;i++)
		if (a[i].x>=a[m].x)
			s=i;
	printf("%d %d\n",a[s].x,s);
	for (i=1;i<=s;i++)
		printf("%d %d\n",a[i].id,a[i].x);
	return 0;
	
}

