program p1002;
type
  person=record
    name:string[21];
    qimo:0..100;
    banji:0..100;
    ganbu:char;
    xibu:char;
    lunwen:0..10;
  end;
var
  n,s,k,sum,i,j,t:longint;
  ch:char;
  a:array[1..100]of person;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(ch);
      while ch<>' 'do
        begin
          a[i].name:=a[i].name+ch;
          read(ch);
        end;
      read(a[i].qimo);
      read(a[i].banji);
      read(ch);
      read(ch);
      a[i].ganbu:=ch;
      read(ch);
      read(ch);
      a[i].xibu:=ch;
      readln(k);
      a[i].lunwen:=k;
    end;
  k:=0;
  sum:=0;
  for i:=1 to n do
    begin
      s:=0;
      with a[i] do
        begin
          if (qimo>80) and (lunwen>=1) then
            s:=s+8000;
          if(qimo>85)and(banji>80) then
            s:=s+4000;
          if (qimo>90)then
            s:=s+2000;
          if (qimo>85)and(xibu='Y')then
            s:=s+1000;
          if (banji>80)and(ganbu='Y')then
            s:=s+850;
          sum:=sum+s;
          if s>k then
            begin
              k:=s;
              t:=i;
            end;
        end;
    end;
  writeln(a[t].name);
  writeln(k);
  writeln(sum);
end.