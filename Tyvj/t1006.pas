program p1006;
var
  s,s1:string;
  a:array[1..10]of longint;
  i,j,k,t,c,m,n,x:longint;
  ch,chi:char;
begin
  readln(s);
  a[1]:=ord(s[1])-48;
  for i:=2 to 4 do
    begin
      a[i]:=ord(s[i+1])-48;
    end;
  for i:=5 to 9 do
    a[i]:=ord(s[i+2])-48;
  ch:=s[13];
  t:=0;
  for i:=1 to 9 do
    t:=t+a[i]*i;
  t:=t mod 11;
  if t=10 then chi:='X'
    else chi:=chr(t+48);
  if ch=chi then writeln('Right')
    else
      begin
        delete(s,13,1);
        s:=s+chi;
        writeln(s);
      end;
end.