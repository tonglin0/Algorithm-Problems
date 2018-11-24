var
  f,a:array[0..110,0..110]of longint;
  i,j,k,n,m,l,s,t:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(F),0);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to n do
    for j:=1 to m do
      begin
        for k:=0 to j do
          f[i,j]:=max(f[i,j],f[i-1,j-k]+a[i,k]);
      end;
  writeln(f[n,m]);
end.


