#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;
struct Edge
{
	int v,wei,pre;
	Edge(){}
	Edge(int a,int b,int c){v=a;pre=b;wei=c;}
}edge[N*2];

int head[N],tot,n,m;
int dx[N],dy[N],d[N];
int q1l,q2l,q1r,q2r,ql,qr;
int q1[N],q2[N];

void addEdge(int u,int v,int wei)
{
	edge[tot]=Edge(v,head[u],wei);
	head[u]=tot++;
}
void dfs(int u,int fa,int dis,int *d)
{
	for(int i=head[u];i!=-1;i=edge[i].pre)
	{
		int v=edge[i].v,wei=edge[i].wei;
		if(v!=fa) dfs(v,u,d[v]=dis+wei,d);
	}
}

void insert_q2(int k)
{
  while(q2r>=q2l&&d[q2[q2r]]<=d[k])
    q2r--;
  q2[++q2r]=k;
}

void insert_q1(int k)
{
  while(q1r>=q1l&&d[q1[q1r]]>=d[k])
    q1r--;
  q1[++q1r]=k;
}

int main()
{
	int k;
	freopen("3162.in","r",stdin);
	freopen("3162_std.out","w",stdout);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		tot=0;
		memset(head,-1,sizeof(head));

		int x,y,i;
		for(int i=2;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			addEdge(i,x,y);
			addEdge(x,i,y);
		}
		dfs(1,0,d[1]=0,d);
		for(x=1,i=2;i<=n;i++)
			if(d[i]>d[x]) x=i;
		dfs(x,0,dx[x]=0,dx);
		for(y=1,i=2;i<=n;i++)
			if(dx[i]>dx[y]) y=i;
		dfs(y,0,dy[y]=0,dy);
		for(int i=1;i<=n;i++) d[i]=max(dx[i],dy[i]);
		ql=1;qr=0;
  q1l=1;q1r=0;
  q2l=1;q2r=0;
  int ans=0;
  while(qr<n)
  {
    qr++;
    insert_q2(qr);
    insert_q1(qr);
    while(ql<qr&&d[q2[q2l]]-d[q1[q1l]]>k)
    {
	  ql=min(q1[q1l],q2[q2l])+1;
      while(q1l<=q1r&&q1[q1l]<ql)
        q1l++;
      while(q2l<=q2r&&q2[q2l]<ql)
        q2l++;
	}
	ans=max(ans,qr-ql+1);
  }
  printf("%d\n",ans);
	}
	return 0;
}

