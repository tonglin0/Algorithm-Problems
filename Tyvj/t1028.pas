var
  f:array[0..45000]of boolean;
  a:array[1..500]of longint;
  i,j,k,m,n:longint;
begin
  fillchar(f,sizeof(f),false);
  f[0]:=true;
  readln(m,n);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to n do
    for j:=m downto 1 do
      if j-a[i]>=0 then
        f[j]:=f[j] or f[j-a[i]];
  for i:=m downto 1 do
    if f[i] then
      begin
        writeln(i);
        halt;
      end;
end.


