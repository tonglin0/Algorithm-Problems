var
  n,p,la,lb,ra,rb,i,j,k,m,s,t,l,r:longint;
  a,b:double;
  function gcd(a,b:longint):longint;
    begin
      if b=0 then exit(a);
      gcd:=gcd(b,a mod b);
    end;
begin
  readln(p,n);
  a:=0;
  b:=1000000;
  for i:=1 to n do
    begin
      l:=0;
      r:=n;
      while l<r do
        begin
          m:=(l+r)shr 1;
          if sqr(m)/sqr(i)<p then
            l:=m+1
          else
            r:=m-1;
        end;
      if sqr(l)/sqr(i)>p then dec(l);
      if sqr(l)/sqr(i)>a then
        begin
          la:=l;
          lb:=i;
          a:=sqr(l)/sqr(i);
        end;
    end;
  for i:=1 to n do
    begin
      l:=0;
      r:=n;
      while l<r do
        begin
          m:=(l+r)shr 1;
          if sqr(m)/sqr(i)<p then
            l:=m+1
          else
            r:=m-1;
        end;
      if sqr(l)/sqr(i)<p then inc(l);
      if l>n then continue;
      if sqr(l)/sqr(i)<b then
        begin
          ra:=l;
          rb:=i;
          b:=sqr(l)/sqr(i);
        end;
    end;
  k:=gcd(la,lb);
  la:=la div k;
  lb:=lb div k;
  write(la,'/',lb,' ');
  k:=gcd(ra,rb);
  ra:=ra div k;
  rb:=rb div k;
  writeln(ra,'/',rb);
end.

