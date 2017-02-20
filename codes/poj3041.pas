var
  map:array[0..501,0..501]of boolean;
  vis:array[0..501]of boolean;
  p:array[0..501]of longint;
  i,j,k,m,n,s,t,ans:longint;
  function find(i:longint):boolean;
    var
      j:longint;
    begin
      for j:=1 to n do
        if (not vis[j])and(map[i,j]) then
          begin
            vis[j]:=true;
            if (p[j]=0)or(find(p[j])) then
              begin
                p[j]:=i;
                exit(true);
              end;
          end;
      exit(false);
    end;
begin
  fillchar(map,sizeof(map),false);
  fillchar(p,sizeof(p),0);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(s,t);
      map[s,t]:=true;
    end;
  ans:=0;
  for i:=1 to n do
    begin
      fillchar(vis,sizeof(vis),false);
      if find(i) then
        inc(ans);
    end;
  writeln(ans);
end.
