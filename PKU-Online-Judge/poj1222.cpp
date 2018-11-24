#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[35][35];

void gauss()
{
  int i,j,k,r;
  for (i=1;i<=30;i++)
  {
    bool flag=false;
    for (j=i;j<=30;j++)
      if (a[j][i]!=0)
      {
        flag=true;
        break;
      }
    //if (!flag) continue;
    if (i!=j)
      for (k=1;k<=31;k++)
        swap(a[i][k],a[j][k]);
    for (j=1;j<=30;j++)
      if (i!=j&&a[j][i])
        for (k=1;k<=31;k++)
          a[j][k]=a[i][k]^a[j][k];
  }
}
/*
void gauss(){  
    for(int i=1;i<=30;i++){  
        int k=i;  
        for(;k<=30;k++)  
            if(a[k][i]!=0)  
                break;  
        for(int j=1;j<=31;j++)  
            swap(a[i][j],a[k][j]);  
        for(int j=1;j<31;j++)  
            if(i!=j&&a[j][i])  
                for(int k=1;k<=31;k++)  
                    a[j][k]=a[i][k]^a[j][k];  
    }  
}  
*/
int main()
{
  freopen("1222.in","r",stdin);
  freopen("1222.out","w",stdout);
  int n,ii,j,i,k,m,T;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    memset(a,0,sizeof(a));
    for (i=1;i<=30;i++)
      scanf("%d",&a[i][31]);
    for (i=1;i<=30;i++)
    {
      a[i][i]=1;
      if (i%6!=1)
        a[i-1][i]=1;
      if (i%6!=0)
        a[i+1][i]=1;
      if (i>6)
        a[i-6][i]=1;
      if (i<25)
        a[i+6][i]=1;
    }
    gauss();
    printf("PUZZLE #%d\n",ii);
    for (i=1;i<=30;i++)
    {
      printf("%d",a[i][31]);
      if (i%6!=0)
        printf(" ");
      else
        printf("\n");
    }
  }
  return 0;
}
