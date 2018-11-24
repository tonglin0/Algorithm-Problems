#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#define MN 503
#define INF (int)1e9
using namespace std;

int a[MN][3];
struct edge{
	int u,v;
	double w;
};
int fa[MN];
edge es[MN*MN/2];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int find(int x)
{
	if (fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int main()
{
	int n,p,i,j;
	scanf("%d%d",&p,&n);
	int top=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][1],&a[i][2]);
		for (j=1;j<i;j++)
		{
			top++;
			es[top].u=i;
			es[top].v=j;
			es[top].w=dist(a[i][1],a[i][2],a[j][1],a[j][2]);
		}
	}
	sort(es+1,es+top+1,cmp);
	int l=1,r=top;
	//while(l<r)
	//{
		int cnt=0;
		int mid=l+r>>1;
		for (i=1;i<=n;i++)
			fa[i]=i;
		for (i=1;i<=top;i++)
		{
			int x=find(es[i].u),y=find(es[i].v);
			if (x!=y)
			{
				fa[x]=y;
				cnt++;
			}
			if (cnt>=n-p)
			{
				l=i;
				break;
			}
		}
		/*if (cnt>=n-p)
			r=mid;
		else
			l=mid+1;*/
	//}
	printf("%.2lf\n",es[l].w);
	return 0;
}
