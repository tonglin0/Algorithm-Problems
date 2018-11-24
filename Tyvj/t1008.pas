var
  i,j,k,n,m,a,b:longint;
  f:array[1..31,0..31]of longint;
begin
  fillchar(f,sizeof(f),0);
  readln(n,m);
  f[1,0]:=1;
  for j:=1 to m do
    for i:=1 to n do
      begin
        if i=1 then a:=n else a:=i-1;
        if i=n then b:=1 else b:=i+1;
        f[i,j]:=f[a,j-1]+f[b,j-1];
      end;
  writeln(f[1,m]);
end.

