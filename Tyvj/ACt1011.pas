var
  a:array[0..50,0..50]of longint;
  f:array[0..50,0..50,0..50,0..50]of longint;
  i,j,k,m,n,x1,x2,y1,y2:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for x1:=1 to n do
    for y1:=1 to m do
      for x2:=1 to n do
        for y2:=1 to m do
          begin
            if (x1=x2)and(y1=y2) then continue;
            f[x1,y1,x2,y2]:=f[x1-1,y1,x2-1,y2];
            f[x1,y1,x2,y2]:=max(f[x1-1,y1,x2,y2-1],f[x1,y1,x2,y2]);
            f[x1,y1,x2,y2]:=max(f[x1,y1-1,x2-1,y2],f[x1,y1,x2,y2]);
            f[x1,y1,x2,y2]:=max(f[x1,y1-1,x2,y2-1],f[x1,y1,x2,y2]);
            inc(f[x1,y1,x2,y2],a[x1,y1]+a[x2,y2]);
          end;
  writeln(f[n-1,m,n,m-1]);
  //writeln(f[n,m-1,n-1,m]);
end.