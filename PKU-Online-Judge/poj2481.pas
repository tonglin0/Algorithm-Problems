//const
  //w=100001;
type
  node=record
    x,y,p:longint;
  end;
var
  ans:array[1..100000]of longint;
  c:array[0..100002]of longint;
  a:array[1..100002]of node;
  i,j,k,p,s,n,m,t:longint;
  function low(k:longint):longint;
    begin
      low:=k and(k xor (k-1));
    end;
  function get(i:longint):longint;
    var
      s:longint;
    begin
      s:=0;
      while i<=t do
        begin
          s:=s+c[i];
          i:=i+low(i);
        end;
      exit(s);
    end;
  procedure add(i:longint);
    begin
      while i>0 do
        begin
          inc(c[i]);
          i:=i-low(i);
        end;
    end;
  procedure qsort(h,t:longint);
    var
      i,j,tt:longint;
      x:node;
    begin
      i:=h;
      j:=t;
      //randomize;
      tt:=random(t-h)+h;
      x:=a[tt];
      a[tt]:=a[h];
      a[h]:=x;
      while i<j do
        begin
          while (i<j)and((a[j].x>x.x)or(a[j].x=x.x)and(a[j].y<=x.y))do
            dec(j);
          a[i]:=a[j];
          while (i<j)and((a[i].x<x.x)or(a[i].x=x.x)and(a[i].y>=x.y))do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
begin
  read(n);
while n<>0 do
begin
  t:=0;
  fillchar(ans,sizeof(ans),0);
  fillchar(a,sizeof(a),0);
  fillchar(c,sizeof(c),0);
  //w:=0;
  for i:=1 to n do
    begin
      read(a[i].x,a[i].y);
      a[i].p:=i;
      if a[i].y>t then t:=a[i].y;
      //if a[i].y>w then w:=a[i].y;
    end;           {
  for i:=1 to n do
    begin
      //a[i].y:=w-a[i].y;
      a[i].p:=i;
      if a[i].y>t then t:=a[i].y;
    end;            }
  randomize;
  qsort(1,n);
  for i:=1 to n do
    begin
      if (i>1)and(a[i].x=a[i-1].x)and(a[i].y=a[i-1].y) then
        begin
          ans[a[i].p]:=s;
          add(a[i].y);
          continue;
        end;
      s:=get(a[i].y);
      ans[a[i].p]:=s;
      add(a[i].y);
    end;
  for i:=1 to n-1 do
    write(ans[i],' ');
  writeln(ans[n]);
  readln;
  read(n);
end;
end.



