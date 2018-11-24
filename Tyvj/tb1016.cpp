#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100000007

int a[15];
int main()
{
  FILE *fin,*fout;
  fin=stdin;//fopen("1016.in","r");
  fout=stdout;//fopen("my.out","w"); 
  memset(a,0,sizeof(a));
  int n,i,j,s,ans;
  a[1]=1;
  fscanf(fin,"%d",&n);
  for (i=2;i<=n;i++)
  {
    for (j=13;j>=2;j--)
      a[j]=a[j-1];
    s=0;
    for (j=3;j<=13;j++)
      s=(s+a[j])%M;
    a[1]=s;
  }
  ans=0;
  for (i=1;i<=12;i++)
    ans=(ans+a[i])%M;
  fprintf(fout,"%d\n",ans);/*
  for (i=1;i<=12;i++)
    printf("%d ",a[i]);*/
  //system("pause");
  //fclose(fin);
  //fclose(fout); 
  return 0;
} 
