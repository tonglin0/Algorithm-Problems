var
  ch:char;
  m,t,u,f,d,ans,sum,i,j,k:longint;
begin
  readln(m,t,u,f,d);
  ans:=0;
  sum:=0;
  for i:=1 to t do
    begin
      readln(ch);
      if (ch='u')or(ch='d') then
        inc(sum,u+d);
      if ch='f' then
        inc(sum,2*f);
      if sum>m then break;
      inc(ans);
    end;
  writeln(ans);
end.


