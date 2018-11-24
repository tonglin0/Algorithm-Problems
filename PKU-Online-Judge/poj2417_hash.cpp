#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define ll long long
#define HS 1000017
using namespace std;

int next[HS+2],id[HS+2],hash[HS+2],head[HS+2];
int top;

void insert(ll x,ll y)
{
  ll k=x%HS;
  hash[top]=x;
  id[top]=y;
  next[top]=head[k];
  head[k]=top++;
}

void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y)
{
  if (b==0){d=a;x=1;y=0;}
  else {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}     
}

ll rev(ll a,ll n)
{
  ll d,x,y;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

ll find(ll x)
{
  ll k=x%HS;
  for (int i=head[k];i!=-1;i=next[i])
    if (hash[i]==x)
      return id[i];
  return 0;
}

ll log_mod(ll a,ll b,ll n)
{
  if (b==1)
    return 0;
  top=1;
  memset(head,-1,sizeof(head));
  ll v,ans,p=1,i,m;
  m=(ll)ceil(sqrt(n+0.5));
  for (i=1;i<m;i++)
  {
    p=p*a%n;
    if (!find(p))
      insert(p,i);
  }
  v=rev(p*a%n,n);
  ll t;
  for (i=0;i<m;i++)
  {
    if (b==1)
      return i*m;
    else if ((t=find(b))!=0)
      return i*m+t;
    b=b*v%n;
  }
  return -1;
}

int main()
{
  freopen("2417.in","r",stdin);
  freopen("2417.out","w",stdout);
  ll ans,a,b,n;
  while(scanf("%I64d%I64d%I64d",&n,&a,&b)==3)
  {
    ans=log_mod(a,b,n);
    if (ans==-1)
      printf("no solution\n");
    else
      printf("%I64d\n",ans);
  }
  return 0;
}
