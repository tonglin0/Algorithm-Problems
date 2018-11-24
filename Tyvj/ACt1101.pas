var
  i,j,n:longint;
  a:array[1..10000]of ansistring;
  procedure qsort(h,t:longint);
    var
      i,j,tt:longint;
      x:ansistring;
    begin
      i:=h;
      j:=t;
      randomize;
      tt:=random(t-h)+h;
      x:=a[tt];
      a[tt]:=a[h];
      a[h]:=x;
      while i<j do
        begin
          while (i<j)and(a[j]>=x) do
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
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  qsort(1,n);
  for i:=1 to n do
    writeln(a[i]);
end.

