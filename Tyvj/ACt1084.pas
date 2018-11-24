var
  a,f:array[1..26,1..26]of longint;
  i,j,k,n,m,x,y:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(a,sizeof(a),128);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    for j:=1 to i do
      read(a[i,j]);
  read(x,y);
  m:=maxlongint div 2;
  inc(a[x,y],m);
  for i:=1 to n do
    f[n,i]:=a[n,i];
  for i:=n-1 downto 1 do
    for j:=1 to i do
      f[i,j]:=max(f[i+1,j],f[i+1,j+1])+a[i,j];
  dec(f[1,1],m);
  writeln(f[1,1]);
end.

