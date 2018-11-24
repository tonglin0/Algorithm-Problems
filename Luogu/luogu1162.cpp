#include<cstdio>
#include<cstring>
using namespace std;

int a[303][303];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool vis[303][303];

bool check(int x,int y)
{
	vis[x][y]=true;
	bool flag=true;
	for (int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if (vis[tx][ty])
			continue;
		if (a[tx][ty]==7)
			return false;
		if (a[tx][ty]==0)
			flag=flag&&check(tx,ty);
		if (!flag)
			return false;
	}
	return flag;
}

void floodfill(int x,int y)
{
	a[x][y]=2;
	for (int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if (a[tx][ty]==0)
			floodfill(tx,ty);
	}
}

int main()
{
	int n,i,x,j,y;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (i=0;i<=n+1;i++)
	{
		a[0][i]=7;
		a[i][0]=7;
		a[n+1][i]=7;
		a[i][n+1]=7;
	}
	bool flag=false;
	for (i=1;i<=n&&!flag;i++)
		for (j=1;j<=n;j++)
			if (a[i][j]==0)
			{
				for (int ti=0;ti<=n+1;ti++)
					for (int tj=0;tj<=n+1;tj++)
						vis[ti][tj]=0;
				if (check(i,j))
				{
					x=i;
					y=j;
					flag=true;
					break;
				}
			}
	//printf("%d %d\n",x,y);
	//return 0;
	
	floodfill(x,y);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n-1;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][n]);
	}
	return 0;
}
