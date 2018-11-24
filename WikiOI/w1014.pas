var
  f:array[0..20001]of boolean;
  a:array[0..101]of longint;
  i,j,k,m,n,s,t,ans:longint;
begin
  fillchar(f,sizeof(f),false);
  fillchar(a,sizeof(A),0);
  readln(m);
  readln(n);
  f[0]:=true;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    for j:=m downto a[i] do
      if f[j-a[i]] then
        f[j]:=true;
  for i:=m downto 1 do
    if f[i] then
      begin
        writeln(m-i);
        halt;
      end;
  writeln(m);
end.


