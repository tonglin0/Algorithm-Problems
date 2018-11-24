#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char sa[3010],sb[3010];
int a[3010]={0},b[3010]={0};
int main()
{
    scanf("%s",sa);
    scanf("%s",sb);
    int la,lb,i,j,l,s,t;
    la=strlen(sa);
    lb=strlen(sb);
    for (i=0;i<=la-1;i++)
      a[la-i]=sa[i]-'0';
    for (i=0;i<=lb-1;i++)
      b[lb-i]=sb[i]-'0';
    l=la>lb?la:lb;
    for (i=1;i<=l;i++)
    {
      a[i+1]+=(a[i]+b[i])/10;
      a[i]=(a[i]+b[i])%10;
    }/*
    printf("%d",a[l+1]);
    system("pause");
    return 0;*/
    if (a[l+1]) l++;
    for (i=l;i>=1;i--)
      printf("%d",a[i]);
    printf("\n");
    //system("pause");
    return 0; 
}
