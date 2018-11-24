var
  f:Array[0..1001]of longint;
  a,b:Array[0..101]of longint;
  i,j,k,m,n,s,t:longint;
  function max(a,b:longint):longint;
    begin
       if a>=b then exit(a);
       exit(b);
    end;
begin
  fillchar(f,sizeof(f),0);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  read(n);
  read(m);
  for i:=1 to n do
    read(a[i],b[i]);
  for i:=1 to n do
    for j:=m downto 1 do
      if j>=b[i] then
        f[j]:=max(f[j],f[j-b[i]]+a[i]);
  writeln(f[m]);
end.


