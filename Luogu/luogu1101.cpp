#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char st[102][102];
bool vis[102][102];

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int main()
{
	freopen("1101.in","r",stdin);
	freopen("1101.out","w",stdout);
	int n,i,j,p;
	string sd="yizhong";
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%s",st[i]);
	memset(vis,0,sizeof(vis));
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (st[i][j]=='y'&&!vis[i][j])
			{
				for (p=0;p<8;p++)
				{
					int x=i,y=j;
					string s="y";
					for (int k=1;k<7;k++)
					{
						x=x+dx[p];
						y=y+dy[p];
						if (x>=n||x<0||y>=n||y<0||vis[x][y])
							break;
						s=s+st[x][y];
					}
					if (s==sd)
					{
						x=i;y=j;vis[x][y]=true;
						for (int k=1;k<7;k++)
						{
							x=x+dx[p];
							y=y+dy[p];
							vis[x][y]=true;
						}
						break;
					}
				}
			}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (vis[i][j])
				printf("%c",st[i][j]);
			else
				printf("*");
		printf("\n");
	}
	return 0;
}
