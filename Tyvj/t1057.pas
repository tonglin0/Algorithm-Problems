type
  node=record
    w,p,lc,rc,fa:longint;
  end;
var
  f:array[0..60,0..3200]of longint;
  q:array[0..60]of node;
  t,i,j,n,k,m:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(f),0);
  fillchar(q,sizeof(q),0);
  readln(m,n);
  m:=m div 10;
  for i:=1 to n do
    begin
      readln(q[i].w,q[i].p,q[i].fa);
      q[i].w:=q[i].w div 10;
      if q[i].fa<>0 then
        begin
          if q[q[i].fa].lc=0 then
            q[q[i].fa].lc:=i
          else
            q[q[i].fa].rc:=i;
        end;
    end;
  for i:=1 to n do
    for j:=1 to m do
      begin
        if q[i].fa<>0 then
          begin
            f[i,j]:=f[i-1,j];
            continue;
          end;
        f[i,j]:=f[i-1,j];
        if j>=q[i].w then
          f[i,j]:=max(f[i,j],f[i-1,j-q[i].w]+q[i].w*q[i].p);
        if j>=q[i].w+q[q[i].lc].w then
          f[i,j]:=max(f[i,j],f[i-1,j-q[i].w-q[q[i].lc].w]+q[i].w*q[i].p+q[q[i].lc].w*q[q[i].lc].p);
        if j>=q[i].w+q[q[i].rc].w then
          f[i,j]:=max(f[i,j],f[i-1,j-q[i].w-q[q[i].rc].w]+q[i].w*q[i].p+q[q[i].rc].w*q[q[i].rc].p);
        if j>=q[i].w+q[q[i].lc].w+q[q[i].rc].w then
          f[i,j]:=max(f[i,j],f[i-1,j-q[i].w-q[q[i].lc].w-q[q[i].rc].w]+q[i].w*q[i].p+q[q[i].lc].w*q[q[i].lc].p+q[q[i].rc].w*q[q[i].rc].p);
      end;
  writeln(f[n,m]*10);
end.


