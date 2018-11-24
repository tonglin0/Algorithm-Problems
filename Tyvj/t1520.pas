type
  node=record
    no,w:longint;
  end;
var
  t:array[1..10000,1..100]of node;
  v:array[1..10000]of boolean;
  q:array[1..10000,1..2]of longint;
  dis:array[1..10000]of longint;
  i,kk,x,y,w,j,k,m,n,s:longint;
  procedure add(x,y,w:longint);
    var
      i,j:longint;
    begin
      for i:=1 to 100 do
      begin
      if t[x,i].no=0 then
        begin
          t[x,i].no:=y;
          t[x,i].w:=w;
          exit;
        end;
      end;
    end;
  function bfs2(k:longint):longint;
    var
      max,i,j,maxn,r,f:longint;
    begin
      r:=1;
      f:=0;
      fillchar(v,sizeof(v),false);
      fillchar(q,sizeof(q),0);
      fillchar(dis,sizeof(dis),0);
      q[1,1]:=k;
      v[k]:=true;
      q[1,2]:=0;
      while f<r do
        begin
          inc(f);
          for i:=1 to 100 do
            if t[q[f,1],i].no=0 then break
            else if not v[t[q[f,1],i].no] then
              begin
                inc(r);
                v[t[q[f,1],i].no]:=true;
                q[r,1]:=t[q[f,1],i].no;
                q[r,2]:=q[f,2]+t[q[f,1],i].w;
                dis[q[r,1]]:=q[r,2];
              end;
        end;
      max:=-1;
      for i:=1 to n do
        if dis[i]>max then
          begin
            max:=dis[i];
            maxn:=i;
          end;
      exit(max);
    end;
  function bfs(k:longint):longint;
    var
      max,i,j,maxn,r,f:longint;
    begin
      r:=1;
      f:=0;
      fillchar(v,sizeof(v),false);
      fillchar(q,sizeof(q),0);
      fillchar(dis,sizeof(dis),0);
      q[1,1]:=k;
      q[1,2]:=0;
      v[k]:=true;
      while f<r do
        begin
          inc(f);
          for i:=1 to 100 do
            if t[q[f,1],i].no=0 then break
            else if not v[t[q[f,1],i].no] then
              begin
                inc(r);
                v[t[q[f,1],i].no]:=true;
                q[r,1]:=t[q[f,1],i].no;
                q[r,2]:=q[f,2]+t[q[f,1],i].w;
                dis[q[r,1]]:=q[r,2];
              end;
        end;
      max:=-1;
      for i:=1 to n do
        if dis[i]>max then
          begin
            max:=dis[i];
            maxn:=i;
          end;
      exit(maxn);
    end;
begin
  fillchar(t,sizeof(t),0);
  fillchar(v,sizeof(v),false);
  fillchar(q,sizeof(q),0);
  fillchar(dis,sizeof(dis),0);
  readln(n);
  for i:=1 to n-1 do
    begin
      readln(x,y,w);
      add(x,y,w);
      add(y,x,w);
    end;
  kk:=bfs(1);
  writeln(bfs2(kk));
end.


