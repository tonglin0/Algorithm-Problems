const
  d:array[0..15]of char=('0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F');
var
  n,m,i,j,k,s:longint;
  a:array[0..100]of longint;
begin
  readln(n,m);
  i:=0;
  fillchar(a,sizeof(a),0);
  while n<>0 do
    begin
      inc(i);
      a[i]:=n mod m;
      n:=n div m;
    end;
  for j:=i downto 1 do
    write(d[a[j]]);
end.