var
  a,b,map:array[0..1000,0..1000]of longint;
  i,j,k,n,m,s,t:longint;
begin
  //assign(input,'1238.in');reset(input);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(map,sizeof(map),0);
  readln(n,m);
  for i:=1 to m do
    begin
      read(s,t,k);
      inc(s);
      inc(t);
      a[s,t]:=1;
      b[s,t]:=k;
    end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if (i<>j)and(j<>k)and(i<>j)and(a[i,k]>0)and(a[k,j]>0)and((a[i,j]=0)or(a[i,k]+a[k,j]<a[i,j])or((a[i,k]+a[k,j]=a[i,j])and(b[i,k]+b[k,j]<b[i,j]))) then
          begin
            a[i,j]:=a[i,k]+a[k,j];
            b[i,j]:=b[i,k]+b[k,j];
          end;
   writeln(b[1,2]);
   //close(input);
end.


