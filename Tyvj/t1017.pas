var
  f:array[1..1000]of longint;
  n,m,i,j,k,l,ans,x,y:longint;
  function find(x:longint):longint;
    begin
      if f[x]=x then exit(x);
      f[x]:=find(f[x]);
      exit(f[x]);
    end;
  procedure union(x,y:longint);
    begin
      f[find(x)]:=f[y];
    end;
begin
  readln(m,n);
  for i:=1 to n do
    f[i]:=i;
  ans:=0;
  for i:=1 to m do
    begin
      readln(x,y);
      if find(x)=find(y) then
        begin
          inc(ans);
          continue;
        end
      else
        union(x,y);
    end;
  writeln(Ans);
end.
