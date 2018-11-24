var
  a:array[0..101,0..101]of boolean;
  p:Array[0..101]of longint;
  vis:Array[0..101]of boolean;
  i,j,k,m,n,s,t,ans:longint;
  ch:char;
  function find(i:longint):boolean;
    var
      j:longint;
    begin
      for j:=1 to m do
        if (not vis[j])and(a[i,j]) then
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
  fillchar(a,sizeof(a),false);
  fillchar(p,sizeof(p),0);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch);
          if ch='1' then
            a[i,j]:=true;
        end;
      readln;
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