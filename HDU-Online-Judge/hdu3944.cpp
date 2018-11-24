#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lint long long
using namespace std;

lint fac[10009];
lint c[10009];
int top;
bool vis[10009];
int po;
lint pre[9974][1230];

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

void get_prime()
{
  memset(vis,0,sizeof(vis));
  top=0;
  for (int i=2;i<=10000;i++)
    if(!vis[i])
    {
      c[++top]=i;
      for (int j=i*i;j<=10000;j+=i)
        vis[j]=true;
	}
}

void init()
{
  for (int i=1;i<=top;i++)
  {
    pre[0][i]=1;
    for (int j=1;j<c[i];j++)
      pre[j][i]=pre[j-1][i]*j%c[i];
  }
}

lint rev(lint a,lint n)
{
  lint d,x,y;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

int lucas(lint n,lint m,lint p)
{
  lint ans=1;
  while(n&&m)
  {
    lint a=n%p;
    lint b=m%p;
    if (a<b)
      return 0;
    n/=p;m/=p;
    ans=ans*pre[a][po]%p*rev(pre[b][po],p)%p*rev(pre[a-b][po],p)%p;
  }
  return (int)ans;
}

int search(int x)
{
  int l=1,r=top;
  while(l<=r)
  {
    int mid=(l+r)>>1;
    if (c[mid]==x)
      return mid;
    else if (c[mid]>x)
      r=mid-1;
    else
      l=mid+1;
  }
}

int main()
{
  freopen("3944.in","r",stdin);
  freopen("3944.out","w",stdout);
  int ii=0,n,k,p;
  get_prime();
  init();
  while(scanf("%d%d%d",&n,&k,&p)==3)
  {
    printf("Case #%d: ",++ii);
    if (k>n/2)
      k=n-k;
    po=search(p);
    printf("%d\n",(lucas(n+1,k,p)-k+n)%p);
  }
  return 0;
}
