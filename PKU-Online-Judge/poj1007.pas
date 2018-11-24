type
  node=record
    t:longint;
    a:array[1..50]of char;
  end;
const
  cr:array[1..4]of char=('A','C','G','T');
var
  q:array[1..100]of node;
  s:string;
  i,j,time,n,m:longint;
  procedure swap(var x,y:char);
    var
      ch:char;
    begin
      ch:=x;
      x:=y;
      y:=ch;
    end;
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
          while (i<j)and(q[j].t>=x.t) do
            dec(j);
          q[i]:=q[j];
          while (i<j)and(q[i].t<=x.t) do
            inc(i);
          q[j]:=q[i];
        end;
      q[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
begin
  //assign(input,'1007.in');assign(output,'1007.out');reset(input);rewrite(output);
  fillchar(q,sizeof(q),0);
  readln(m,n);
  for time:=1 to n do
    begin
      readln(s);
      for i:=1 to m do
        q[time].a[i]:=s[i];
      for i:=m-1 downto 1 do
        for j:=1 to i do
          if q[time].a[j]>q[time].a[j+1] then
            begin
              inc(q[time].t);
              swap(q[time].a[j],q[time].a[j+1]);
            end;     {
      writeln(q[time].t);
      for i:=1 to m do
      write(q[time].a[i],' ');
      writeln;        }
      for i:=1 to m do
        q[time].a[i]:=s[i];
    end;
  qsort(1,n);
  for i:=1 to n do
    begin
      for j:=1 to m do
        write(q[i].a[j]);
      writeln;
    end;
  //close(input);close(output);
end.


