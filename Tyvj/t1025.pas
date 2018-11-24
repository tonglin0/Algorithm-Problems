const
  e:set of char=['0','2','4','6','8'];
  //o:set of char=('1','3','5','7','9');
var
  s:string;
  l,i,j,n,m,k:longint;
begin
  readln(n);
  for j:=1 to n do
    begin
      readln(s);
      l:=length(s);
      if s[l] in e then
        writeln('even')
      else writeln('odd');
    end;
end.


