type
  node=record
    u,v,w:longint;
  end;
var
  a:array[0..5001]of node;
  f:array[0..501]of longint;
  i,j,k,n,m,st,en,x,y,ans1,ans2:longint;
  procedure qs(h,t:longint);
    var
      x:node;
      i,j,tt:longint;
    begin
      i:=h;
      j:=t;
      tt:=random(t-h)+h;
      x:=a[tt];
      a[tt]:=a[h];
      a[h]:=x;
      while i<j do
        begin
          while (i<j)And(a[j].w>=x.w) do
            dec(j);
          a[i]:=a[j];
          while (i<j)and(a[i].w<=x.w) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if h<i-1 then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
  function find(x:longint):longint;
    begin
      if f[x]=x then exit(x);
      f[x]:=find(f[x]);
      exit(F[x]);
    end;
  procedure union(x,y:longint);
    begin
      f[find(x)]:=find(y);
    end;
begin
  fillchar(a,sizeof(a),0);
  read(n,m);
  for i:=1 to m do
    read(a[i].u,a[i].v,a[i].w);
  read(st,en);
  randomize;
  qs(1,m);
  ans1:=1;
  ans2:=maxlongint;
  for i:=1 to m do
    begin
      for j:=1 to n do
        f[j]:=j;
      for j:=i to m do
        begin
          union(a[j].u,a[j].v);
          if find(st)=find(en) then
            break;
        end;
      if (find(st)=find(en))and(a[j].w/a[i].w<ans2/ans1) then
        begin
          ans1:=a[i].w;
          ans2:=a[j].w;
        end;
    end;
  if (ans1=1)and(ans2=maxlongint) then
    begin
      writeln('IMPOSSIBLE');
      halt;
    end;
  for i:=2 to ans1 do
    if (ans1 mod i=0)and(ans2 mod i=0) then
      begin
        ans1:=ans1 div i;
        ans2:=ans2 div i;
      end;
  if ans1=1 then writeln(ans2) else
  writeln(ans2,'/',ans1);
end.

