type
  pt=^pk;
  pk=record
    data,n:longint;
    next:pt;
  end;
const
  mn=1000017;
var
  h:Array[0..1000017]of pt;
  a:Array[0..30001]of longint;
  t,i,j,k,m,n,s,ans:longint;
  p,q:pt;
  procedure add(x:longint);
    var
      i,j:longint;
      p,q:pt;
    begin
      k:=m mod mn;
      p:=h[k];
      if p=nil then
        begin
          new(h[k]);
          h[k]^.next:=nil;
          h[k]^.data:=x;
          h[k]^.n:=1;
          inc(t);
          a[t]:=x;
        end
      else
        begin
          while p<>nil do
            begin
              q:=p;
              if q^.data=x then
                begin
                  inc(q^.n);
                  exit;
                end;
              p:=p^.next;
            end;
          new(p);
          p^.data:=x;
          p^.next:=nil;
          p^.n:=1;
          inc(t);
          a[t]:=x;
        end;
    end;
  procedure qs(h,t:longint);
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
          while(i<j)and(a[j]>=x) do
            dec(j);
          a[i]:=a[j];
          while(i<j)and(a[i]<=x) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
  function qus(x:longint):longint;
    var
      i,j,k:longint;
      p,q:pt;
    begin
      k:=x mod mn;
      p:=h[k];
      while (p<>nil)and(p^.data<>x) do
        p:=p^.next;
      exit(p^.n);
    end;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=0 to mn do
    h[i]:=nil;
  t:=0;
  for i:=1 to n do
    begin
      read(m);
      add(m);
    end;
  randomize;
  qs(1,t);     {
  for i:=1 to t do
    write(a[i],' ');
  halt;       }
  for i:=1 to t do
    writeln(a[i],' ',qus(a[i]));
end.
