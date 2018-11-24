type
  arr=array[0..1001]of longint;
var
  a,b:array[0..1001]of longint;
  f:Array[0..1001,0..1001]of longint;
  v:Array[0..1001,0..1001]of boolean;
  i,j,k,m,n,s,t:longint;
  function max(a,b:longint):longint;
    begin
      if a>b then exit(a);
      exit(b);
    end;
  function find(i,j:longint):longint;
    var
      k,d:longint;
    begin
      if v[i,j] then exit(f[i,j]);
      v[i,j]:=true;
      k:=n-i-j;
      if k=0 then exit(0);
      d:=n-j;
      if a[d]<b[k] then
        f[i,j]:=find(i+1,j)-200
      else if a[d]>b[k] then
        f[i,j]:=find(i,j+1)+200
      else
        f[i,j]:=max(find(i+1,j)-200,find(i,j+1));
      exit(f[i,j]);
    end;
  procedure qs(var a:arr;h,t:longint);
    var
      i,j,x,tt:longint;
    begin
      i:=h;
      j:=t;
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
      if i-1>h then qs(a,h,i-1);
      if j+1<t then qs(a,j+1,t);
    end;
begin
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),false);
  read(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  randomize;
  qs(a,1,n);
  qs(b,1,n);
  f[0,0]:=find(0,0);
  writeln(f[0,0]);
end.
