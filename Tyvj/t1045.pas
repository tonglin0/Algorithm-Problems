var
  f:Array[0..100,0..100,0..100]of longint;
  v:array[0..100,0..100,0..100]of boolean;
  a:Array[0..100]of longint;
  sum:array[0..100,0..100]of longint;
  i,j,k,m,n,s,t:longint;
  function max(a,b:longint):longint;
    begin
      if a>b then exit(a);
      exit(b);
    end;
  function find(i,j,k:longint):longint;
    var
      ii,jj:longint;
    begin
      if j<i then exit(0);
      if v[i,j,k] then exit(f[i,j,k]);
      if k>j-i then exit(0);
      v[i,j,k]:=true;
      if k=0 then
        begin
          f[i,j,k]:=sum[i,j-i+1];
          exit(sum[i,j-i+1]);
        end;
      for jj:=0 to k-1 do
        for ii:=i+jj to j-1 do
          f[i,j,k]:=max(f[i,j,k],find(i,ii,jj)*find(ii+1,j,k-jj-1));
      exit(f[i,j,k]);
    end;
begin
  //assign(input,'1045.in');reset(input);
  //assign(output,'1045.out');rewrite(output);
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),false);
  fillchar(a,sizeof(a),0);
  fillchar(sum,sizeof(sum),0);
  read(n,m);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    sum[i,1]:=a[i];
  for j:=2 to n do
    for i:=1 to n-j+1 do
      sum[i,j]:=sum[i+1,j-1]+a[i];
  f[1,n,m]:=find(1,n,m);
  writeln(f[1,n,m]);  {
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to m do
        writeln('i=',i,' j=',j,' k=',k,'  ',f[i,j,k]);
  close(output); }
end.


