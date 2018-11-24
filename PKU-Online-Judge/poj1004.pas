var
  ans,j:single;
  i:byte;
begin
  ans:=0;
  for i:=1 to 12 do
    begin
      readln(j);
      ans:=ans+j;
    end;
  writeln('$',ans/12:0:2);
end.
