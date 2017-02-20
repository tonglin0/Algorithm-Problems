#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

struct bign{
  int len,s[600];
  bign(){len=1;memset(s,0,sizeof(s));}
  bign operator = (char *num)
  {
    string ss=num;
    int l=strlen(num);
    while(l%4)
    {
      ss="0"+ss;
      l++;
	}
	len=l/4;
	for (int i=0;i<len;i++)
	  for (int j=0;j<4;j++)
	    s[i]=s[i]*10+ss[l-4*(i+1)+j]-'0';
	return *this;
  }
  bign operator = (int num)
  {
    char t[240];
    sprintf(t,"%d",num);
    *this=t;
    return *this;
  }
  int Max(int a,int b){return a>b?a:b;}
  bign operator + (bign b)
  {
    bign c;
    c.len=Max(len,b.len);
    for (int i=0;i<c.len;i++)
    {
      c.s[i+1]+=(c.s[i]+b.s[i]+s[i])/10000;
      c.s[i]=(c.s[i]+b.s[i]+s[i])%10000;
	}
	if (c.s[c.len]>0)
	  c.len++;
	return c;
  }
  bign operator - (bign b)
  {
    //bign c;
    //c.len=len;
    for (int i=0;i<len;i++)
    {
      if (s[i]<b.s[i])
      {
        s[i]+=10000;
        s[i+1]--;
	  }
	  s[i]-=b.s[i];
	}
	while(len>1&&s[len-1]==0)
	  len--;
	return *this;
  }
  bign operator * (bign b)
  {
    bign c;
    c.len=len+b.len;
    for (int i=0;i<len;i++)
      for (int j=0;j<b.len;j++)
      {
        c.s[i+j+1]+=(c.s[i+j]+s[i]*b.s[j])/10000;
        c.s[i+j]=(c.s[i+j]+s[i]*b.s[j])%10000;
	  }
	while(c.len>1&&c.s[c.len-1]==0)
	  c.len--;
	return c;
  }
  void output()
  {
    printf("%d",s[len-1]);
    for (int i=len-2;i>=0;i--)
      printf("%04d",s[i]);
    printf("\n");
  }
};

bign f[56];
bign h[56];
bign g[56];
bign c[56][56];

bign pow_mod(int a,int b)
{
  bign ans;ans=1;
  bign t;t=a;
  while(b)
  {
    if (b&1) 
      ans=ans*t;
    b>>=1;
    t=t*t;
  }
  return ans;
}

int main()
{
  freopen("1737.in","r",stdin);
  freopen("1737.out","w",stdout);
  int n,i,j,k,m;
  for (i=0;i<=50;i++)
    g[i]=0;
  for (i=0;i<=50;i++)
    for (j=0;j<=50;j++)
      c[i][j]=0;
  for (i=0;i<=50;i++)
    f[i]=0;
  c[0][0]=1;
  for (i=1;i<=50;i++)
  {
    c[i][0]=c[i][i]=1;
    for (j=1;j<i;j++)
      c[i][j]=c[i-1][j-1]+c[i-1][j];
  }
  //c[10][3].output();
  //return 0;
  h[0]=1;h[1]=1;
  for (i=2;i<=50;i++)
    h[i]=pow_mod(2,i*(i-1)/2);
  //memset(f,0,sizeof(f));
  f[1]=1;f[2]=1;f[3]=4;
  g[1]=1;g[2]=1;g[3]=3;
  for (i=4;i<=50;i++)
  {
    for (k=0;k<=i-2;k++)
      g[i]=g[i]+c[i-1][k]*f[k+1]*h[i-k-1];
    bign t=h[i];
	f[i]=t-g[i];
  }
  /*for (i=1;i<=50;i++)
    printf("%d\n",f[i]);
  return 0;*/
  while(scanf("%d",&n)==1)
  {
    if (n==0) break;
    f[n].output();//printf("%d\n",f[n]);
  }
  return 0;
}
