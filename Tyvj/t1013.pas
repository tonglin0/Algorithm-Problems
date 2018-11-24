var
  f:array[0..100,0..100,0..100,1..2]of longint;
  i,j,k,l,n,m,r:longint;
  a,b,c:array[1..100]of longint;
begin
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    readln(a[i],b[i],c[i]);
  readln(m,r);
  for i:=1 to n do
    for j:=0 to m do
      for k:=0 to r do
        begin
          f[i,j,k,1]:=f[i-1,j,k,1];
          f[i,j,k,2]:=f[i-1,j,k,2];
          if (j>=a[i])and(k>=b[i]) then
            begin
              if (f[i-1,j-a[i],k-b[i],1]+1>f[i,j,k,1])or((f[i-1,j-a[i],k-b[i],1]+1=f[i,j,k,1])and(f[i-1,j-a[i],k-b[i],2]+c[i]<f[i,j,k,2])) then
                begin
                  f[i,j,k,1]:=f[i-1,j-a[i],k-b[i],1]+1;
                  f[i,j,k,2]:=f[i-1,j-a[i],k-b[i],2]+c[i];
                end;
            end;
        end;
  writeln(f[n,m,r,2]);
end.


