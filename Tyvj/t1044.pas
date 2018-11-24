var
  map:array[0..25,0..25]of longint;
  f:array[0..25,0..25]of longint;
  i,j,k,n,m,l:longint;
  function max(x,y:longint):longint;
    begin
      if x>=y then exit(x);
      exit(y);
    end;
begin
  fillchar(map,sizeof(map),0);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to i do
        read(map[i,j]);
      readln;
    end;
  f[1,1]:=map[1,1];
  for i:=2 to n do
    begin
      for j:=1 to i do
        f[i,j]:=max(f[i-1,j-1],f[i-1,j])+map[i,j];
    end;
  k:=-1;
  for i:=1 to n do
    if f[n,i]>k then k:=f[n,i];
  writeln(k);
end.




