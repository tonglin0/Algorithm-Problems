var
  f:Array[0..101,0..8001]of boolean;
  a:array[0..201]of longint;
  i,j,n,m,k,n2:longint;
begin
  fillchar(f,sizeof(f),false);
  fillchar(a,sizeof(a),0);
  readln(n);
  m:=0;
  n2:=n shr 1;
  for i:=1 to n do
    begin
      read(a[i]);
      inc(m,a[i]);
    end;
  f[0]:=true;
  for i:=1 to n2 do
    for j:=m downto 1 do
      if (j-a[i]>=0)and(f[j-a[i]]) then
        f[j]:=true;
  j:=maxlongint;
  k:=m div 2;
  for i:=k downto 0 do
    if f[i] then
      begin
        writeln(i,' ',m-i);
        halt;
      end;
end.


