type
  arr=array[1..2001]of longint;
var
  h,n,m,i,j,k,l,s:longint;
  a,b:array[1..2001]of longint;
  procedure qsort(var a:arr;h,t:longint);
    var
      x,i,j,tt:longint;
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
          while (i<j)and(a[j]<=x) do
            dec(j);
          a[i]:=a[j];
          while (i<j)and(a[i]>=x) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qsort(a,h,i-1);
      if j+1<t then qsort(a,j+1,t);
    end;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n-1 do
    read(a[i]);
  for j:=1 to m-1 do
    read(b[j]);
  qsort(a,1,n);
  qsort(b,1,m);
  h:=1;
  l:=1;
  s:=0;
  while not((h=n)and(l=m)) do
    begin
      if h=n then
        begin
          inc(s,h*b[l]);
          inc(l);
          continue;
        end;
      if l=m then
        begin
          inc(s,l*a[h]);
          inc(h);
          continue;
        end;
      if a[h]>=b[l] then
        begin
          inc(s,l*a[h]);
          inc(h);
          continue;
        end
      else
        begin
          inc(s,h*b[l]);
          inc(l);
          continue;
        end;
    end;
  writeln(s);
end.



