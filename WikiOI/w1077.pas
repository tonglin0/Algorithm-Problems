var
  map:array[0..101,0..101]of longint;
  i,j,n,m,k:longint;
begin
  fillchar(map,sizeof(map),0);
  read(n);
  for i:=1 to n do
    for j:=1 to n do
      read(map[i,j]);
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if map[i,k]+map[k,j]<map[i,j] then
          map[i,j]:=map[i,k]+map[k,j];
  read(m);
  for i:=1 to m do
    begin
      read(n,k);
      writeln(map[n,k]);
    end;
end.
