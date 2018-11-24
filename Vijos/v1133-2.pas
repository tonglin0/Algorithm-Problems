var
  a:array[1..30]of longint;
  f:Array[0..20001]of longint;
  i,j,n,m:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(F),0);
  readln(m);
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to n do
    for j:=m downto 1 do
      if j-a[i]>=0 then
        f[j]:=max(f[j],f[j-a[i]]+a[i]);
  writeln(m-f[m]);
end.

