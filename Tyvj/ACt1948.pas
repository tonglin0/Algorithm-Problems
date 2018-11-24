type
  node=record
    x,y,d:longint;
  end;
const
  dx:array[1..4]of longint=(0,-1,0,1);
  dy:array[1..4]of longint=(-1,0,1,0);
var
  a,dis:array[0..201,0..201]of longint;
  v:Array[0..201,0..201]of boolean;
  q:Array[0..400000]of node;
  i,j,k,m,n,s,f,r,mx,my,x,y,t:longint;
  ch:char;
begin
  fillchar(a,sizeof(a),0);
  fillchar(dis,sizeof(dis),0);
  fillchar(v,sizeof(v),false);
  fillchar(q,sizeof(q),0);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch);
          a[i,j]:=ord(ch)-48;
        end;
      readln;
    end;
  f:=0;
  r:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j]=1 then
        begin
          inc(r);
          q[r].x:=i;
          q[r].y:=j;
          v[i,j]:=true;
          q[r].d:=0;
        end;
  while f<r do
    begin
      inc(f);
      x:=q[f].x;
      y:=q[f].y;
      for i:=1 to 4 do
        begin
          mx:=x+dx[i];
          my:=y+dy[i];
          if (mx>0)and(my>0)and(mx<=n)and(my<=m)and(not v[mx,my]) then
            begin
              inc(r);
              q[r].x:=mx;
              q[r].y:=my;
              q[r].d:=q[f].d+1;
              dis[mx,my]:=q[r].d;
              v[mx,my]:=true;
            end;
        end;
    end;
  for i:=1 to n do
    begin
      for j:=1 to m-1 do
        write(dis[i,j],' ');
      writeln(dis[i,m]);
    end;
end.

