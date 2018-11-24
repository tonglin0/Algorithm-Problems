const
  d:array[10..15]of char=('A','B','C','D','E','F');
var
  i,j,n,m,s,t:longint;
  st,sa:string;
  function get(c:char):longint;
    var
      i:longint;
    begin
      for i:=10 to 15 do
        if d[i]=c then
          exit(i);
    end;
begin
  readln(st);
  t:=pos(' ',st);
  sa:=copy(st,1,t-1);
  delete(st,1,t);
  val(st,m);
  j:=1;
  s:=0;
  n:=length(sa);
  for i:=n downto 1 do
    begin
      if sa[i] in ['0'..'9'] then
        s:=s+(ord(sa[i])-48)*j
      else s:=s+get(sa[i])*j;
      j:=j*m;
    end;
  writeln(s);
end.

