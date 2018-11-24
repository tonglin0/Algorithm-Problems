const
  mn=11;
var
  ni,mi:Array[0..mn]of int64;
  i,j,k:longint;
  ans,n,mk,m,x,y:int64;
  procedure gcd(a,b:int64);
    var
      t:int64;
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
  fillchar(ni,sizeof(ni),0);
  fillchar(mi,sizeof(mi),0);
  read(j);
  n:=int64(j);
  for i:=1 to n do
    begin
      read(j,k);
      ni[i]:=int64(j);
      mi[i]:=int64(k);
    end;
  ans:=0;
  m:=1;
  for i:=1 to n do
    m:=m*ni[i];
  for i:=1 to n do
    begin
      mk:=m div ni[i];
      gcd(mk,ni[i]);
      ans:=(ans+(mk*x) mod m*mi[i] mod m)mod m;
    end;
  if ans<0 then
    inc(ans,m);
  writeln(ans);
end.

