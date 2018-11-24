const
  dx:array[1..4]of longint=(0,-1,0,1);
  dy:array[1..4]of longint=(-1,0,1,0);
var
  map:array[1..50,1..80]of longint;
  v:array[1..50,1..80]of boolean;
  q:array[1..4000,1..2]of longint;
  n,m,i,j,k,l,ans:longint;
  ch:char;
  procedure work(x,y:longint);
    var
      r,f,i,j,mx,my:longint;
    begin
      fillchar(q,sizeof(q),0);
      f:=0;
      r:=1;
      q[1,1]:=x;
      q[1,2]:=y;
      while f<r do
        begin
          inc(f);
          for i:=1 to 4 do
            begin
              mx:=q[f,1]+dx[i];
              my:=q[f,2]+dy[i];
              if (mx>0)and(my>0)and(mx<=n)and(my<=m)and(not v[mx,my])and(map[mx,my]<>0) then
                begin
                  inc(r);
                  q[r,1]:=mx;
                  q[r,2]:=my;
                  v[mx,my]:=true;
                end;
            end;
        end;
    end;
begin
  fillchar(map,sizeof(map),0);
  fillchar(v,sizeof(v),false);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch);
          val(ch,map[i,j]);
        end;
      readln;
    end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (not v[i,j])and(map[i,j]<>0) then
        begin
          inc(ans);
          v[i,j]:=true;
          work(i,j);
        end;
  writeln(ans);
end.


