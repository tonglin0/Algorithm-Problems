#include<cstdio>
#include<vector>
#include<algorithm>
#define MN 303
#define INF (int)1e9
using namespace std;

struct edge{
	int u,v,w;
	bool operator < (const edge& b) const{
		return w<b.w;
	}
};
edge es[MN*MN];
int fa[MN];

int find(int x)
{
	if (fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int main()
{
	int n,i,j,m;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
		scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);
	sort(es+1,es+m+1);
	int l=1,r=m;
	//while(l<r)
	//{
		int mid=l+r>>1;
		for (i=1;i<=n;i++)
			fa[i]=i;
		int cnt=0;
		for (i=1;i<=m;i++)
		{
			int x=find(es[i].u),y=find(es[i].v);
			if (x!=y)
			{
				fa[x]=y;
				cnt++;
			}
			if (cnt==n-1)
			{
				l=i;
				break;
			}
		}
		/*if (cnt==n-1)
			r=mid;
		else
			l=mid+1;
	}*/
	printf("%d %d\n",n-1,es[l].w);
	return 0;
}
