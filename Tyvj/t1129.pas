var
  a,b,max,ans,i,j,k:longint;
begin
  max:=-1;
  ans:=0;
  for i:=1 to 7 do
    begin
      readln(a,b);
      a:=a+b;
      if a>8 then
        begin
          if a>max then
            begin
              ans:=i;
              max:=a;
            end;
        end;
    end;
  writeln(ans);
end.

