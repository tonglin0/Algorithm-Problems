var
  v:array[0..9]of boolean;
  i,j,k,m,n,t:longint;
  s:ansistring;
begin
  fillchar(v,sizeof(v),false);
  v[2]:=true;
  v[3]:=true;
  v[7]:=true;
  v[8]:=true;
  for i:=1 to 10 do
    begin
      readln(s);
      t:=pos(' ',s);
      k:=ord(s[t-1])-48;
      n:=ord(s[length(s)])-48;
      if (v[k])and(v[n]) then
        writeln('Shadow')
      else writeln('Matrix67');
    end;
end.