var
  m:int64;
  n,k,i,j,l:longint;
  s:string;
begin
  readln(n,k);
  m:=1;
  for i:=1 to n do
    m:=m*i;
  str(m,s);
  l:=length(s);
  while s[l]='0' do
    begin
      delete(s,l,1);
      l:=length(s);
    end;
  if l<=k then
    writeln(s)
  else
    begin
      for i:=l-k+1 to l do
        write(s[i]);
      writeln;
    end;
end.
