#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MN 8001
using namespace std;

int co[MN<<2],set[MN<<2];
int ql,qr;
int st[MN],top,ans[MN];

void pushdown(int p)
{
	if (set[p]>=0)
	{
		set[p<<1]=set[p<<1|1]=set[p];
		co[p<<1]=co[p<<1|1]=set[p];
		set[p]=-1;
	}
} 

void update(int p,int l,int r,int d)
{
	if (ql<=l&&qr>=r)
	{
		set[p]=d;
		co[p]=d;
		return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if (ql<=mid)
		update(p<<1,l,mid,d);
	if (qr>mid)
		update(p<<1|1,mid+1,r,d);
	//pushup(p);	父节点的co[]值无意义 
}

void query(int p,int l,int r)
{
	if (l==r)
	{
		st[top++]=co[p];
		return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	query(p<<1,l,mid);
	query(p<<1|1,mid+1,r);
}

int main()
{
	freopen("1610.in","r",stdin);
	freopen("1610.out","w",stdout);
	int n,i;
	bool isfirst=true;
	while(scanf("%d",&n)==1)
	{
		//build(1,1,n);     不必build()，直接memset即可 
		memset(co,-1,sizeof(co));
		memset(set,-1,sizeof(set));       //不能初始化为0
		/*if (!isfirst)
			printf("\n");
		else
			isfirst=false;*/
		for (i=1;i<=n;i++)
		{
			int d;
			scanf("%d%d%d",&ql,&qr,&d);
			ql++;    //用左端点表示线段 
			update(1,1,8000,d);
		}
		top=0;
		query(1,1,8000);    //全树遍历 
		memset(ans,0,sizeof(ans));
		for (i=0;i<=top-1;i++)
			if (st[i]>=0&&(i==0||st[i]!=st[i-1]))
				ans[st[i]]++;
		for (i=0;i<=8000;i++)
			if (ans[i]>0)
				printf("%d %d\n",i,ans[i]);
		printf("\n");
	}
	return 0;
}
