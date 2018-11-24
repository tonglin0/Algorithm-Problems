#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct node{int id,s,w;};
node a[200004];
node b[100003],c[100003];

bool cmp(node a,node b)
{
	if (a.s!=b.s)
		return a.s>b.s;
	return a.id<b.id;
}

int main()
{
	int n,i,r,q;
	scanf("%d%d%d",&n,&r,&q);
	for (i=1;i<=(n<<1);i++)
		scanf("%d",&a[i].s);
	for (i=1;i<=(n<<1);i++)
		scanf("%d",&a[i].w),a[i].id=i;
	sort(a+1,a+(n<<1)+1,cmp);
	b[n+1].s=-1;c[n+1].s=-1;
	for (int k=1;k<=r;k++)
	{
		int tb=0,tc=0;
		for (i=1;i<=n;i++)
			if (a[i<<1].w>a[(i<<1)-1].w)
			{
				a[i<<1].s++;
				b[++tb]=a[i<<1];
				c[++tc]=a[(i<<1)-1];
			}
			else
			{
				a[(i<<1)-1].s++;
				b[++tb]=a[(i<<1)-1];
				c[++tc]=a[i<<1];
			}
		tb=1;tc=1;
		for (i=1;i<=(n<<1);i++)
			if (b[tb].s>c[tc].s||(b[tb].s==c[tc].s&&b[tb].id<c[tc].id))
			{
				a[i]=b[tb];
				tb++;
			}
			else
			{
				a[i]=c[tc];
				tc++;
			}
	}
	printf("%d\n",a[q].id);
	return 0;
}
