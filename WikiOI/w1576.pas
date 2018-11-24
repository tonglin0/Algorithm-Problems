var
  a,f:array[0..5001]of longint;
  i,j,k,m,n,s,t,ans:longint;
  function find(l,r,k:longint):longint;
    var
      mid,i,j:longint;
    begin
      while l<>r do
        begin
          mid:=(l+r)shr 1;
          if f[mid]>=k then
            r:=mid
          else
            l:=mid+1;
        end;
      if k>f[l] then
        inc(l);
      exit(l);
    end;
begin
  fillchar(f,sizeof(f),0);
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  f[1]:=a[1];
  k:=1;
  for i:=2 to n do
    begin
      t:=find(1,k,a[i]);
      if t>k then
        begin
          inc(k);
          f[k]:=a[i];
        end
      else
        f[t]:=a[i];
    end;
  writeln(k);
end.

