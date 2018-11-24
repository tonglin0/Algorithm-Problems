var
  a:array[1..1001]of longint;
  ans,n,m,i,s,j,k,t:longint;
  procedure qsort(h,t:longint);
    var
      tt,i,j,x:longint;
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
          while (i<j)and(a[j]>=x)do
            dec(j);
          a[i]:=a[j];
          while (i<j)and(a[i]<=x)do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
  function min(x,y:longint):longint;
    begin
      if x<=y then exit(x);
      exit(y);
    end;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  ans:=0;
  qsort(1,n);
  if odd(n) then
    inc(ans,a[1]+a[2]+a[3])
  else
    inc(ans,a[2]);
  while n>3 do
    begin
      s:=min(a[2]+a[1]+a[n]+a[2],a[n]+a[1]+a[n-1]+a[1]);
      inc(ans,s);
      dec(n,2);
    end;
  writeln(Ans);
end.


