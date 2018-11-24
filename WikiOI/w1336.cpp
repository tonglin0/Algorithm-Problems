#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define INF 10000000

int a[50003];
int main()
{
  FILE *fin,*fout;
  fin=stdin;//fopen("w1336.in","r");
  fout=stdout;//fopen("w1336.out","w");
  int n,i,j,minj,k,ans,m,s;
  fscanf(fin,"%d",&n);
  for (i=1;i<=n;i++)
  {
      memset(a,0,sizeof(a));
      fscanf(fin,"%d",&m);
      for (j=1;j<=m;j++)
        fscanf(fin,"%d",&a[j]);
      ans=INF;
      for (j=0;j<=49;j++)
      {
        s=0;
        for (k=1;k<=m;k++)
          s+=abs(a[k]-j);
        if (s<ans)
        {
          minj=j;
          ans=s;
        } 
      }
      fprintf(fout,"%d %d\n",minj,ans); 
  }/*
  fclose(fin);
  fclose(fout);*/
  return 0;
} 
