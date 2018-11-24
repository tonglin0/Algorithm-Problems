type
  node=record
    u,v,w:longint;
  end;
var
  fa:array[0..100002]of longint;
  a:array[0..100002]of node;
  ig,i,j,k,m,n,s,t,u,w,v:longint;
  ans:int64;
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
          while (i<j)and(a[j].w>=x.w) do
            dec(j);
          a[i]:=a[j];
          while (i<j)and(A[i].w<=x.w) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
  function find(x:longint):longint;
    begin
      if fa[x]=x then exit(x);
      fa[x]:=find(fa[x]);
      exit(Fa[x]);
    end;
begin
  fillchar(fa,sizeof(fa),0);
  fillchar(a,sizeof(a),0);
  readln(n,m);
  for i:=1 to m do
    readln(a[i].u,a[i].v,a[i].w);
  for i:=1 to n do
    fa[i]:=i;
  randomize;
  qs(1,m);
  ig:=0;
  i:=0;
  ans:=0;
  while ig<n-1 do
    begin
      inc(i);
      u:=a[i].u;
      v:=a[i].v;
      if find(u)<>find(v) then
        begin
          inc(ig);
          inc(ans,a[i].w);
          fa[find(u)]:=fa[v];
        end;
    end;
  writeln(ans);
end.
