var
  a:array[0..2001,1..2]of longint;
  i,j,k,m,n,s,t,ans:longint;
  f:Array[0..2001]of longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    read(a[i,1],a[i,2]);
  for i:=1 to n do
    for j:=i+1 to n do
      if ((a[j,2]<a[i,2])and(a[j,1]<a[i,1]))or((a[j,1]<a[i,2])and(a[j,2]<a[i,1])) then
        begin
          s:=a[i,1];
          t:=a[i,2];
          a[i,1]:=a[j,1];
          a[i,2]:=a[j,2];
          a[j,1]:=s;
          a[j,2]:=t;
        end;
  f[1]:=1;
  for i:=2 to n do
    begin
      s:=0;
      for j:=1 to i-1 do
        if (((a[j,1]<a[i,1])and(a[j,2]<a[i,2]))or((a[j,1]<a[i,2])and(a[j,2]<a[i,1])))and(f[j]>s) then
          s:=f[j];
      f[i]:=s+1;
    end;
  s:=0;
  for i:=1 to n do
    if f[i]>s then
      s:=f[i];
  writeln(s);
end.


