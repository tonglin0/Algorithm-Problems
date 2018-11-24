var
  i,j,a,b,c:int64;
begin
  a:=65535;
  readln(b);
  c:=a and b;
  b:=b shr 16;
  c:=c shl 16;
  c:=b+c;
  writeln(c);
end.


