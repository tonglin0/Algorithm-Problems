const
  pi=3.1415926535;
var
  i,j,r,n:longint;
  x,y,x2,y2,x1,y1,s:real;
  function dis(x,y,a,b:real):real;
    begin
      dis:=sqrt(sqr(x-a)+sqr(y-b));
    end;
begin
  readln(n,r);
  s:=pi*r*2;
  for i:=1 to n do
    begin
      readln(x,y);
      if i>1 then s:=s+dis(x,y,x2,y2)
        else begin x1:=x;y1:=y;end;
      x2:=x;
      y2:=y;
    end;
  s:=s+dis(x1,y1,x2,y2);
  writeln(s:0:2);
end.



