var
  n,i,j,k,m,ans:int64;
begin
  readln(n);
  ans:=0;
  while n<>1 do
    begin
      if n and 1=1 then
        n:=n*3+1
      else
        n:=n shr 1;
      inc(ans);
    end;
  writeln(Ans);
end.


