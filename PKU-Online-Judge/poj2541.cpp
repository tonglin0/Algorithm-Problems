#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 2000003
using namespace std;

char st[MN];
int next[MN];

int main()
{
  freopen("2541.in","r",stdin);
  freopen("2541.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  scanf("%s",st);
  int len=strlen(st);
  for (i=0;i<len/2;i++)
    swap(st[i],st[len-i-1]);    
  for (i=len-1+m;i>=m;i--)
    st[i]=st[i-m];
  st[len+m]=0;
  len=len+m;
  for (k=1;k<=m;k++)
  {
    int pos=m-k;
    int ms=0,pt;
    bool flag=false;
    next[pos+1]=next[pos+2]=pos+1;
    for (i=pos+2;i<len+m;i++)
    {
      j=next[i];
      while(j>pos+1&&st[i]!=st[j])
        j=next[j];
      next[i+1]=(st[i]==st[j])?j+1:pos+1;
      if (next[i+1]-pos-1>ms)
      {
      	if (next[i+1]-pos-1>13)
      	  next[i+1]=pos+14;
        ms=next[i+1]-pos-1;
        pt=i-ms;//pt=i+1-(next[i+1]-pos-1);
	  }
	  if (ms>=13)
      {
        break;
	  }
	}
	if (ms>0)
	  st[pos]=st[pt];
	else
	  st[pos]='0';
  }
  for (i=m-1;i>=0;i--)
    printf("%c",st[i]);
  printf("\n");
  return 0;
}
