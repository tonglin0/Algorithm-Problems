var
  sa,s:ansistring;
  t,i,l:longint;
  flag:boolean;
begin
  readln(sa);
  flag:=false;
  s:='';
  l:=length(sa);
  for i:=l downto 1 do
    s:=s+sa[i];
  t:=pos(' ',s);
  if t=0 then flag:=true;
  if t<>0 then
    for i:=t-1 downto 1 do
      write(s[i]);
  delete(s,1,t);
  t:=pos(' ',s);
  while t<>0 do
    begin
      write(' ');
      for i:=t-1 downto 1 do
        write(s[i]);
      delete(s,1,t);
      t:=pos(' ',s);
    end;
  if not flag then write(' ');
  l:=length(s);
  for i:=l downto 1 do
    write(s[i]);
end.