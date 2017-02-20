const
  m=23*28*33;
  a:array[1..3]of longint=(23,28,33);
var
  i,j,k,d,mi,n,s,t,ans,time,x,y:longint;
  ni:array[1..3]of longint;
  procedure gcd(a,b:longint);
    var
      t:longint;
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
  time:=0;
  for i:=1 to 3 do
    begin
      read(ni[i]);
      ni[i]:=ni[i] mod a[i];
    end;
  readln(d);
  while d>=0 do
    begin
      inc(time);
      ans:=0;
      for i:=1 to 3 do
        begin
          mi:=m div a[i];
          gcd(mi,a[i]);
          ans:=(ans+(x*mi)mod m*ni[i] mod m)mod m;
        end;
      dec(ans,d);
      if ans<=0 then
        ans:=ans+m;
      if ans<=0 then
        ans:=ans+m;
      writeln('Case ',time,': the next triple peak occurs in ',ans,' days.');
      for i:=1 to 3 do
        begin
          read(ni[i]);
          ni[i]:=ni[i] mod a[i];
        end;
      readln(d);
    end;
end.
