var
  a,b:Array[1..21]of longint;
  n,m,k,i,j,s,t,ans:longint;
  flag:boolean;
  procedure change(i,j:longint);
    begin
      t:=a[j];
      a[j]:=a[i];
      a[i]:=t;
      t:=b[j];
      b[j]:=b[i];
      b[i]:=t;
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(B,sizeof(B),0);
  readln(n,m);
  for i:=1 to n do
    readln(a[i],b[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[j]>a[i] then
        change(i,j);
  i:=1;
  ans:=0;
  while (i<=n)and(a[i]>=m) do
    begin
      inc(ans,b[i]);
      b[i]:=0;
      inc(i);
    end;
  if i>n then
    begin
      writeln(ans);
      halt;
    end;
  j:=i;
  k:=i;
  while true do
    begin
      j:=k;
      while (j<=n)And(b[j]=0) do
        inc(j);
      t:=m;
      while j<=n do
        begin
          while (b[j]>0)and(t-a[j]>=0)do
            begin
              dec(b[j]);
              dec(t,a[j]);
            end;
          inc(j);
        end;
      flag:=false;
      if t=0 then
        begin
          inc(ans);
          continue;
        end
      else
        for i:=n downto k do
          if b[i]>0 then
            begin
              dec(b[i]);
              inc(ans);
              flag:=true;
              break;
            end;
      if not flag then break;
    end;
  writeln(ans);
end.



