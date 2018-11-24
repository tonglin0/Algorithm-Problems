var
  a,b,c,t,ans,i:longint;
  v:Array[0..999]of longint;
begin
  read(c);
  t:=c mod 1000;
  v[t]:=1;
  ans:=t;
  i:=1;
  while true do
    begin
      inc(i);
      ans:=ans*c mod 1000;
      if v[ans]>0 then
        begin
          writeln(i,' ',v[ans]);
          halt;
        end
      else v[ans]:=i;
    end;
end.

