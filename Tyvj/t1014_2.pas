var
  f:array[1..100,1..100]of longint;
  a:array[1..100]of longint;
  i,j,k,m,n,l:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
begin
  assign(input,'1014.in');reset(input);assign(output,'1014_2.out');rewrite(output);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=2 to n-1 do
    f[i,i]:=a[i-1]*a[i]*a[i+1];
  for j:=2 to n-2 do
    for i:=2 to n-j+1 do
      begin
        f[i,i+j-1]:=maxlongint;
        for k:=i to i+j-1 do
          f[i,i+j-1]:=min(f[i,i+j-1],f[i,k-1]+f[k+1,i+j-1]+a[k]*a[i-1]*a[i+j])
      end;
  writeln(f[2,n-1]);
  close(input);close(output);
end.


