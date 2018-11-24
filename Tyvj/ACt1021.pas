var
  a:array[1..10001]of longint;
  i,j,n,m,s,t:longint;
  ans:int64;
  procedure qs(h,t:longint);
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
          while(i<j)and(a[j]>=x) do
            dec(j);
          a[i]:=a[j];
          while (i<j)and(a[i]<=x) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  qs(1,n);
  ans:=0;
  for i:=1 to n-1 do
    inc(ans,i*(a[i+1]-a[i])*(n-i));
  writeln(ans*2);
end.
