var
  s:string;
  i,j,l,k:longint;
begin
  readln(s);
  k:=pos('-',s);
  if k=1 then
    begin
      write('-');
      delete(s,1,1);
    end;
  l:=length(s);
  while (l>1)and(s[l]='0') do
    begin
      delete(s,l,1);
      l:=length(s);
    end;
  for i:=l downto 1 do
    write(s[i]);
  writeln;
end.

