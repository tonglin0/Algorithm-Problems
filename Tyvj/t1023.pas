var
  f:array[0..2000,0..500]of longint;
  d:array[1..2000]of longint;
  i,j,k,m,n,s,t:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(f),0);
  readln(n,m);
  for i:=1 to n do
    readln(d[i]);
  for i:=1 to n do
    begin
      f[i,0]:=f[i-1,0];
      for k:=1 to i-1 do
        begin
          if k>m then break;
          f[i,0]:=max(f[i,0],f[i-k,k]);
        end;
      for j:=1 to m do
        f[i,j]:=f[i-1,j-1]+d[i];
    end;
  writeln(f[n,0]);
end.


