var
  sa,sb:ansistring;
  i,j,k,l,n,m:longint;
  f:array[0..2000,0..2000]of longint;
  function min(x,y,z:longint):longint;
    begin
      if x<y then y:=x;
      if y<z then exit(y)
      else exit(z);
    end;
begin
  fillchar(f,sizeof(f),0);
  readln(sa);
  readln(sb);
  n:=length(sa);
  m:=length(sb);
  readln(k);
  for i:=0 to n do
    f[i,0]:=i*k;
  for j:=0 to m do
    f[0,j]:=j*k;
  for i:=1 to n do
    for j:=1 to m do
      f[i,j]:=min(f[i-1,j]+k,f[i,j-1]+k,f[i-1,j-1]+abs(ord(sa[i])-ord(sb[j])));
  writeln(f[n,m]);
end.

