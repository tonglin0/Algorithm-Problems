var
  a:array[0..1000]of int64;
  f,b:Array[0..1000,0..1000]of int64;
  i,j,n,m,k,t,s:longint;
  function find(i,j:longint):int64;
    var
      k:longint;
      ii:int64;
    begin
      if f[i,j]>0 then exit(f[i,j]);
      if j<i then exit(1);
      if i=j then exit(a[i]);
      for k:=i to j do
        begin
          ii:=find(i,k-1)*find(k+1,j)+a[k];
          if ii>f[i,j] then
            begin
              f[i,j]:=ii;
              b[i,j]:=k;
            end;
        end;
      exit(f[i,j]);
    end;
  procedure print(i,j:longint);
    begin
      if b[i,j]=0 then exit;
      if (i=1)and(j=n) then write(b[i,j])
        else write(' ',b[i,j]);
      print(i,b[i,j]-1);
      print(b[i,j]+1,j);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    b[i,i]:=i;
  f[1,n]:=find(1,n);
  writeln(f[1,n]);
  print(1,n);
end.
