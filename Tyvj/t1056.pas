var
  f:array[0..301,0..201]of longint;
  a:Array[0..301]of longint;
  p,i,j,k,m,n,s,t,ans,max:longint;
begin
  fillchar(a,sizeof(A),0);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  m:=n shl 1-1;
  for i:=n+1 to m+1 do
    a[i]:=a[i-n];
  for p:=1 to n-1 do
    for i:=1 to m-1 do
      begin
        j:=p+i;
        if j>m then break;
        for k:=i to j-1 do
          if f[i,k]+f[k+1,j]+a[i]*a[k+1]*a[j+1]>f[i,j] then
            f[i,j]:=f[i,k]+f[k+1,j]+a[i]*a[k+1]*a[j+1];
      end;
  max:=-1;
  for i:=1 to n do
    if f[i,i+n-1]>max then
      max:=f[i,i+n-1];
  writeln(max);
end.


