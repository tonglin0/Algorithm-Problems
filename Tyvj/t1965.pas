var
  i,j,n,t:longint;
begin
  readln(t);
  for i:=1 to t do
    begin
      readln(n);
      writeln(trunc(sqrt(n)));
    end;
end.