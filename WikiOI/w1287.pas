var
  a,b,c:array[0..201,0..201]of int64;
  i,j,k,n,x,y,m:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  read(x,n);
  for i:=1 to x do
    for j:=1 to n do
      read(a[i,j]);
  read(n,y);
  for i:=1 to n do
    for j:=1 to y do
      read(b[i,j]);
  for i:=1 to x do
    for j:=1 to y do
      for k:=1 to n do
        c[i,j]:=c[i,j]+a[i,k]*b[k,j];
  for i:=1 to x do
    begin
      for j:=1 to y-1 do
        write(c[i,j],' ');
      writeln(c[i,y]);
    end;
end.

