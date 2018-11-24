var
  f:array[1..100,0..100]of longint;
  a:array[1..100]of longint;
  n,m,i,min,mink,j,k,l:longint;
begin
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=2 to n-1 do
    f[i,1]:=a[i-1]*a[i]*a[i+1];
  for j:=2 to n-2 do
    for i:=2 to n-j do
      begin
        f[i,j]:=maxlongint;
        for k:=0 to j-1 do
          if f[i,k]+f[i+k+1,j-k-1]+a[i+k]*a[i-1]*a[i+j]<f[i,j] then
            f[i,j]:=f[i,k]+f[i+k+1,j-k-1]+a[i+k]*a[i-1]*a[i+j];
      end;
  writeln(f[2,n-2]);
end.




