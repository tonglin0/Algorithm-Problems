#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
bool vis[7][7];
int n,m,sx,sy,tx,ty;
int ans=0;

void dfs(int x,int y)
{
	if (x==tx&&y==ty)
	{
		ans++;
		return ;
	}
	for (int i=0;i<4;i++)
	{
		int fx=x+dx[i];
		int fy=y+dy[i];
		if (fx>=1&&fx<=n&&fy>=1&&fy<=m&&!vis[fx][fy])
		{
			vis[fx][fy]=true;
			dfs(fx,fy);
			vis[fx][fy]=false;
		}
	}
}

int main()
{
	int t,i;
	scanf("%d%d%d",&n,&m,&t);
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vis[x][y]=true;
	}
	vis[sx][sy]=true;
	dfs(sx,sy);
	printf("%d\n",ans);
	return 0; 
}
