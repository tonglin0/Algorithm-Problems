#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1003][1003];
int main()
{
   FILE *input,*output;
   input=stdin;//fopen("1021.in","r");
   output=stdout;//fopen("1021.out","w");
   memset(a,0,sizeof(a));
   int n,i,m,j,s,k;
   fscanf(input,"%d%d%d",&n,&m,&s);
   for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
     {
       fscanf(input,"%d",&k);
       a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+k;
     }
   for (i=1;i<=s;i++)
   {
     int x1,y1,x2,y2;
     fscanf(input,"%d%d%d%d",&x1,&y1,&x2,&y2);
     int ans=a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];
     fprintf(output,"%d\n",ans); 
   }
  //fclose(input);
  //fclose(output);
  return 0;
}
