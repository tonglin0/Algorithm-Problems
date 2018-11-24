var
  a:array[1..10000]of longint;
  w:array[1..100]of longint;
  n,m,i,j,ta,tb,k,s:longint;
  function min:longint;
    var
      i,j:longint;
    begin
      j:=maxlongint;
      for i:=1 to m do
        if w[i]<j then j:=w[i];
      exit(j);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(w,sizeof(w),0);
  readln(n,m);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to m do
    w[i]:=a[i];
  ta:=m+1;
  s:=0;
  while ta<=n do
    begin
      k:=min;
      for i:=1 to m do
        dec(w[i],k);
      inc(s,k);
      for i:=1 to m do
        if w[i]=0 then
          begin
            if ta>n then
              w[i]:=0
            else
              begin
                w[i]:=a[ta];
                inc(ta);
              end
          end;
    end;
  j:=0;
  for i:=1 to m do
    if w[i]>j then j:=w[i];
  inc(s,j);
  writeln(s);
end.

