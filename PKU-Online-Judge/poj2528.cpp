#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MN 80009
using namespace std;

bool vis[MN];
int ll[MN],rr[MN];
struct node{int id,s,p;};
node q[MN];
int sl,sr;
bool cmp(node a,node b){return a.s<b.s;}
int set[MN],co[MN];

void pushdown(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  set[lc]=set[rc]=set[p];
  co[lc]=co[rc]=set[p];
  set[p]=0;
}

void update(int p,int l,int r,int k)
{
  if (sl<=l&&sr>=r)
  {
    co[p]=k;
    set[p]=k;
    return ;
  }
  int mid=(l+r)>>1;
  if (set[p])
    pushdown(p,l,r);
  if (sl<=mid) 
    update(p<<1,l,mid,k);
  if (sr>mid)
    update(p<<1|1,mid+1,r,k);
  if (co[p<<1]!=-1&&co[p<<1]==co[p<<1|1])
    co[p]=co[p<<1];
  else
    co[p]=-1;
}

void query(int p,int l,int r)
{
  if (co[p]>=0)
  {
    vis[co[p]]=true;
    return ;
  }                             
  int mid=(l+r)>>1;
  query(p<<1,l,mid);
  query(p<<1|1,mid+1,r);
}

int main()
{
  freopen("2528.in","r",stdin);
  freopen("2528.out","w",stdout);
  int T,n,i,j,k,m;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&n);
    memset(q,0,sizeof(q));
    memset(ll,0,sizeof(ll));
    memset(rr,0,sizeof(rr));
    memset(vis,0,sizeof(vis));
    m=0;
    for (i=1;i<=n;i++)
    {
      node a;
      a.id=i;
      a.p=1;
      scanf("%d",&a.s);
      q[++m]=a;
      a.p=2;
      scanf("%d",&a.s);
      q[++m]=a;
    }
    sort(q+1,q+m+1,cmp);
    int pre=-1;
    int t=0;
    for (i=1;i<=m;i++)
    {
      //if (i!=1&&(q[i].s-1)!=q[i-1].s)
        //t++;                            WA before deleting this para
        //                                However, you can't get the ¡¾real¡¿ correct answer if you delete this para.
      if (q[i].s==pre)
      {
        q[i].s=t;
      }
      else
      {
        pre=q[i].s;
        q[i].s=++t;
      }
    }
    for (i=1;i<=m;i++)
      if (q[i].p==1)
        ll[q[i].id]=q[i].s;
      else
        rr[q[i].id]=q[i].s;
    memset(set,0,sizeof(set));
    memset(co,0,sizeof(co));
    for (i=1;i<=n;i++)
    {
      sl=ll[i];
      sr=rr[i];
      update(1,1,t,i);
    }
    query(1,1,t);
    int ans=0;
    for (i=1;i<=n;i++)
      if (vis[i])
        ans++;
    printf("%d\n",ans);
  }
  return 0;
}
