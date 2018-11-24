#include <stdlib.h>
#include <stdio.h>

int main()
{
    //FILE *fin,*fout;
    //fin=stdin;
    //fout=stdout;
    double k=0;
    int i,n;
    scanf("%d",&n);
    i=0;
    while(k<=n)
    {
        i++;
        k+=1.0/i;
    }
    printf("%d",i);
    /*system("pause");
    fclose(fin);
    fclose(fout);*/
    return 0;
} 
