var
  a:array[1..100]of longint;
  i,j,k,n:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  if n=0 then begin writeln(0);halt;end;
  i:=0;
  while n<>0 do
    begin
      inc(i);
      a[i]:=n mod (-2);
      n:=n div (-2);
      if a[i]<0 then
        begin
          inc(a[i],2);
          inc(n);
        end;
    end;
  for j:=i downto 1 do
    write(a[j]);
end.

