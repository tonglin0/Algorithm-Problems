type
  node=record
    u,v,w:longint;
  end;
var
  q:array[0..10010]of node;
  map:array[0..101,0..101]of longint;
  f:array[0..101]of longint;
  i,j,n,m,k,s,t:longint;
  procedure qsort(h,t:longint);
    var
      x:node;
      i,j,tt:longint;
    begin
      i:=h;
      j:=t;
      tt:=random(t-h)+h;
      x:=q[tt];
      q[tt]:=q[h];
      q[h]:=x;
      while i<j do
        begin
          while (i<j)and(q[j].w>=x.w) do
            dec(j);
          q[i]:=q[j];
          while (i<j)and(q[i].w<=x.w) do
            inc(i);
          q[j]:=q[i];
        end;
      q[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
  function find(x:longint):longint;
    begin
      if f[x]=x then exit(x);
      f[x]:=find(f[x]);
      exit(f[x]);
    end;
begin
  fillchar(q,sizeof(q),0);
  fillchar(map,sizeof(map),0);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(map[i,j]);
  t:=0;
  for i:=1 to n do
    for j:=i+1 to n do
      if map[i,j]<>0 then
        begin
          inc(t);
          q[t].u:=i;
          q[t].v:=j;
          q[t].w:=map[i,j];
        end;
  randomize;
  qsort(1,t);
  {for i:=1 to t do
    write(q[i].w,' ');
  halt;    }
  for i:=1 to n do
    f[i]:=i;
  s:=0;
  k:=0;
  i:=0;
  while k<n-1 do
    begin
      inc(i);
      if find(q[i].u)<>find(q[i].v) then
        begin
          inc(s,q[i].w);
          f[find(q[i].u)]:=find(q[i].v);
          inc(k);
        end;
    end;
  writeln(s);
end.

