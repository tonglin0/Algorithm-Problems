var
  a:array[0..101]of longint;
  f1,f2:array[0..101]of longint;
  i,j,k,m,n,t:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(f1,sizeof(f1),0);
  fillchar(f2,sizeof(f2),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  f1[1]:=1;
  for i:=2 to n do
    begin
      for j:=1 to i-1 do
        if a[j]<a[i] then
          f1[i]:=max(f1[j],f1[i]);
      inc(f1[i]);
    end;
  f2[n]:=1;
  for i:=n-1 downto 1 do
    begin
      for j:=n downto i+1 do
        if a[j]<a[i] then
          f2[i]:=max(f2[i],f2[j]);
      inc(f2[i]);
    end;
  m:=0;
  for i:=1 to n do
    begin
      inc(f1[i],f2[i]);
      m:=max(f1[i],m);
    end;
  writeln(n-m+1);
end.


