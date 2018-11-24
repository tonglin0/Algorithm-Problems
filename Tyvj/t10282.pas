var
  f:array[0..45000]of longint;
  a:array[1..500]of longint;
  i,j,k,m,n:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(f),0);
  readln(m,n);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to n do
    for j:=m downto 1 do
      if j-a[i]>=0 then
        f[j]:=max(f[j],f[j-a[i]]+a[i]);
  writeln(f[m]);
end.