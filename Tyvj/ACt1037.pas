const
  mn=1000000000000;
var
  a:int64;
  ss:string;
  i,j,k,m,n,l,s:longint;
begin
  readln(n,m);
  l:=1;
  a:=1;
  for i:=2 to n do
    begin
      s:=i;
      while s mod 10=0 do
        s:=s div 10;
      while s mod 5=0 do
        begin
          s:=s div 5;
          a:=a shr 1;
        end;
      a:=a*s mod mn;
    end;
  str(a,ss);
  ss:='0000000000'+ss;
  l:=length(ss);
  for i:=l-m+1 to l do
    write(ss[i]);
  writeln;
end.

