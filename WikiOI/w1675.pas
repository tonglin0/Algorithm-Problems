//uses sysutils;
var
  v:Array[1..1000001]of boolean;
  i,j,n,m,k:longint;
  //t:double;
begin
  //t:=now*86400;
  //assign(output,'1.out');
  //rewrite(output);
  fillchar(v,sizeof(v),true);
  i:=2;
  read(n);
  k:=trunc(sqrt(n));
  while i<=k do
    begin
      j:=i*i;
      while j<n do
        begin
          v[j]:=false;
          j:=j+i;
        end;
      inc(i);
      while not v[i] do
        inc(i);
    end;
  for i:=2 to n-1 do
    if v[i] then writeln(i);
  //writeln((now*86400-t):0:8);
  //close(output);
end.


