type
  pt=^node;
  node=record
    k,s:longint;
    next:pt;
  end;
const
  ha=1000017;
  mn=10010;
var
  f:Array[0..30000]of longint;
  h:array[0..ha]of pt;
  i,j,k,m,fa,fb,fa2,fb2,n,s,a,b,t,x,y:longint;
  st:ansistring;
  p,q:pt;
  function find(x:longint):longint;
    begin
      if f[x]=x then exit(x);
      f[x]:=find(f[x]);
      exit(f[x]);
    end;
  function get(x:longint):longint;
    var
      p,q:pt;
      i,j:longint;
    begin
      j:=x mod ha;
      p:=h[j];
      while p<>nil do
        begin
          if p^.s=x then
            exit(p^.k)
          else
            p:=p^.next;
        end;
      new(p);
      inc(t);
      p^.s:=x;
      p^.k:=t;
      p^.next:=h[j];
      h[j]:=p;
      exit(t);
    end;
begin
  for i:=0 to 30000 do
    f[i]:=i;
  for i:=0 to ha do
    h[i]:=nil;
  readln(m);
  readln(n);
  t:=0;
  for i:=1 to n do
    begin
      read(a,b);
      readln(st);
      dec(a);
      x:=get(a);
      y:=get(b);
      if pos('o',st)<>0 then
        begin
          fa:=find(x);
          fb:=find(y);
          fa2:=find(x+mn);
          fb2:=find(y+mn);
          if (fa=fb)or(fa2=fb2) then
            begin
              writeln(i-1);
              halt;
            end;
          f[fa]:=fb2;
          f[fa2]:=fb;
        end
      else
        begin
          fa:=find(x);
          fb:=find(y);
          fa2:=find(x+mn);
          fb2:=find(y+mn);
          if (fa=fb2)or(fb=fa2) then
            begin
              writeln(i-1);
              halt;
            end;
          f[fa]:=fb;
          f[fa2]:=fb2;
        end;
    end;
  writeln(n);
end.
