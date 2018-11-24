var
  f:Array[0..2001]of longint;
  a:array[1..2000]of string;
  i,j,k,n,m:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  f[1]:=1;
  for i:=2 to n do
    begin
      for j:=1 to i-1 do
        if (pos(a[j],a[i])=1)and(f[j]>f[i]) then
          f[i]:=f[j];
      inc(f[i]);
    end;
  m:=0;
  for i:=1 to n do
    if f[i]>m then
      m:=f[i];
  writeln(m);
end.


