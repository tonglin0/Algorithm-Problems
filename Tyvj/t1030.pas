const
  dx:array[1..8]of longint=(-1,-1,-1,0,0,1,1,1);
  dy:array[1..8]of longint=(-1,0,1,-1,1,-1,0,1);
var
  map:array[1..100,1..100]of longint;
  v:array[1..100,1..100]of boolean;
  q:array[1..10000,1..3]of longint;
  r,f,i,j,m,n,k,l,mx,my,x,y:longint;
  ch:char;
begin
  fillchar(map,sizeof(map),0);
  fillchar(q,sizeof(q),0);
  fillchar(v,sizeof(v),false);
  readln(n,m,mx,my);
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(ch);
          if ch='.' then map[i,j]:=0 else map[i,j]:=1;
        end;
      readln;
    end;
  x:=m-my+1;
  my:=mx;
  mx:=x;
  r:=1;
  f:=0;
  q[1,1]:=mx;
  q[1,2]:=my;
  v[mx,my]:=true;
  q[1,3]:=0;
  while f<r do
    begin
      inc(f);
      for i:=1 to 8 do
        begin
          x:=q[f,1]+dx[i];
          y:=q[f,2]+dy[i];
          if (x>=1)and(y>=1)and(x<=m)and(y<=n)and(map[x,y]=0)and(not v[x,y])then
            begin
              inc(r);
              q[r,1]:=x;
              q[r,2]:=y;
              q[r,3]:=q[f,3]+1;
              v[x,y]:=true;
            end;
        end;
    end;
  writeln(q[r,3]);
end.

