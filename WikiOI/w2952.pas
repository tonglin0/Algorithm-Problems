var
  aa,bb,cc,i,j:longint;
  a,b,c,ans,t:int64;
begin
  read(bb,cc);
  b:=int64(bb);
  c:=int64(cc);
  ans:=1;
  t:=2 mod c;
  while b>0 do
    begin
      if b and 1=1 then
        ans:=ans*t mod c;
      b:=b shr 1;
      t:=t*t mod c;
    end;
  writeln(ans);
end.


