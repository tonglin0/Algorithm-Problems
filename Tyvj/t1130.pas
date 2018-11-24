type
  node=record
    a,b,c,o,s:longint;
  end;
var
  q:array[1..300]of node;
  i,j,k,n,m:longint;
  procedure qsort(h,t:longint);
    var
      i,j,tt:longint;
      x:node;
    begin
      i:=h;
      j:=t;
      randomize;
      tt:=random(t-h)+h;
      x:=q[tt];
      q[tt]:=q[h];
      q[h]:=x;
      while i<j do
        begin
          while (i<j)and((q[j].s>x.s)or((q[j].s=x.s)and(q[j].a>x.a))or((q[j].s=x.s)and(q[j].a=x.a)and(q[j].o<x.o))) do
            dec(j);
          q[i]:=q[j];
          while (i<j)and((q[i].s<x.s)or((q[i].s=x.s)and(q[i].a<x.a))or((q[i].s=x.s)and(q[i].a=x.a)and(q[i].o>x.o))) do
            inc(i);
          q[j]:=q[i];
        end;
      q[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
begin
  readln(n);
  fillchar(q,sizeof(q),0);
  for i:=1 to n do
    begin
      with q[i] do
        begin
          readln(a,b,c);
          o:=i;
          s:=a+b+c;
        end;
    end;
  qsort(1,n);
  for i:=n downto n-4 do
    writeln(q[i].o,' ',q[i].s);
end.


