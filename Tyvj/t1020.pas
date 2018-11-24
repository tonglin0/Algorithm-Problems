var
  p:array[1..20000]of boolean;
  q:array[1..10000]of longint;
  i,j,k,l,max,x,m,n:longint;
begin
  readln(n);
  fillchar(p,sizeof(p),true);
  i:=2;
  m:=trunc(sqrt(20000));
  while i<=m do
    begin
      j:=i+i;
      while (j<=20000) do
        begin
          p[j]:=false;
          inc(j,i);
        end;
      inc(i);
      while (i<=m)and(p[i]=false) do
        inc(i);
    end;
  m:=0;
  for i:=1 to 20000 do
    if p[i] then
      begin
        inc(m);
        q[m]:=i;
      end;
  k:=1;
  max:=1;
  for i:=1 to n do
    begin
      readln(x);
      for j:=m downto k do
        if x mod q[j]=0 then
          begin
            max:=x;
            k:=j;
            break;
          end;
    end;
  writeln(max);
end.


