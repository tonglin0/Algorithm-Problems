var
  sa,sb,s:ansistring;
  t:longint;
begin
  readln(s);
  t:=pos('  ',s);
  while t<>0 do
    begin
      delete(s,t,1);
      t:=pos('  ',s);
    end;
  t:=pos(' ',s);
  sa:=copy(s,1,t-1);
  delete(s,1,t);
  sb:=s;
  t:=pos(sb,sa);
  writeln(t);
end.