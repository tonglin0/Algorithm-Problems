#include<cstdio>
#include<algorithm>
using namespace std;

struct point{int x,y;};
bool cmp(point a,point b)
{
	return a.y<b.y;
}

point a[5003];

int main()
{
	int t,b,n,s,i;
	scanf("%d%d",&n,&s);
	scanf("%d%d",&t,&b);
	b+=t;
	int top=0;
	for (i=1;i<=n;i++)
	{
		int xi,yi;
		scanf("%d%d",&xi,&yi);
		if (xi<=b)
		{
			a[++top].x=xi;
			a[top].y=yi;
		}
	}
	//printf("%d\n",top);
	sort(a+1,a+top+1,cmp);
	//for (i=1;i<=top;i++)
	//	printf("%d ",a[i].y);
	//printf("\n");
	int ans=0;
	for (i=1;i<=top;i++)
		if (s>=a[i].y)
		{
			ans++;
			s-=a[i].y;
		}
	printf("%d\n",ans);
	return 0;
}
