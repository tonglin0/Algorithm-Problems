var
  ans:array[1..1000]of longint;
  map:array[1..1000,1..1000]of boolean;
  v:array[1..1000]of boolean;
  flag:boolean;
  n,m,k:longint;
  procedure init;
    var
      i,j,x,y:longint;
    begin
      flag:=false;
      fillchar(map,sizeof(map),true);
      for i:=1 to m do
        begin
          readln(x,y);
          map[x,y]:=false;
          map[y,x]:=false;
        end;
    end;
  procedure dfs(t:longint);
    var
      i,j:longint;
    begin
      if t=k+1 then
        begin
          flag:=true;
          writeln(m-k);
          exit;
        end;
      for i:=1 to n do
      if(not flag)and(not v[i]) then
        begin
          if t<>1 then
            begin
              if not map[i,ans[t-1]] then continue;
              if (t=k)and(not map[i,ans[1]]) then continue;
            end;
          ans[t]:=i;
          v[i]:=true;
          dfs(t+1);
          if flag then exit;
          v[i]:=false;
        end;
    end;
begin                   {
  assign(input,'poj2942.in');
  assign(output,'poj2942.out');
  reset(input);
  rewrite(output);     }
  readln(n,m);
  while n<>0 do
    begin
      init;
      if m mod 2=0 then k:=m-1 else k:=m;
      while (k>1)and(not flag) do
        begin
          fillchar(ans,sizeof(ans),0);
          fillchar(v,sizeof(v),false);
          dfs(1);
          dec(k,2);
        end;
      readln(n,m);
    end;
  {close(input);
  close(output);      }
end.