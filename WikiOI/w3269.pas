var
  w,v,c:array[0..201]of longint;
  f:array[0..200003]of longint;
  i,j,k,n,m,t,s:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(f,sizeof(f),0);
  fillchar(w,sizeof(w),0);
  fillchar(v,sizeof(V),0);
  fillchar(c,sizeof(c),0);
  readln(n,m);
  for i:=1 to n do
    readln(v[i],w[i],c[i]);
  for i:=1 to n do
    if c[i]=-1 then
      for j:=1 to n do
        if (v[j]>=v[i])and(w[j]<=w[i])and(i<>j) then
          c[j]:=-2;
  for i:=1 to n do
    if c[i]=-2 then continue
    else
    if c[i]=1 then
      for j:=m downto v[i] do
        f[j]:=max(f[j-v[i]]+w[i],f[j])
    else if c[i]=-1 then
      for j:=v[i] to m do
        f[j]:=max(f[j],f[j-v[i]]+w[i])
    else
      begin
        t:=1;
        while c[i]>0 do
          begin
            if t>c[i] then t:=c[i];
            c[i]:=c[i]-t;
            for j:=m downto v[i]*t do
              f[j]:=max(f[j],f[j-v[i]*t]+w[i]*t);
            t:=t shl 1;
          end;
      end;
  writeln(f[m]);
end.



