var
  a,b,c:longint;
begin
  readln(a,b);
  while b<>0 do
    begin
      c:=a;
      a:=b;
      b:=c mod b;
    end;
  writeln(a);
end.
