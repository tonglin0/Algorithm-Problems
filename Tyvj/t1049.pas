var
  a:array[1..5000]of longint;
  f:array[1..5000]of longint;
  i,j,n,m,k:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  f[1]:=1;
  for i:=2 to n do
    begin
      m:=0;
      for j:=1 to i-1 do
        if (a[j]<=a[i])and(f[j]>m) then
          m:=f[j];
      f[i]:=m+1;
    end;
  m:=-1;
  for i:=1 to n do
    if f[i]>m then m:=f[i];
  writeln(m);
end.


