#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int v[]={0,1,2,3,4,5,6};
int w[]={0,1,2,3,4,5,6};
int f[120003];
int A[120004],B[120004];
int num[8];

int r,ff;

void insert(int x,int y)
{
  while(r>=ff&&B[r]<=y)
    r--;
  A[++r]=x;
  B[r]=y;
}

int main()
{
  freopen("1014.in","r",stdin);
  freopen("1014.out","w",stdout);
  int s,n,i,j,k,m,ii=0,ca;
  while(true)
  {
    s=0;
    for (i=1;i<=6;i++)
    {
      scanf("%d",&num[i]);
      s+=i*num[i];
	}
	if (s==0)
	  break;
	printf("Collection #%d:\n",++ii);
	if (s&1)
	{
	  printf("Can't be divided.\n\n");
	  continue;
	}
	memset(f,0,sizeof(f));
	m=s>>1;
	for (i=1;i<=6;i++)
	{
	  if (num[i]*v[i]>m)
	    num[i]=m/v[i];
	  for (int d=0;d<v[i];d++)
	  {
	    ff=1;r=0;
	    for (j=0;j<=(m-d)/v[i];j++)
	    {
	      insert(j,f[j*v[i]+d]-j*w[i]);
	      while(A[ff]<j-num[i])
	        ff++;
	      f[j*v[i]+d]=B[ff]+j*w[i];
		}
	  }
    }
    if (f[m]!=m)
      printf("Can't be divided.\n\n");
    else
      printf("Can be divided.\n\n");
  }
  return 0;
}
