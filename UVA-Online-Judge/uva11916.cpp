#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<cmath>
#include<algorithm>
#define lint long long
#define MOD 100000007
#define HS 100007
using namespace std;

lint Max(lint a,lint b){return a>b?a:b;}
set<pair<lint,lint> > ss;
lint x[509],y[509];
int top;
lint hash[HS+2],head[HS+2],id[HS+2],next[HS+2];

lint pow_mod(lint a,lint b,lint c)
{
  lint t=a%c,ans=1;
  while(b)
  {
    if (b&1)
      ans=ans*t%c;
    b>>=1;
    t=t*t%c;
  }
  return ans;
}

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

lint rev(lint a,lint n)
{
  lint d,x,y;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

void insert(lint x,lint y)
{
  lint k=x%HS;
  hash[top]=x;
  id[top]=y;
  next[top]=head[k];
  head[k]=top++;
}

lint find(int x)
{
  lint k=x%HS;
  for (lint i=head[k];i!=-1;i=next[i])
    if (hash[i]==x)
      return id[i];
  return 0;
}

lint log_mod(lint a,lint b,lint c)
{
  lint v,i,j,m;
  if (b==1)
    return 0;
  top=1;
  memset(head,-1,sizeof(head));
  m=ceil(sqrt(c+0.5));
  v=1;
  for (i=1;i<m;i++)
  {
    v=v*a%c;
    if (!find(v))
      insert(v,i);
  }
  v=v*a%c;
  v=rev(v,c);
  lint tmp;
  for (i=0;i<m;i++)
  {
    if (b==1)
      return i*m;
	if ((tmp=find(b))!=0)
      return i*m+tmp;
    b=b*v%c;
  }
  return -1;
}

int main()
{
  freopen("11916.in","r",stdin);
  freopen("11916.out","w",stdout);
  lint n,i,j,k,m,b,ca,r;
  scanf("%lld",&ca);
  for (int ii=1;ii<=ca;ii++)
  {
    printf("Case %d: ",ii);
    scanf("%lld%lld%lld%lld",&n,&k,&b,&r);
    m=1;
    ss.clear();
    for (i=1;i<=b;i++)
    {
      scanf("%lld%lld",&x[i],&y[i]);
      ss.insert(make_pair(x[i],y[i]));
      m=Max(m,x[i]);
	}
	lint c=0;
	c+=n;
	for (i=1;i<=b;i++)
	  if (x[i]!=m&&!ss.count(make_pair(x[i]+1,y[i])))
	    c++;
	for (i=1;i<=b;i++)
	  if (x[i]==1)
	    c--;
	lint t=pow_mod(k,c,MOD)*pow_mod(k-1,m*n-b-c,MOD)%MOD;
	if (t==r)
	{
	  printf("%lld\n",m);
	  continue;
	}
	c=0;
	for (i=1;i<=b;i++)
	  if (x[i]==m)
	    c++;
	t=t*pow_mod(k,c,MOD)%MOD*pow_mod(k-1,n-c,MOD)%MOD;
	m++;
	if (t==r)
	{
	  printf("%lld\n",m);
	  continue;
	}
	lint tmp=pow_mod(k-1,n,MOD);
	r=r*rev(t,MOD)%MOD;
	lint ans=log_mod(tmp,r,MOD);
	printf("%lld\n",ans+m);
  }
  return 0;
}
