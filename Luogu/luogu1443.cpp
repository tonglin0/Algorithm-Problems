#include<cstdio>
#include<algorithm>
#include<queue>
#define INF (int)1e9
using namespace std;

struct node{int x,y,s;};
queue<node> q;
//bool vis[203][203];
int ans[203][203];
int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,-2,-1,1,2};

int main()
{
	int n,m,i,j,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	//memset(vis,0,sizeof(vis));
	node t;t.x=x;t.y=y;t.s=0;
	for (i=0;i<=n+1;i++)
		for (j=0;j<=m+1;j++)
			ans[i][j]=INF;
	q.push(t);ans[x][y]=0;
	while(!q.empty())
	{
		node c=q.front();q.pop();
		x=c.x;y=c.y;int s=c.s;
		for (i=0;i<8;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if (tx<1||ty<1||tx>n||ty>m) 
				continue;
			if (s+1<ans[tx][ty])
			{
				t.x=tx;t.y=ty;t.s=s+1;
				q.push(t);
				ans[tx][ty]=s+1;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
			if (ans[i][j]!=INF)
				printf("%-5d",ans[i][j]);
			else
				printf("%-5d",-1);
		printf("\n");
	}
	return 0;
}
