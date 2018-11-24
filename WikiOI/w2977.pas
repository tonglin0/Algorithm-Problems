var
  a:array[0..150002]of longint;
  i,j,k,m,n,s,t:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    read(A[i]);
  for i:=1 to n do
    begin
      if a[i shl 1]=0 then break;
      if a[i shl 1]<a[i] then
        begin
          writeln('NO');
          halt;
        end;
      if a[i shl 1+1]=0 then break;
      if a[i shl 1+1]<a[i] then
       begin
         writeln('NO');
         halt;
       end;
    end;
  writeln('YES');
end.


