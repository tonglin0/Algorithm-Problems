#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

char st[22][1003];
char s[3];
int ls[22];
int vis[22];
int dis[22][22];
vector<int> g[23];
int ans=0;
int n;

void dfs(int k,int u,int s)
{
	/*if (k==n)
	{
		ans=max(ans,s);
		return ;
	}*/
	ans=max(ans,s);
	for (int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if (vis[v]>=2) continue;
		vis[v]++;
		dfs(k+1,v,s+ls[v]-dis[u][v]);
		vis[v]--;
	}
}

bool check(int a,int b,int k)
{
	for (int i=0;i<k;i++)
		if (st[b][i]!=st[a][ls[a]-k+i])
			return false;
	return true;
}

bool legal(int a,int b)
{
	int i,la=ls[a],lb=ls[b];
	int s=0;
	for (i=1;i<min(la,lb);i++)
		if (check(a,b,i))
		{
			s=i;
			break;
		}
	//if (a!=b&&s==0&&check(a,b,min(la,lb)))
	//	s=min(la,lb);
	if (s==0||s==la||s==lb)
		return false;
	dis[a][b]=s;
	return true;
}

int main()
{
	freopen("1019.in","r",stdin);
	freopen("1019.out","w",stdout);
	int i,j;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%s",st[i]);
	for (i=1;i<=n;i++)
		ls[i]=strlen(st[i]);
	for (i=0;i<=n;i++)
		g[i].clear();
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			if (legal(i,j))
				g[i].push_back(j);
		}
	
	/*for (i=1;i<=n;i++)
	{
		for (j=0;j<g[i].size();j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}
	return 0;*/
	
	scanf("%s",s);
	for (i=1;i<=n;i++)
		if (s[0]==st[i][0])
			g[0].push_back(i);
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}

