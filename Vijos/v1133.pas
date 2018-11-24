var
  a:array[1..30]of longint;
  f:Array[0..20001]of boolean;
  i,j,n,m:longint;
begin
  fillchar(f,sizeof(F),0);
  readln(m);
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  f[0]:=true;
  for i:=1 to n do
    for j:=m downto 1 do
      if (j-a[i]>=0)and(f[j-a[i]]) then
        f[j]:=true;
  for i:=m downto 1 do
    if f[i] then
      begin
        writeln(m-i);
        halt;
      end;
end.

