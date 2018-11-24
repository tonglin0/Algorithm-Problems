var
  f:array[0..5020,1..2]of longint;
  t:array[0..5001,0..1000]of longint;
  a:array[0..5001]of longint;
  i,j,n,m,k,s:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
  function find(u,k:longint):longint;
    var
      i,s:longint;
    begin
      if f[u,k]<>0 then exit(f[u,k]);
      if k=1 then
        begin
          s:=0;
          for i:=1 to t[u,0] do
            s:=s+find(t[u,i],2);
          f[u,k]:=s+a[u];
          exit(f[u,k]);
        end
      else
        begin
          s:=0;
          for i:=1 to t[u,0] do
            s:=s+max(find(t[u,i],1),find(t[u,i],2));
          f[u,k]:=s;
          exit(s);
        end;
    end;
begin
  fillchar(f,sizeof(f),0);
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    read(a[i]);
  fillchar(t,sizeof(t),0);
  for i:=2 to n do
    begin
      read(k);
      inc(t[k,0]);
      t[k,t[k,0]]:=i;
    end;
  f[1,1]:=find(1,1);
  f[1,2]:=find(1,2);
  writeln(max(f[1,1],f[1,2]));
end.



