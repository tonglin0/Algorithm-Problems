var
  a:array[1..10]of longint;
  f:array[0..500]of longint;
  i,j,k,m,n:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
begin
  for i:=1 to 10 do
    read(a[i]);
  readln(n);
  for i:=1 to n do
    f[i]:=maxlongint;
  //for i:=1 to 10 do
    //f[i]:=a[i];
  for i:=1 to 10 do
    for j:=1 to n do
      if j>=i then
        f[j]:=min(f[j],f[j-i]+a[i]);
  writeln(f[n]);
end.


