var
  v,g,w:array[0..1001]of longint;
  f:array[0..1001,0..1001]of longint;
  n,m,a,b,i,j,k:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(w,sizeof(w),0);
  fillchar(v,sizeof(v),0);
  fillchar(g,sizeof(g),0);
  fillchar(f,sizeof(f),0);
  read(a,b);
  read(n);
  for i:=1 to n do
    read(w[i],v[i],g[i]);
  for i:=1 to n do
    for j:=a downto v[i] do
      for k:=b downto g[i] do
        f[j,k]:=max(f[j,k],f[j-v[i],k-g[i]]+w[i]);
  writeln(f[a,b]);
end.

