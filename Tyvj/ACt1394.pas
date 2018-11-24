var
  l,r,i,j,k,s,m,n:longint;
begin
  readln(l,r);
  s:=0;
  for i:=l to r do
    begin
      n:=i;
      while n<>0 do
        begin
          m:=n mod 10;
          if m=2 then inc(s);
          n:=n div 10;
        end;
    end;
  writeln(s);
end.


