var
  a:array[0..26,0..26]of longint;
  f:array[0..26,0..26,0..100]of boolean;
  i,j,k,m,n,s,t:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),false);
  readln(n);
  for i:=1 to n do
    for j:=1 to i do
      read(a[i,j]);
  for i:=1 to n do
    f[n,i,a[n,i]]:=true;
  for i:=n-1 downto 1 do
    begin
      for j:=1 to i do
        for k:=0 to 99 do
          if f[i+1,j,k] or f[i+1,j+1,k] then
            f[i,j,(k+a[i,j])mod 100]:=true;
    end;
  for i:=99 downto 0 do
    if f[1,1,i] then
      begin
        writeln(i);
        halt;
      end;
end.

