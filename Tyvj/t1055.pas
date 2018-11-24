var
  sum,f:array[1..301,1..301]of longint;
  num:array[1..301]of longint;
  t,j,i,n,m,s,ans,l,k:longint;
begin
  fillchar(num,sizeof(num),0);
  fillchar(f,sizeof(f),0);
  fillchar(sum,sizeof(sum),0);
  readln(n);
  for i:=1 to n do
    read(num[i]);
  for i:=1 to n do
    sum[i,1]:=num[i];
  for j:=2 to n do
    for i:=1 to n-j+1 do
      sum[i,j]:=sum[i,j-1]+num[i+j-1];
  for j:=2 to n do
    for i:=1 to n-j+1 do
      begin
        s:=maxlongint;
        for k:=1 to j-1 do
          if f[i,k]+f[i+k,j-k]+sum[i,j]<s then
            s:=f[i,k]+f[i+k,j-k]+sum[i,j];
        f[i,j]:=s;
      end;
  writeln(f[1,n]);
end.


