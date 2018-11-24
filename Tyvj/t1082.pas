var
  i,j,k,n,m:longint;
  a:array[1..10000]of longint;
  b:array[1..10000]of string;
  procedure qsort(h,t:longint);
    var
      x:longint;
    begin
      i:=h;
      j:=t;
      x:=a[h];
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
  procedure qqsort(h,t:longint);
    var
      x:string;
    begin
      i:=h;
      j:=t;
      x:=b[h];
      while i<j do
        begin
          while (i<j)and(b[j]>=x)do
            dec(j);
          b[i]:=b[j];
          while (i<j)and(b[i]<=x)do
            inc(i);
          b[j]:=b[i];
        end;
      b[i]:=x;
      if i-1>h then qqsort(h,i-1);
      if j+1<t then qqsort(j+1,t);
    end;
begin
  //assign(input,'1082.in');reset(input);
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    readln(b[i]);
  for i:=1 to n do
    readln(a[i]);
  qsort(1,n);
  qqsort(1,n);
  for i:=1 to n do
    writeln(b[i],' ',a[i]);
  //close(input);
end.


