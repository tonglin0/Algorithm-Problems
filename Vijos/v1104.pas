var
  f:Array[0..1001]of longint;
  w,v:array[0..101]of longint;
  i,j,n,m,t:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(f),0);
  fillchar(w,sizeof(w),0);
  fillchar(v,sizeof(v),0);
  readln(n,m);
  for i:=1 to m do
    read(w[i],v[i]);
  for i:=1 to m do
    for j:=n downto 1 do
      if j-w[i]>=0 then
        f[j]:=max(f[j],f[j-w[i]]+v[i]);
  writeln(f[n]);
end.


