var
  ans:real;
  i,j,k,m,n,s,h:longint;
begin
  s:=0;
  h:=0;
  for i:=1 to 12 do
    begin
      read(k);
      h:=h+300;
      if h>=k then
        begin
          inc(s,(h-k)div 100*100);
          h:=(h-k)mod 100;
          continue;
        end;
      if h<k then
        begin
          write('-');
          writeln(i);
          halt;
        end;
    end;
  ans:=h+s+s*0.2;
  writeln(ans:0:0);
end.



