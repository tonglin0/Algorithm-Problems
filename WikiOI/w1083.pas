var
  k,i,j,n,m:longint;
begin
  readln(n);
  m:=0;
  i:=0;
  while m<n do
    begin
      inc(i);
      inc(m,i);
    end;
  dec(m,i);
  k:=n-m;
  if i and 1=1 then
    writeln(i+1-k,'/',k)
  else writeln(k,'/',i+1-k);
end.


