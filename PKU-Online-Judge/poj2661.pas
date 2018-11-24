var
  y,n,i,j,k,t:longint;
  s:double;
begin
  readln(y);
  while y<>0 do
    begin
      y:=(y-1960)div 10;
      n:=4;
      n:=n shl y;
      //dec(n);
      //s:=ln(1)/ln(2);
      i:=1;
      s:=0;
      while s<n do
        begin
          inc(i);
          s:=s+(ln(i)/ln(2));
          //inc(i);
        end;
      writeln(i-1);
      readln(y);
    end;
end.