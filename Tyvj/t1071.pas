var
  a,b:Array[0..3001]of longint;
  f:Array[0..3001,0..3001]of longint;
  i,j,k,m,max,n,s,t,ans:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  if n<=200 then
    begin
    for i:=1 to n do
      for j:=1 to n do
        if a[i]=b[j] then
          begin
            max:=0;
            for k:=1 to j-1 do
              if (b[k]<a[i])and(f[i-1,k]>max) then
                max:=f[i-1,k];
            f[i,j]:=max+1;
          end
        else
          f[i,j]:=f[i-1,j];
    max:=-maxlongint;
    for i:=1 to n do
      if f[n,i]>max then
        max:=f[n,i];
    writeln(max);
    halt;
    end;
  for i:=1 to n do
    begin                        {
      for j:=1 to n do
        if a[i]=b[j] then
          begin
            max:=0;
            for k:=1 to j-1 do
              if (b[k]<a[i])and(f[i-1,k]>max) then
                max:=f[i-1,k];
            f[i,j]:=max+1;
          end
        else
          f[i,j]:=f[i-1,j];
    end;                        }

      max:=0;
      for j:=1 to n do
        begin
          f[i,j]:=f[i-1,j];
          if (a[i]>b[j])and(f[i-1,j]>max)then
            max:=f[i-1,j]
          else if (a[i]=b[j])and(max+1>f[i,j]) then
            f[i,j]:=max+1;
        end;
    end;    {
  for i:=1 to n do
    write(f[n,i],' ');
  writeln;
  halt;      }
  max:=-maxlongint;
  for i:=1 to n do
    if f[n,i]>max then
      max:=f[n,i];
  writeln(max);
end.

