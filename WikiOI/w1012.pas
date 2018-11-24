var
  s,y2,x2,x,y,i,j,n,m,gc:longint;
  function gcd(x,y:longint):longint;
    begin
      if y=0 then
        begin
          gc:=x;
          exit(gc);
        end
      else
        begin
          gc:=gcd(y,x mod y);
          exit(gc);
        end;
    end;
begin
  readln(x,y);
  s:=0;
  if (gcd(x,y)=x) and (x*y div gc=y) then
    begin
      if x<>y then inc(s,2)
        else inc(s);
    end;
  x2:=x shl 1;
  y2:=y shr 1;
  i:=x2;
  while i<=y2 do
    begin
      j:=x2;
      while j<=i do
        begin
          if (gcd(i,j)=x) and (i*j div gc=y) then
            begin
              if i<>j then inc(s,2)
                else inc(s,1);
            end;
          inc(j,x);
        end;
      inc(i,x);
    end;
  writeln(s);
end.
