#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lint long long
#define MOD 20100501
using namespace std;

bool vis[2000003];
lint c[1000000];
lint s[1000000];
lint p=0;
lint ml;

lint pow_mod(lint a,lint b,lint c)
{
  lint t=a,ans=1;
  while(b)
  {
    if (b&1)
      ans=ans*t%MOD;
    b>>=1;
    t=t*t%MOD;
  }
  return ans;
}

void add(lint n,lint sig)
{
  for (int i=1;i<=p;i++)
  {
  	if (c[i]>n)
  	  break;
    lint t=n;
    while(t)
    {
      s[i]+=(sig*(t/c[i]));
      t/=c[i];
	}
  }
}

int main()
{
  freopen("3398.in","r",stdin);
  freopen("3398.out","w",stdout);
  lint i,j,k;
  lint n,m,ca;
  memset(vis,0,sizeof(vis));
  p=0;
  for (i=2;i<=2000000;i++)
    if (!vis[i])
    {
      c[++p]=i;
      for (j=i*i;j<=2000000;j+=i)
        vis[j]=true;
	}
  scanf("%I64d",&ca);
  while(ca--)
  {
    scanf("%I64d%I64d",&n,&m);
    if (n<m)
    {
      printf("0\n");
      continue;
	}
    for (i=1;i<=p;i++)
	  s[i]=0;
    add(n+m,1);
    add(n,-1);
    add(m,-1);
    lint s1=1;
    for (i=1;i<=p;i++)
      if (s[i]>0)
        s1=s1*pow_mod(c[i],s[i],MOD)%MOD;
	for (i=1;i<=p;i++)
      s[i]=0;
    add(n+m,1);
    add(m-1,-1);
    add(n+1,-1);
    lint s2=1;
    for (i=1;i<=p;i++)
      if (s[i]>0)
        s2=s2*pow_mod(c[i],s[i],MOD)%MOD;
	printf("%I64d\n",(((s1-s2)%MOD+MOD)%MOD));
  }
  return 0;
}
