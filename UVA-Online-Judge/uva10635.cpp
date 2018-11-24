#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int len;
int num[62509],a[62509],b[62509];
int g[62509];

int find(int x)
{
  int l=1,r=len+1;
  while(l<r)
  {
    int mid=(l+r)>>1;
    if (g[mid]<x)
      l=mid+1;
    else
      r=mid;
  }
  return l;
}

int main()
{
  freopen("10635.in","r",stdin);
  freopen("10635.out","w",stdout);
  int ca,ii,p,q,n,i,j,k,m;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    printf("Case %d: ",ii);
    scanf("%d%d%d",&n,&p,&q);
    p++;q++;
    memset(num,0,sizeof(num));
	for (i=1;i<=p;i++)
	{
      scanf("%d",&a[i]);
      num[a[i]]=i;
    }
    for (j=1;j<=q;j++)
    {
	  scanf("%d",&b[j]);
      b[j]=num[b[j]];
    }
    /*for (i=1;i<=q;i++)
      printf("%d ",b[i]);
    return 0;*/
    j=1;
    /*while(j<=q&&b[j]==0)
      j++;
    if (j>q)
    {
      printf("0\n");
      continue;
	}*/
	len=1;
	g[1]=b[j];
	for (i=j+1;i<=q;i++)
	  if (b[i]!=0)
	  {
	    k=find(b[i]);
	    len=max(len,k);
	    g[k]=b[i];
	  }
	printf("%d\n",len);
  }
  return 0;
}
