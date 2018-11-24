type
  node=record
    x,y,h:longint;
  end;
const
  dx:array[1..4]of longint=(0,-1,0,1);
  dy:array[1..4]of longint=(-1,0,1,0);
var
  mx,tx,ty,my,n,m,th,ans,i,j,k,l,t:longint;
  q:array[1..10000]of node;
  map:array[1..100,1..100]of longint;
  f:array[1..100,1..100]of longint;
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
          while (i<j)and(q[j].h>=x.h) do
            dec(j);
          q[i]:=q[j];
          while (i<j)and(q[i].h<=x.h) do
            inc(i);
          q[j]:=q[i];
        end;
      q[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
  function max(x,y:longint):longint;
    begin
      if x>=y then exit(x)
        else exit(y);
    end;
begin
  fillchar(q,sizeof(q),0);
  fillchar(map,sizeof(map),0);
  fillchar(f,sizeof(f),0);
  readln(n,m);
  t:=0;
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          f[i,j]:=1;
          read(map[i,j]);
          inc(t);
          q[t].x:=i;
          q[t].y:=j;
          q[t].h:=map[i,j];
        end;
      readln;
    end;
  qsort(1,t);
  ans:=-1;
  for i:=1 to t do
    begin
      tx:=q[i].x;
      ty:=q[i].y;
      th:=q[i].h;
      for j:=1 to 4 do
        begin
          mx:=tx+dx[j];
          my:=ty+dy[j];
          if (mx>=1)and(my>=1)and(mx<=n)and(my<=m)and(map[mx,my]<th)then
            f[tx,ty]:=max(f[tx,ty],f[mx,my]+1);
          if f[tx,ty]>ans then ans:=f[tx,ty];
        end;
    end;
  writeln(ans);
end.


