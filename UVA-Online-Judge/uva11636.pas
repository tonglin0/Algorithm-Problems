var
  cas,n,i,j,k,m,s:longint;
begin
  cas:=0;
  readln(n);
  while n>0 do
    begin
      inc(cas);
      m:=1;
      i:=0;
      while m<n do
        begin
          m:=m shl 1;
          inc(i);
        end;
      writeln('Case ',cas,': ',i);
      readln(n);
    end;
end.


