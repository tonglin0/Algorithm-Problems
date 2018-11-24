var
  i,j:longint;
  n,s:real;
begin
  readln(n);
  while n<>0 do
    begin
      s:=0;
      i:=1;
      while s<n do
        begin
          inc(i);
          s:=s+1/i;
        end;
      write(i-1);
      writeln(' card(s)');
      readln(n);
    end;
end.






