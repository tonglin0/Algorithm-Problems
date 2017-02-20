#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

struct bign{
	int len,s[20];
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
	  char t[10];
	  sprintf(t,"%d",num);
	  *this=t;
	  return *this;
	}
	bign operator + (bign b)
	{
	  bign c;
	  if (len>b.len)
	    c.len=len;
	  else
	    c.len=b.len;
	  for (int i=0;i<c.len;i++)
	  {
	    c.s[i+1]+=(c.s[i]+s[i]+b.s[i])/10000;
	    c.s[i]=(c.s[i]+s[i]+b.s[i])%10000;
	  }
	  if (c.s[c.len]>0)
	    c.len++;
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

bign f[1009];

int main()
{
  freopen("3181.in","r",stdin);
  freopen("3181.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&m,&n);
  for (i=1;i<=m;i++)
    f[i]=0;//memset(f,0,sizeof(f));
  f[0]=1;
  for (i=1;i<=n;i++)
    for (j=i;j<=m;j++)
      f[j]=f[j]+f[j-i];
  f[m].output();//printf("%d\n",f[m]);
  return 0;
}
