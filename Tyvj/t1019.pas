var
  a,b:array[1..10000]of longint;
  i,j,n,s:longint;
  procedure qsort(h,t:longint);
    var
      i,j,tt:longint;
      x:longint;
    begin
      i:=h;
      j:=t;
      x:=a[h];
      while i<j do
        begin
          while (i<j)And(a[j]>=x) do
            dec(j);
          a[i]:=a[j];
          while (i<j)and(a[i]<=x) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
  procedure qqsort(h,t:longint);
    var
      i,j,tt:longint;
      x:longint;
    begin
      i:=h;
      j:=t;
      x:=b[h];
      while i<j do
        begin
          while (i<j)And(b[j]>=x) do
            dec(j);
          b[i]:=b[j];
          while (i<j)and(b[i]<=x) do
            inc(i);
          b[j]:=b[i];
        end;
      b[i]:=x;
      if i-1>h then qqsort(h,i-1);
      if j+1<t then qqsort(j+1,t);
    end;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  qsort(1,n);
  qqsort(1,n);
  s:=0;
  for i:=1 to n do
    inc(s,abs(a[i]-b[n-i+1]));
  writeln(S);
end.