var
  a:array[1..30]of longint;
  f:array[0..30,0..20000]of boolean;
  i,j,n,m,k:longint;
begin
  fillchar(f,sizeof(f),false);
  readln(m);
  readln(n);
  for i:=0 to n do
    f[i,0]:=true;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    for j:=1 to m do
      f[i,j]:=f[i-1,j] or (j-a[i]>=0)and(f[i-1,j-a[i]]);
  for i:=m downto 0 do
    if f[n,i] then
      begin
        writeln(m-i);
        halt;
      end;
end.


