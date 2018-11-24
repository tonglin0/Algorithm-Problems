#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#define lint long long
#define eps 1e-8
#define MOD 1000000007
#define INF (int)1e9
using namespace std;

lint pow_mod(lint a,lint b)
{
  lint ans=1,t=a;
  while(b)
  {
    if (b&1)
      ans=ans*t%MOD;
    t=t*t%MOD;
    b>>=1;
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
  lint x,y,d;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

int main()
{
  freopen("3240.in","r",stdin);
  freopen("3240.out","w",stdout);
  lint n,i,j,k,m,a,b,c,d;
  char s1[1000009],s2[1000009];
  scanf("%s%s",s1,s2);
  int len1=strlen(s1);
  n=0;
  for (i=0;i<len1;i++)
	n=(n*10+s1[i]-'0')%MOD;
  //n=((n-1)%MOD+MOD)%MOD;
  m=0;
  int len2=strlen(s2);
  for (i=0;i<len2;i++)
	m=(m*10+s2[i]-'0')%MOD;
  //m=((m-1)%MOD+MOD)%MOD;
  
  lint tmpn=0;
  for (i=0;i<len1;i++)
    tmpn=(tmpn*10+s1[i]-'0')%(MOD-1);
  tmpn=((tmpn-1)%(MOD-1)+MOD-1)%(MOD-1);
  lint tmpm=0;
  for (i=0;i<len2;i++)
    tmpm=(tmpm*10+s2[i]-'0')%(MOD-1);
  tmpm=((tmpm-1)%(MOD-1)+MOD-1)%(MOD-1);
  
  //scanf("%I64d%I64d",&n,&m);
  
  scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
  if (a!=1)
  {
    lint A=c*pow_mod(a,tmpm)%MOD;
    lint B=b*c%MOD*(pow_mod(a,tmpm)-1)%MOD*rev(a-1,MOD)%MOD+d;
    B%=MOD;
    lint t=(pow_mod(A,tmpn)+B*(pow_mod(A,tmpn)-1)%MOD*rev(A-1,MOD)%MOD)%MOD;
    lint ans=(pow_mod(a,tmpm)*t%MOD+b*(pow_mod(a,tmpm)-1)%MOD*rev(a-1,MOD))%MOD;
    printf("%I64d\n",ans);
  }
  else 
  {
    if (c!=1)
    {
      lint A=c,B=(b*c%MOD*(m-1)%MOD+d)%MOD;
	  lint t=(pow_mod(A,tmpn)+B*(pow_mod(A,tmpn)-1)%MOD*rev(A-1,MOD)%MOD)%MOD;
	  lint ans=(t+(m-1)*b%MOD)%MOD;
	  printf("%I64d\n",ans);
	}
	else
	{	  
	  lint ans=(1+((m-1)*b%MOD+d)%MOD*(n-1)%MOD+(m-1)*b%MOD)%MOD;
	  printf("%I64d\n",ans);
	}
  }
  return 0;
}

