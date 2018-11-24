var
  f:array[0..5001]of longint;
  n,m,p,x,y,i,j,k,t:longint;
  function get(x:longint):longint;
    begin
      if f[x]=x then exit(x);
      f[x]:=get(f[x]);
      exit(f[x]);
    end;
begin
  fillchar(f,sizeof(f),0);
  readln(n,m,p);
  for i:=1 to n do
    f[i]:=i;
  for i:=1 to m do
    begin
      readln(x,y);
      f[get(x)]:=get(y);
    end;
  for i:=1 to p do
    begin
      readln(x,y);
      if get(x)=get(y) then
        writeln('Yes')
      else writeln('No');
    end;
end.


