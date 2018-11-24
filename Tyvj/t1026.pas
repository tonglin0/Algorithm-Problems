var
  map:array[0..241,0..241]of boolean;
  i,j,m,n,l,x,y,k,mx,my:longint;
begin
  fillchar(map,sizeof(map),false);
  readln(m,n,k);
  for i:=1 to k do
    begin
      readln(x,y,mx,my);
      for j:=x to mx do
        for l:=y to my do
          map[j,l]:=true;
    end;
  k:=0;
  for i:=1 to m do
    for j:=1 to n do
      if map[i,j] then inc(k);
  writeln(k);
end.

