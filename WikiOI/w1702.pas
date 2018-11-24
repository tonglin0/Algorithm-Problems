var
  s:string;
  n,i,j,m:longint;
  a,k:int64;
  function cheng(a,b,c:int64):int64;
    var
      s,q:int64;
    begin
      s:=0;
      q:=a;
      while b>0 do
        begin
          if b and 1=1 then
            s:=(s+q)mod c;
          b:=b shr 1;
          q:=(q shl 1) mod c;
        end;
      cheng:=s;
    end;
  function f(a,b,c:int64):int64;
    var
      ans,t:int64;
    begin
      ans:=1;
      t:=a mod c;
      while b>0 do
        begin
          if b and 1=1 then
            ans:=cheng(ans,t,c);
          b:=b shr 1;
          t:=cheng(t,t,c);
        end;
      f:=ans;
    end;
  procedure prime(a:int64);
    begin
      randomize;
      for i:=1 to 10 do
        begin
          k:=random(a-2)+2;
          if f(k,a-1,a)<>1 then
            begin
              writeln('No');
              halt;
            end;
        end;
    end;
begin
  readln(s);
  a:=0;
  k:=length(s);
  for i:=1 to k do
    a:=a*10+ord(s[i])-48;
  if a=2 then
    begin
      writeln('Yes');
      halt;
    end;
  if a<=1000000000000 then
    begin
      m:=trunc(sqrt(a));
      for i:=2 to m do
        if a mod i=0 then
          begin
            writeln('No');
            halt;
          end;
      writeln('Yes');
      halt;
    end;
  prime(a);
  writeln('Yes');
end.


