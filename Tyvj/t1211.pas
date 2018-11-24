const
  a:array[0..4,1..4]of longint=((2,2,2,2),(1,3,4,3),(3,1,3,4),(4,3,1,3),(3,4,3,1));
var
  c:array[0..10001]of longint;
  f:Array[0..10002,0..4,0..4]of longint;
  i,j,l,r,k,m,n,s,t:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(f),0);
  f[0,0,0]:=0;
  read(n);
  for i:=1 to n do
    read(c[i]);
  t:=c[1];
  f[1,t,0]:=2;
  f[1,0,t]:=2;
  for i:=1 to n-1 do
    begin
      t:=c[i+1];
      for l:=0 to 4 do
        for r:=0 to 4 do
          if f[i,l,r]>0 then
            begin
              if f[i+1,t,r]=0 then
                f[i+1,t,r]:=f[i,l,r]+a[l,t]
              else
                f[i+1,t,r]:=min(f[i+1,t,r],f[i,l,r]+a[l,t]);
              if f[i+1,l,t]=0 then
                f[i+1,l,t]:=f[i,l,r]+a[r,t]
              else
                f[i+1,l,t]:=min(f[i+1,l,t],f[i,l,r]+a[r,t]);
            end;
    end;
  s:=maxlongint;
  for i:=0 to 4 do
    for j:=0 to 4 do
      if (f[n,i,j]>0)and(f[n,i,j]<s) then
        s:=f[n,i,j];
  writeln(s);
end.

