var
  a,b,k,n,t,ans,i:longint;
begin
  read(a,b,k);
  write(a,'^',b,' mod ',k,'=');
  ans:=1;
  t:=a mod k;
  while b>0 do
    begin
      if b and 1=1 then
        ans:=ans*t mod k;
      b:=b shr 1;
      t:=t*t mod k;
    end;
  writeln(ans);
end.

