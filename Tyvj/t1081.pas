var
  map:array[1..2001,1..2]of real;
  s,ans,x,y:real;
  i,j,k,n,m,mx,my:longint;
begin
  fillchar(map,sizeof(map),0);
  readln(n);
  ans:=maxlongint;
  for i:=1 to n do
    begin
      readln(x,y);
      map[i,1]:=x;
      map[i,2]:=y;
      for j:=1 to i-1 do
        begin
          s:=sqr(x-map[j,1])+sqr(y-map[j,2]);
          if s<ans then
            begin
              ans:=s;
              mx:=j;
              my:=i;
            end;
        end;
    end;
  writeln(mx,' ',my);
end.
