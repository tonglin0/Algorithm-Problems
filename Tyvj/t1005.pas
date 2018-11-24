var
  f:array[0..100,0..1000]of longint;
  t,v:array[1..100]of longint;
  i,j,k,l,m,n,s,ans:longint;
  function max(x,y:longint):longint;
    begin
      if x>=y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),0);
  fillchar(t,sizeof(t),0);
  readln(m,n);
  for i:=1 to n do
    readln(t[i],v[i]);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          if j<t[i] then f[i,j]:=f[i-1,j]
          else
            f[i,j]:=max(f[i-1,j],f[i-1,j-t[i]]+v[i]);
        end;
    end;
  writeln(f[n,m]);
end.


