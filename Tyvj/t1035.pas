var
  xx,yy,m,n,i,j,k,l,s:longint;
  map:array[0..101,0..101]of longint;
  g:array[0..10000,0..4]of longint;
  x,y:array[1..5000]of longint;
  v:array[1..10000]of boolean;
  f:array[1..10000]of longint;
  function find(u:longint):boolean;
    var
      i:longint;
    begin
      for i:=1 to g[u,0] do
        if (not v[g[u,i]]) then
          begin
            v[g[u,i]]:=true;
            if (f[g[u,i]]=0)or(find(f[g[u,i]])) then
              begin
                f[g[u,i]]:=u;
                exit(true);
              end;
          end;
      exit(false);
    end;
begin
  fillchar(map,sizeof(map),0);
  fillchar(f,sizeof(f),0);
  fillchar(x,sizeof(x),0);
  fillchar(g,sizeof(g),0);
  fillchar(y,sizeof(y),0);
  readln(n,m);
  k:=0;
  for i:=1 to n do
    for j:=1 to n do
      begin
        inc(k);
        map[i,j]:=k;
      end;
  for i:=1 to m do
    begin
      readln(l,s);
      map[l,s]:=0;
    end;
  s:=0;
  xx:=0;
  yy:=0;
  for i:=1 to n do
    for j:=1 to n do
      begin
      //g[map[i,j],0]:=0;
      if map[i,j]<>0 then
        if (i+j)mod 2=0 then
          begin
            inc(xx);
            x[xx]:=map[i,j];
            if map[i-1,j]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i-1,j];
              end;
            if map[i,j-1]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i,j-1];
              end;
            if map[i+1,j]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i+1,j];
              end;
            if map[i,j+1]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i,j+1];
              end;
          end
        else
          begin
            inc(yy);
            y[yy]:=map[i,j];
            if map[i-1,j]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i-1,j];
              end;
            if map[i,j-1]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i,j-1];
              end;
            if map[i+1,j]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i+1,j];
              end;
            if map[i,j+1]<>0 then
              begin
                inc(g[map[i,j],0]);
                g[map[i,j],g[map[i,j],0]]:=map[i,j+1];
              end;
          end;
      end;
  for i:=1 to xx do
    begin
      fillchar(v,sizeof(v),false);
      if find(x[i]) then inc(s);
    end;
  writeln(s);
end.

