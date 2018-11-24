var
  s:ansistring;
  i,j,k,m,n,l:longint;
begin
  readln(s);
  readln(n);
  k:=(ord(s[1])-48) xor n;
  l:=length(s);
  for i:=1 to l do
    write(((ord(s[i])-48) xor k)mod 10);
  writeln;
end.
