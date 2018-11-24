#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct node{int x,y;};
char st[1003];
bool a[1003][1003];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int vis[1003][1003];
int cnt,n;
int ans[1003][1003];
/*
void dfs(int x,int y)
{
	vis[x][y]=2;
	cnt++;
	for (int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if (tx<1||tx>n||ty<1||ty>n)
			continue;
		if (vis[tx][ty]==0&&a[x][y]==(!a[tx][ty]))
			dfs(tx,ty);
	}
}

void dfs2(int x,int y)
{
	ans[x][y]=cnt;
	vis[x][y]=1;
	for (int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if (tx<1||tx>n||ty<1||ty>n)
			continue;
		if (vis[tx][ty]==2)
			dfs2(tx,ty);
	}
}*/

void bfs2(int x,int y)
{
	ans[x][y]=cnt;
	vis[x][y]=1;
	queue<node> q;
	node t;t.x=x;t.y=y;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();q.pop();
		for (int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if (tx<1||tx>n||ty<1||ty>n)
				continue;
			if (vis[tx][ty]==2)
			{
				vis[tx][ty]=1;
				ans[tx][ty]=cnt;
				node tmp;tmp.x=tx;tmp.y=ty;
				q.push(tmp);
			}
		}
	}
}

void bfs(int x,int y)
{
	queue<node> q;
	vis[x][y]=2;
	cnt++;
	node t;t.x=x;t.y=y;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();q.pop();
		for (int i=0;i<4;i++)
		{
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if (tx<1||tx>n||ty<1||ty>n)
				continue;
			if (vis[tx][ty]==0&&a[t.x][t.y]==(!a[tx][ty]))
			{
				vis[tx][ty]=2;
				cnt++;
				node tmp;tmp.x=tx;tmp.y=ty;
				q.push(tmp);
			}
		}
	}
}

int main()
{
	freopen("1141.in","r",stdin);
	freopen("1141.out","w",stdout);
	int qus,i,j;
	scanf("%d%d",&n,&qus);
	for (i=1;i<=n;i++)
	{
		scanf("%s",st);
		for (j=0;j<n;j++)
			if (st[j]=='0')
				a[i][j+1]=false;
			else
				a[i][j+1]=true;
	}
	for (i=0;i<=n+1;i++)
		for (j=0;j<=n+1;j++)
			vis[i][j]=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (vis[i][j]==0)
			{
				cnt=0;
				bfs(i,j);
				bfs2(i,j);
			}
	while(qus--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",ans[x][y]);
	}
	return 0;
}
