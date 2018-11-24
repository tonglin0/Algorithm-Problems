#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
  if(a>b) return a;
  else return b;   
}
int min(int a,int b)
{
  if (a<b) return a;
  else return b;
}
int main()
{
  int a,b,c,d;
  char ma,mb,ca,cb,cc,cd;
  scanf("%c %d\n",&ca,&a);
  scanf("%c %d\n",&cb,&b);
  scanf("%c %d\n",&cc,&c);
  scanf("%c %d\n",&cd,&d);
  switch(ca)
  {
    case '0':ca=58;break;
    case 'J':ca=59;break;
    case 'Q':ca=60;break;
    case 'K':ca=61;break;
    case 'A':ca=62;break;
  }
  switch(cb)
  {
    case '0':cb=58;break;
    case 'J':cb=59;break;
    case 'Q':cb=60;break;
    case 'K':cb=61;break;
    case 'A':cb=62;break;
  }
  switch(cc)
  {
    case '0':cc=58;break;
    case 'J':cc=59;break;
    case 'Q':cc=60;break;
    case 'K':cc=61;break;
    case 'A':cc=62;break;
  }
  switch(cd)
  {
    case '0':cd=58;break;
    case 'J':cd=59;break;
    case 'Q':cd=60;break;
    case 'K':cd=61;break;
    case 'A':cd=62;break;
  }
  if(ca==cb&&cc!=cd)
  {
    printf("freda");
    return 0;
  }
  else if (ca!=cb&&cc==cd)
  {
    printf("rainbow");
    return 0;
  }
  else if (ca==cb&&cc==cd)
  {
    if (ca>cc)
      printf("freda");
    else if (ca<cc)
      printf("rainbow");
    else
    {
      if (a==1||b==1) 
        printf("freda");
      else 
        printf("rainbow");
    }
    return 0; 
  }
  else
  {
    ma=max(ca,cb);
    mb=max(cc,cd);
    if (ma>mb)
    {
      printf("freda");
      return 0;
    }
    else if (ma<mb)
    {
      printf("rainbow");
      return 0; 
    }
    else
    {
      ma=min(ca,cb);
      mb=min(cc,cd);
      if (ma>mb)
      {
        printf("freda");
        return 0;
      }
      else if (ma<mb)
      {
        printf("rainbow");
        return 0;
      }
      else
      {
        if (ca>cb)
          ma=a;
        else ma=b;
        if (cc>cd)
          mb=c;
        else mb=d;
        if (ma<mb)
          printf("freda");
        else
          printf("rainbow");
        return 0;
      }
    }
  }
  return 0;
} 
