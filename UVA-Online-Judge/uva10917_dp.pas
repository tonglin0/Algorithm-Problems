const
  nn=1001;
var
  fv:array[0..1001]of boolean;
  q:Array[0..nn]of longint;
  ins:array[0..nn]of boolean;
  ng:array[0..nn,0..nn]of longint;
  a:array[0..nn,0..nn]of longint;
  map:array[0..nn,0..nn]of longint;
  dis:array[0..nn]of longint;
  vis:Array[0..nn]of boolean;
  nm:array[0..nn,0..nn]of boolean;
  f:array[0..nn]of longint;
  i,j,k,m,u,v,w,n,s,t,st,ff,r,en:longint;
  procedure dijk;
    var
      i,j,min,minj:longint;
    begin
      fillchar(dis,sizeof(dis),127);
      fillchar(vis,sizeof(vis),false);
      dis[2]:=0;
      for i:=1 to n-1 do
        begin
          min:=dis[0];
          for j:=1 to n do
            if (not vis[j])and(dis[j]<min) then
              begin
                min:=dis[j];
                minj:=j;
              end;
          vis[minj]:=true;
          for j:=1 to a[minj,0] do
            if (not vis[a[minj,j]])and(dis[minj]<dis[a[minj,j]]-map[minj,a[minj,j]]) then
              dis[a[minj,j]]:=dis[minj]+map[minj,a[minj,j]];
        end;
    end;
  function dfs(u:longint):longint;
    var
      ans,i:longint;
    begin
      if fv[u] then
        exit(F[u]);
      ans:=0;
      for i:=1 to n do
        if nm[u,i] then
          ans:=ans+dfs(i);
      f[u]:=ans;
      fv[u]:=true;
      exit(f[u]);
    end;
begin
  //assign(input,'10917.in');reset(input);
  read(n);
  while n<>0 do
    begin
      read(m);
      fillchar(ng,sizeof(ng),0);
      fillchar(map,sizeof(map),0);
      fillchar(a,sizeof(a),0);
      for i:=1 to m do
        begin
          readln(u,v,w);
          map[u,v]:=w;
          map[v,u]:=w;
          inc(a[u,0]);
          a[u,a[u,0]]:=v;
          inc(a[v,0]);
          a[v,a[v,0]]:=u;
        end;
      dijk;
      fillchar(nm,sizeof(nm),false);
      for i:=1 to n do
        for j:=1 to a[i,0] do
          begin
            u:=i;
            v:=a[i,j];
            if dis[v]<dis[u] then
              nm[v,u]:=true;
          end;
      fillchar(fv,sizeof(fv),false);
      fillchar(f,sizeof(f),0);
      f[1]:=1;
      fv[1]:=true;
      f[2]:=dfs(2);
      writeln(f[2]);
      read(n);
    end;
end.

