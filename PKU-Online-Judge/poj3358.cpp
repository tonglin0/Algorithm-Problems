#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
#define HS 100017
using namespace std;

int top;
LL head[HS+3],next[HS+3],hash[HS+2],id[HS+3];

LL gcd(LL a,LL b){if (b==0) return a;return gcd(b,a%b);}

void ex_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL rev(LL a,LL n)
{
  LL d,x,y;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

void insert(LL x,LL y)
{
  LL k=x%HS;
  hash[top]=x;
  id[top]=y;
  next[top]=head[k];
  head[k]=top++;
}

LL find(int x)
{
  LL k=x%HS;
  for (int i=head[k];i!=-1;i=next[i])
    if (hash[i]==x)
      return id[i];
  return 0;
}

LL log_mod(LL a,LL b,LL n)
{
  LL v,m,i,p=1;
  //if (b==1)
    //return 0;
  top=1;
  memset(head,-1,sizeof(head));
  m=(LL)ceil(sqrt(n+0.5));
  for (i=1;i<m;i++)
  {
    p=p*a%n;
    if (!find(p))
      insert(p,i);
  }
  v=rev(p*a%n,n);
  LL t;
  for (i=0;i<m;i++)
  {
    if (b==1&&i!=0)
      return i*m;
   if ((t=find(b))!=0)
      return i*m+t;
    b=b*v%n;
  }
}

int main()
{
  freopen("3358.in","r",stdin);
  freopen("3358.out","w",stdout);
  LL a,b,i,j,k,m,n,P,Q,p,q,p2;
  int ii=0;
  while(scanf("%I64d/%I64d",&P,&Q)==2)
  {
    ii++;
    printf("Case #%d: ",ii);
    LL d=gcd(P,Q);
    p=P/d;q=Q/d;
    LL ans1=0;
    while(q%2==0)
    {
      ans1++;
      q/=2;
    }
    ans1++;
    printf("%I64d,",ans1);
    LL ans2=log_mod(2,1,q);
    printf("%I64d\n",ans2);//+ans1);
  }
  return 0;
}
