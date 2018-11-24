var
  c:array[0..10001]of boolean;
  x,y,i,s,j,n,m:longint;
begin
  fillchar(c,sizeof(c),true);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y);
      for j:=x to y do
        c[j]:=false;
    end;
  s:=0;
  for i:=0 to n do
    if c[i] then inc(s);
  writeln(s);
end.


