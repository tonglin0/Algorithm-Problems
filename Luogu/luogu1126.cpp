#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#define INF (int)1e9
using namespace std;

bool a[53][53];
vector<int> g[60003];
queue<int> q;
bool ins[60003];
int dis[60003];

int main()
{
	int n,i,j,k,m;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			int c;
			scanf("%d",&c);
			a[i][j]=(c==1)?false:true;
		}
	int sx,sy,tx,ty;
	char tc[3];
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	scanf("%s",tc);
	int op;
	if (tc[0]=='N')
		op=1;
	else if (tc[0]=='E')
		op=2;
	else if (tc[0]=='S')
		op=3;
	else if (tc[0]=='W')
		op=4;
	int s=sx*1000+sy*10+op;
	int t=tx*1000+ty*10;
	for (i=0;i<n*1000+m*10+4;i++)
		g[i].clear();
	for (i=1;i<=n-1;i++)
		for (j=1;j<=m-1;j++)
			for (k=1;k<=4;k++)
			{
				if (!a[i][j]||!a[i][j+1]||!a[i+1][j]||!a[i+1][j+1])
					continue;
				int st=i*1000+j*10+k;
				int nd;
				if (k==1)
				{
					nd=st+1;
					g[st].push_back(nd);
					nd=st+3;
					g[st].push_back(nd);
					for (int p=1;p<=3;p++)
					{
						int x=i-p;
						int y=j;
						if (x<1||a[x][y]==false||a[x][y+1]==false)
							break;
						nd=x*1000+y*10+k;
						g[st].push_back(nd);
					}
				}
				else if (k==2)
				{
					nd=st+1;
					g[st].push_back(nd);
					nd=st-1;
					g[st].push_back(nd);
					for (int p=1;p<=3;p++)
					{
						int x=i,y=p+j;
						if (y>m-1||a[x][y+1]==false||a[x+1][y+1]==false)
							break;
						nd=x*1000+y*10+k;
						g[st].push_back(nd);
					}
				}
				else if (k==3)
				{
					nd=st+1;
					g[st].push_back(nd);
					nd=st-1;
					g[st].push_back(nd);
					for (int p=1;p<=3;p++)
					{
						int x=i+p,y=j;
						if (x>n-1||a[x+1][y]==false||a[x+1][y+1]==false)
							break;
						nd=x*1000+y*10+k;
						g[st].push_back(nd);
					}
				}
				else if (k==4)
				{
					nd=st-3;
					g[st].push_back(nd);
					nd=st-1;
					g[st].push_back(nd);
					for (int p=1;p<=3;p++)
					{
						int x=i,y=j-p;
						if (y<1||a[x][y]==false||a[x+1][y]==false)
							break;
						nd=x*1000+y*10+k;
						g[st].push_back(nd);
					}
				}
			}
	memset(ins,0,sizeof(ins));
	for (i=0;i<n*1000+m*10+4;i++)
		dis[i]=INF;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		ins[u]=false;
		for (i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if (dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				if (!ins[v])
				{
					q.push(v);
					ins[v]=true;
				}
			}
		}
	}
	int ans=INF;
	for (i=1;i<=4;i++)
		ans=min(ans,dis[t+i]);
	if (ans==INF)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}
