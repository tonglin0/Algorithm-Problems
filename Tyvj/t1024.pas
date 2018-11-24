var
  sa,s:string;
  f,a:array[1..256]of longint;
  ch:char;
  t,j,i,k,m,n,maxn:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  readln(sa);
  readln(s);
  t:=pos(' ',s);
  while t<>0 do
    begin
      for i:=1 to t-1 do
        a[i]:=pos(s[i],sa);
      fillchar(f,sizeof(f),0);
      f[1]:=1;
      for i:=2 to t-1 do
        begin
          f[i]:=1;
          for j:=1 to i-1 do
            if a[i]>=a[j] then
              f[i]:=max(f[i],f[j]+1);
        end;
      maxn:=-1;
      for i:=1 to t-1 do
        if f[i]>maxn then maxn:=f[i];
      write(maxn);
      delete(s,1,t);
      t:=pos(' ',s);
    end;
  t:=length(s);
  inc(t);
  for i:=1 to t-1 do
    a[i]:=pos(s[i],sa);
      fillchar(f,sizeof(f),0);
      f[1]:=1;
      for i:=2 to t-1 do
        begin
          f[i]:=1;
          for j:=1 to i-1 do
            if a[i]>=a[j] then
              f[i]:=max(f[i],f[j]+1);
        end;
      maxn:=-1;
      for i:=1 to t-1 do
        if f[i]>maxn then maxn:=f[i];
      write(maxn);
end.