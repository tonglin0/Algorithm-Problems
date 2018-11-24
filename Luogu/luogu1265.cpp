#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 1e9
#define MN 5001
using namespace std;

int p[MN][2];
double dis[MN];
bool vis[MN];

double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&p[i][0],&p[i][1]);
	for (i=2;i<=n;i++)
		dis[i]=INF;
	int mj;
	double mi;
	double ans=0;
	for (i=1;i<=n;i++)
	{
		mi=INF;
		for (j=1;j<=n;j++)
			if (!vis[j]&&dis[j]<mi)
			{
				mj=j;
				mi=dis[j];
			}
		ans+=mi;
		vis[mj]=true;
		for (j=1;j<=n;j++)
		{
			double t=dist(p[mj][0],p[mj][1],p[j][0],p[j][1]);
			if (t<dis[j])
				dis[j]=t;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
