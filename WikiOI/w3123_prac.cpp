#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<complex>
#define MN 800004
#define PI acos(-1.0)
using namespace std;

const complex<double> I(0,1);
char aa[MN],bb[MN];
complex<double> a[MN],b[MN];
int ans[MN];
int n;

void bit_reverse(complex<double> *a)
{
  for (int i=0;i<n;i++)
  {
    int j=0;
    for (int t=i,k=1;k<n;j=(j<<1)|(t&1),k<<=1,t>>=1);
    if (j>i)
      swap(a[i],a[j]);
  }
}

void FFT(complex<double> *a,int sig)
{
  bit_reverse(a);
  for (int h=2;h<=n;h<<=1)
  {
    int mh=h>>1;
    for (int i=0;i<mh;i++)
    {
      complex<double> w=exp(i*PI*sig/mh*I);
      for (int j=i;j<n;j+=h)
      {
        int k=j+mh;
        complex<double> u=a[j],t=w*a[k];
        a[j]=u+t;
        a[k]=u-t;
      }
    }
  }
  if (sig==-1)
    for (int i=0;i<n;i++)
      a[i]/=n;
}

int main()
{
  freopen("3123.in","r",stdin);
  freopen("3123.out","w",stdout);
  int i,j,k;
  scanf("%s%s",aa,bb);
  int la=strlen(aa);
  int lb=strlen(bb);
  n=1;
  while((n<(la<<1))||(n<(lb<<1)))n<<=1;
  for (i=0;i<la;i++)
    a[i]=aa[la-i-1]-'0';
  while(i<n)
    a[i++]=0;
  for (i=0;i<lb;i++)
    b[i]=bb[lb-i-1]-'0';
  while(i<n)
    b[i++]=0;
  FFT(a,1);
  FFT(b,1);
  for (i=0;i<n;i++)
    a[i]*=b[i];
  FFT(a,-1);
  for (i=0;i<n;i++)
    ans[i]=(int)(a[i].real()+0.5);
  for (i=0;i<n;i++)
  {
    ans[i+1]+=ans[i]/10;
    ans[i]%=10;
  }
  while(n>1&&ans[n-1]==0)
    n--;
  for (i=n-1;i>=0;i--)
    printf("%d",ans[i]);
  return 0;
}
