#include<stdio.h>
#include<stdlib.h>

int main()
{
  char ch;
  scanf("%c",&ch);
  switch (ch)
  {
    case 'Q':printf("1 2");break;
    case 'W':printf("2 3");break;
    case 'E':printf("3 4");break;
    case 'R':printf("4 5");break;
    case 'T':printf("5 6");break;
    case 'Y':printf("6 7");break;
    case 'U':printf("7 8");break;
    case 'I':printf("8 9");break;
    case 'O':printf("9 0");break;
    case 'P':printf("0 -");break;
    case 'A':printf("Q W");break;
    case 'S':printf("W E");break;
    case 'D':printf("E R");break;
    case 'F':printf("R T");break;
    case 'G':printf("T Y");break;
    case 'H':printf("Y U");break;
    case 'J':printf("U I");break;
    case 'K':printf("I O");break;
    case 'L':printf("O P");break;
    case 'Z':printf("A S");break;
    case 'X':printf("S D");break;
    case 'C':printf("D F");break;
    case 'V':printf("F G");break;
    case 'B':printf("G H");break;
    case 'N':printf("H J");break;
    case 'M':printf("J K");break;
    case ',':printf("K L");break;
  }
  //system("pause");
  return 0;
} 
