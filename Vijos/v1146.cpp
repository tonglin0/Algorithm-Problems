#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define lint long long
#define INF (int)1e9
using namespace std;

lint m[1003],r[1003];

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("1146.in","r",stdin);
  freopen("1146.out","w",stdout);
  int n,i,j,k,ca;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%I64d%I64d",&m[i],&r[i]);
  lint M=1;
  for (i=1;i<=n;i++)
    M*=m[i];
  lint ans=0;
  lint x,y,d;
  for (i=1;i<=n;i++)
  {
    lint w=M/m[i];
    ex_gcd(w,m[i],d,x,y);
    x=(x%m[i]+m[i])%m[i];
    ans=(ans+w*x%M*r[i]%M)%M;
  }
  printf("%I64d\n",(ans%M+M)%M);
  return 0;
}

