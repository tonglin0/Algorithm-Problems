var
  n,j,i,k,m,l,t:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(m);
      if (m=1)or(m=2) then
        begin
          writeln(1);
          continue;
        end;
      m:=(m-1)*2;
      t:=trunc(sqrt(m));
      if t*(t+1)=m then
        writeln(1)
      else writeln(0);
    end;
end.


