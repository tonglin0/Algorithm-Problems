var
  a,b,i,s,m:longint;
begin
  readln(a,b);
  m:=1012;
  s:=1;
  a:=a mod m;
  for i:=1 to b do
    s:=s*a mod m;
  writeln(s);
end.

