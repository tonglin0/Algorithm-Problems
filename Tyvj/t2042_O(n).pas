var
  a:array[0..50001]of longint;
  i,j,k,m,n,l,r:longint;
begin
  assign(input,'2042.in');assign(output,'b.out');reset(input);rewrite(output);
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    begin
      readln(l,r);
      inc(a[l]);
      dec(a[r+1]);
    end;
  for i:=1 to 50000 do
    a[i]:=a[i-1]+a[i];
  readln(m);
  for i:=1 to m do
    begin
      readln(k);
      writeln(a[k]);
    end;
  close(input);close(output);
end.

