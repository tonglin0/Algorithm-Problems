var
  a:array[0..210,0..210]of longint;
  x,y,i,j,n,m,k:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  m:=n shr 1+1;
  a[m,m]:=1;
  i:=2;
  k:=1;
  x:=m+1;
  y:=m+1;
  while x<=n do
    begin
      for j:=x-1 downto x-i do
        begin
          inc(k);
          a[j,y]:=k;
        end;
      x:=x-i;
      for j:=y-1 downto y-i do
        begin
          inc(k);
          a[x,j]:=k;
        end;
      y:=y-i;
      for j:=x+1 to x+i do
        begin
          inc(k);
          a[j,y]:=k;
        end;
      x:=x+i;
      for j:=y+1 to y+i do
        begin
          inc(k);
          a[x,j]:=k;
        end;
      y:=y+i;
      x:=x+1;
      y:=y+1;
      inc(i,2);
    end;
  for i:=1 to n do
    begin
      for j:=1 to n-1 do
        write(a[i,j],' ');
      writeln(a[i,n]);
    end;
  k:=0;
  for i:=1 to n do
    inc(k,a[i,i]);
  for i:=1 to n do
    inc(k,a[n-i+1,i]);
  dec(k,1);
  writeln(k);
end.

