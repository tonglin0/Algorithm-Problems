label
  l1;
const
  c2:array[0..3]of longint=(6,2,4,8);
  c3:array[0..3]of longint=(1,3,9,7);
  c7:array[0..3]of longint=(1,7,9,3);
  c8:array[0..3]of longint=(6,8,4,2);
var
  ch,ch1,ch2:char;
  flag,n01,n02:boolean;
  i,j,k,t,s,n,m:longint;
  //st:ansistring;
  procedure print(n,m:longint);
    begin
      case n of
        2:writeln(c2[m]);
        3:writeln(c3[m]);
        7:writeln(c7[m]);
        8:writeln(c8[m]);
      end;
    end;
begin
  ch:='!';
  ch1:='!';
  ch2:='!';
  n01:=false;
  while ch<>' ' do
    begin
      ch1:=ch;
      read(ch);
      if ch in ['1'..'9'] then n01:=true;
    end;
  n:=ord(ch1)-48;
  n02:=false;
  while not eoln do
    begin
      //ch1:=ch2;
      ch2:=ch;
      read(ch);
      if ch in ['1'..'9'] then n02:=true;
    end;
  flag:=false;
  if ch2<>' ' then
    begin
      m:=ord(ch2)-48;
      m:=m*10+ord(ch)-48;
    end
  else
    begin
      m:=ord(ch)-48;
      flag:=true;
    end;{
  readln(st);
  l:=length(st);
  for i:=1 to l do
    if st[i]=' ' then
      begin
        n:=ord(s[i-1])-48;
        break;
      end;  }
  while not((not n01) and (not n02)and(n=0)and(m=0)) do
    begin
      if (flag) and (m=0) then begin writeln(1);goto l1;end;
      case n of
        5:writeln(5);
        0:writeln(0);
        1:writeln(1);
        6:writeln(6);
        9:if m and 1=1 then writeln(9) else writeln(1);
        4:if m and 1=1 then writeln(4) else writeln(6);
        2:
          begin
            k:=m mod 4;
            print(2,k);
          end;
        3:print(3,m mod 4);
        7:print(7,m mod 4);
        8:print(8,m mod 4);
      end;
      l1:
  ch:='!';
  ch1:='!';
  ch2:='!';
  n01:=false;
  while ch<>' ' do
    begin
      ch1:=ch;
      read(ch);
      if ch in ['1'..'9'] then n01:=true;
    end;
  n:=ord(ch1)-48;
  n02:=false;
  while not eoln do
    begin
      //ch1:=ch2;
      ch2:=ch;
      read(ch);
      if ch in ['1'..'9'] then n02:=true;
    end;
  flag:=false;
  if ch2<>' ' then
    begin
      m:=ord(ch2)-48;
      m:=m*10+ord(ch)-48;
    end
  else
    begin
      m:=ord(ch)-48;
      flag:=true;
    end;
  end;
end.

