#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define MOD 10007
using namespace std;

char st[104];
int ch[6005][27];
bool mk[6005];
int val[6005];
int next[6005];
int tot=0;
int f[104][6005];

void insert(char *s)
{
	int len=strlen(s);
	int u=0;
	for (int i=0;i<len;i++)
	{
		int c=s[i]-'A';
		if (!ch[u][c])
		{
			ch[u][c]=++tot;
			memset(ch[tot],0,sizeof(ch[tot]));
			val[tot]=0;
		}
		u=ch[u][c];
	}
	val[u]=1;
}

void acgetfail()
{
	mk[0]=false;next[0]=0;
	queue<int> q;
	for (int i=0;i<26;i++)
		if (ch[0][i])
		{
			int u=ch[0][i];
			q.push(u);
			next[u]=0;
			if (val[u])
				mk[u]=true;
			else 
				mk[u]=false;
		}
	while(!q.empty())
	{
		int r=q.front();q.pop();
		for (int c=0;c<26;c++)
		{
			int  u=ch[r][c];
			if (!u)
			{
				ch[r][c]=ch[next[r]][c];
				continue;
			}
			q.push(u);
			int v=next[r];
			next[u]=ch[v][c];
			if (val[u]||mk[next[u]])
				mk[u]=true;
		    else
				mk[u]=false;
		}
	}
}

int main()
{
	freopen("1030.in","r",stdin);
	freopen("1030.out","w",stdout);
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%s",st);
		insert(st);
	}
	acgetfail();
	int ans=1;
	for (i=1;i<=m;i++)
		ans=ans*26%MOD;
	int ans2=0;
	f[0][0]=1;
	for (i=0;i<=m;i++)
		for (j=0;j<=tot;j++)
			if (!mk[j])
			    for (k=0;k<26;k++)
				    if (!mk[ch[j][k]])
						f[i+1][ch[j][k]]=(f[i+1][ch[j][k]]+f[i][j])%MOD;
	for (i=0;i<=tot;i++)
		ans2=(ans2+f[m][i])%MOD;
	ans=(ans-ans2+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}