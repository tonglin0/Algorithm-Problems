var
  a:array[1..10]of longint;
  s,i,j:longint;
begin
  fillchar(a,sizeof(a),0);
  for i:=1 to 10 do
    read(a[i]);
  readln(j);
  inc(j,30);
  s:=0;
  for i:=1 to 10 do
    if a[i]<=j then
      inc(s);
  writeln(s);
end.



