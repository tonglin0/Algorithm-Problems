#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 200020
using namespace std;

struct node{
         int l,r,s;
       };
node t[MN];
char ch[20];
int ql,qr;

void build(int p,int a,int b)
{
  if (a==b)
  {
    t[p].l=t[p].r=a;
    t[p].s=0;
  }
  else
  {
    t[p].l=a;
    t[p].r=b;
    t[p].s=0;
    int mid=(a+b)>>1;
    build(p<<1,a,mid);
    build((p<<1)+1,mid+1,b);
  }
}

void add_p(int p,int l,int d)
{
  if (t[p].l==l&&t[p].r==l)
  {
    t[p].s+=d;
    return ;
  }
  else
  {
    int mid=(t[p].l+t[p].r)>>1;
    if (l<=mid)
      add_p(p<<1,l,d);
    else
      add_p((p<<1)+1,l,d);
    t[p].s=t[p<<1].s+t[(p<<1)+1].s;
  }
}

int query(int p)
{
  if (ql<=t[p].l&&qr>=t[p].r)
    return t[p].s;
  int mid=(t[p].l+t[p].r)>>1;
  int ans=0;
  if (ql<=mid)
    ans+=query(p<<1);
  if (qr>mid)
    ans+=query((p<<1)+1);
  return ans;
}

int main()
{
  freopen("1166.in","r",stdin);
  freopen("1166.out","w",stdout);
  int T,i,j,k,m,n,ii;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    scanf("%d",&n);
    printf("Case %d:\n",ii);
    build(1,1,n);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&k);
      add_p(1,i,k);
    }
    scanf("%s",ch);
    while(strcmp(ch,"End")!=0)
    {
    if (ch[0]=='A')
    {
      scanf("%d%d",&m,&k);
      add_p(1,m,k);
    }
    else if (ch[0]=='S')
    {
      scanf("%d%d",&m,&k);
      add_p(1,m,-k);
    }
    else
    {
      scanf("%d%d",&ql,&qr);
      printf("%d\n",query(1));
    }
    scanf("%s",ch);
    }
  }
  return 0;
}
