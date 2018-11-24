var
  n,m,i:longint;
begin
  readln(n);
  m:=trunc(sqrt(n+0.1));
  for i:=2 to m do
    if n mod i=0 then
      begin
        writeln(n div i);
        halt;
      end;
end.

