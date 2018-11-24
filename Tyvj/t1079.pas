var
  a:Array[0..30,0..30]of longint;
  f:Array[0..30,0..30]of longint;
  x,y,i,j,k,m,n,s,t,ans:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    for j:=1 to i do
      read(a[i,j]);
  x:=n shr 1;
  ans:=0;
  while x>0 do
    begin
      inc(ans,a[x,x]);
      dec(x);
    end;
  x:=n shr 1;
  for i:=1 to n do
    f[n,i]:=a[n,i];
  for i:=n-1 downto x do
    for j:=1 to i do
      f[i,j]:=max(f[i+1,j],f[i+1,j+1])+a[i,j];
  inc(ans,f[x,x]-a[x,x]);
  writeln(Ans);
end.

