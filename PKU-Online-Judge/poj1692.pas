var
  f:array[0..1000,0..1000]of longint;
  a,b:array[1..1000]of longint;
  i,j,k,l,m,n,t,ii:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  readln(t);
  for ii:=1 to t do
    begin
      fillchar(f,sizeof(f),0);
      readln(n,m);
      for i:=1 to n do
        read(a[i]);
      for i:=1 to m do
        read(b[i]);
      for i:=1 to n do
        for j:=1 to m do
          begin
            f[i,j]:=max(f[i-1,j],f[i,j-1]);
            if a[i]=b[j] then continue;
            for k:=1 to i-1 do
              if a[k]=b[j] then
                begin
                  for l:=1 to j-1 do
                    if b[l]=a[i] then
                      f[i,j]:=max(f[i,j],f[k-1,l-1]+2);
                end;
          end;
      writeln(f[n,m]);
    end;
end.



