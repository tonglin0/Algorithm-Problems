var
  f:array[0..100]of longint;
  //a:array[1..10]of longint;
  i,j,k,m,n:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
begin
  //fillchar(a,sizeof(a),0);
  for i:=1 to 10 do
    read(f[i]);
  readln(n);
  for i:=11 to n do
    f[i]:=maxlongint;
  f[0]:=0;
  for i:=1 to n do
    for j:=0 to i-1 do
      f[i]:=min(f[i],f[j]+f[i-j]);
  writeln(f[n]);
end.



