var
  aa,bb,i,j:longint;
  a,b,x,y,t:int64;
  procedure gcd(a,b:int64);
    begin
      if b=0 then
        begin
          x:=1;
          y:=0;
        end
      else
        begin
          gcd(b,a mod b);
          t:=x;
          x:=y;
          y:=t-(a div b)*y;
        end;
    end;
begin
  read(aa,bb);
  a:=int64(aa);
  b:=int64(bb);
  gcd(a,b);
  x:=(x mod b+b)mod b;
  writeln(x);
end.

