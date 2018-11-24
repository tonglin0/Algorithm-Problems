#include<cstdio>
#include<cstring>
#include<cstdlib>
#define LL long long
using namespace std;

LL a[6];
LL m[]={0,23,28,33};

void ex_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
  if (b==0)
  {d=a;x=1;y=0;}
  else
  {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("1006.in","r",stdin);
  freopen("1006.out","w",stdout);
  LL ans,M,Mi,x,y,d,pred;
  int i,j,k,ii=0;;
  scanf("%I64d%I64d%I64d%I64d",&a[1],&a[2],&a[3],&pred);
  while(a[1]!=-1)
  {
    ii++;
    M=1;
    for (i=1;i<=3;i++)
      M*=m[i];
    ans=0;
    for (i=1;i<=3;i++)
    {
      Mi=M/m[i];
      ex_gcd(Mi,m[i],d,x,y);
      ans=(Mi*a[i]%M*x%M+ans)%M;
    }
    ans-=pred;
    ans=(ans%M+M)%M;
    if (ans==0) ans=M;
    printf("Case %d: the next triple peak occurs in %I64d days.\n",ii,ans);
    scanf("%I64d%I64d%I64d%I64d",&a[1],&a[2],&a[3],&pred);
  }
  return 0;
}
