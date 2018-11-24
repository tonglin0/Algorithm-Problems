#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char st[13][13];
struct node{
	int v,c;
};
node a[103];
int k;
bool cmp(node a,node b){return a.c<b.c;}
bool f[100009];

int get_color(char *s)
{
  for (int i=1;i<=k;i++)
    if (strcmp(s,st[i])==0)
      return i;
  return 0;
}

int main()
{
  freopen("3211.in","r",stdin);
  freopen("3211.out","w",stdout);
  int n,i,j,m;
  while(scanf("%d%d",&k,&n)==2&&(k+n))
  {
	for (i=1;i<=k;i++)
      scanf("%s",st[i]);
    for (i=1;i<=n;i++)
    {
      char ch[13];
      scanf("%d%s",&a[i].v,ch);
      a[i].c=get_color(ch);
	}
	sort(a+1,a+n+1,cmp);
	int ii=1;
	int N=n;
	int ans=0;
	while(ii<=N)
	{
	  n=ii;
	  //memset(f,0,sizeof(f));
	  while(n+1<=N&&a[n+1].c==a[n].c)
	    n++;
	  int sum=0;
	  for (i=ii;i<=n;i++)
	    sum+=a[i].v;
	  m=sum>>1;
	  for (i=1;i<=(sum>>1)+1;i++)
	    f[i]=false;
	  f[0]=true;
	  for (i=ii;i<=n;i++)
	    for (j=m;j>=a[i].v;j--)
	      f[j]=f[j]||f[j-a[i].v];
	  for (i=m;i>=0;i--)
	    if (f[i])
	    {
	      ans+=(sum-i);
	      break;
		}
	  ii=n+1;
	}
	printf("%d\n",ans);
  }
  return 0;
}
