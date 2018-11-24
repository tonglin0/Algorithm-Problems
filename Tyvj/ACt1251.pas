const
  mn=5001;
var
  f:Array[0..mn]of longint;
  i,j,a,b,k,m,n,p,s,t:longint;
  function find(x:longint):longint;
    begin
      if f[x]=x then exit(x);
      f[x]:=find(f[x]);
      exit(f[x]);
    end;
begin
  fillchar(f,sizeof(f),0);
  readln(n,m,p);
  for i:=1 to n do
    f[i]:=i;
  for i:=1 to m do
    begin
      readln(s,t);
      a:=find(s);
      b:=find(t);
      if a<>b then
        f[a]:=b;
    end;
  for i:=1 to p do
    begin
      readln(s,t);
      if find(s)<>find(t) then
        writeln('No')
      else
        writeln('Yes');
    end;
end.
