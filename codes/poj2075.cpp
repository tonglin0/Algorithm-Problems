#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> ss;
string s;
char sa[100];
struct node
{
  int u,v;
  double w;/*
  bool operator < (const node &a)
  {
    return w<a.w; 
  }  */
};
int fa[10000];
vector<node> q;

bool cmp(node a,node b)
{
  return a.w<b.w;
}
int find(int x)
{
  if (fa[x]==x) return x;
  fa[x]=find(fa[x]);
  return fa[x];
}
int main()
{
  freopen("2075.in","r",stdin);
  freopen("2075.out","w",stdout);
  double ans=0,pro;
  scanf("%lf",&pro);
  int i,j,k,m,n;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%s",sa);
    s=sa;
    ss.push_back(s);
  }
  scanf("%d",&m);
  for (i=1;i<=m;i++)
  {
    int d1,d2;
    double w;
    scanf("%s",sa);
    s=sa;
    for (j=0;j<ss.size();j++)
      if (ss[j]==s)
      {
        d1=j;
        break;
      }
    scanf("%s",sa);
    s=sa;
    for (j=0;j<ss.size();j++)
      if (ss[j]==s)
      {
        d2=j;
        break;
      }
    scanf("%lf",&w);
    node x;
    //x=(node){d1,d2,w};
    x.u=d1;
    x.v=d2;
    x.w=w;
    q.push_back(x);
  }
  sort(q.begin(),q.end(),cmp);
  int ing=0;
  for (i=1;i<=n;i++) fa[i]=i;
  i=0;
  while(ing<n-1)
  {
    int u=q[i].u,v=q[i].v;double w=q[i].w;
    if (find(u)!=find(v))
    {
      fa[find(u)]=find(v);
      ing++;
      ans+=w;
    }
    i++;
  }
  if (ans>pro) printf("Not enough cable\n"); 
  else printf("Need %.1lf miles of cable",ans);
  return 0; 
} 
