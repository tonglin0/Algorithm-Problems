#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int a[10002][4];

int main()
{
	int n,i,x1,x2,y1,x,y,y2;
	scanf("%d",&n);
	int ans=-1;
	for (i=1;i<=n;i++)
	{
		int w,h;
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&w,&h);
		a[i][2]=a[i][0]+w;a[i][3]=a[i][1]+h;
	}
	scanf("%d%d",&x,&y);
	for (i=1;i<=n;i++)
		if (x>=a[i][0]&&y>=a[i][1]&&x<=a[i][2]&&y<=a[i][3])
			ans=i;
	printf("%d\n",ans);
	return 0;
}
