type
  node=record
    a,b:longint;
  end;
  arra=array[1..1000]of longint;
  arr=array[1..1000]of node;
var
  i,j,k,l,m,n,x,y,c,mx,my:longint;
  han,lie:array[1..1000]of node;
  a,b:arra;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
  procedure qsort(h,t:longint;var v:arr);
    var
      i,j:longint;
      x:node;
    begin
      i:=h;
      j:=t;
      x:=v[h];
      while i<j do
        begin
          while (i<j)and(v[j].a<=x.a) do
            dec(j);
          v[i]:=v[j];
          while (i<j)and(v[i].a>=x.a)do
            inc(i);
          v[j]:=v[i];
        end;
      v[i]:=x;
      if i-1>h then qsort(h,i-1,v);
      if j+1<t then qsort(j+1,t,v);
    end;
  procedure qsortt(h,t:longint;var v:arra);
    var
      i,j,x:longint;
    begin
      i:=h;
      j:=t;
      x:=v[h];
      while i<j do
        begin
          while (i<j)and(v[j]>=x) do
            dec(j);
          v[i]:=v[j];
          while (i<j)and(v[i]<=x)do
            inc(i);
          v[j]:=v[i];
        end;
      v[i]:=x;
      if i-1>h then qsortt(h,i-1,v);
      if j+1<t then qsortt(j+1,t,v);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(han,sizeof(han),0);
  fillchar(lie,sizeof(lie),0);
  readln(n,m,l,k,c);
  for i:=1 to n do
    han[i].b:=i;
  for i:=1 to n do
    lie[i].b:=i;
  for i:=1 to c do
    begin
      readln(x,y,mx,my);
      if x=mx then inc(lie[min(y,my)].a);
      if y=my then inc(han[min(x,mx)].a);
    end;
  qsort(1,n,han);
  for i:=1 to l do
    a[i]:=han[i].b;
  qsortt(1,l,a);
  for i:=1 to l-1 do
    write(a[i],' ');
  writeln(a[l]);
  qsort(1,m,lie);
  for i:=1 to k do
    a[i]:=lie[i].b;
  qsortt(1,k,a);
  for i:=1 to k-1 do
    write(a[i],' ');
  writeln(a[k]);
end.
