const
  dx:array[1..8]of longint=(-1,-2,-2,-1,1,2,2,1);
  dy:array[1..8]of longint=(-2,-1,1,2,-2,-1,1,2);
var
  map:array[1..150,1..150]of longint;
  v:array[1..150,1..150]of boolean;
  q:array[1..22500,1..3]of longint;
  r,f,i,j,m,n,k,x,y,sx,sy,tx,ty:longint;
  ch:char;
begin
  //assign(input,'1074.in');reset(input);
  fillchar(map,sizeof(map),0);
  fillchar(q,sizeof(q),0);
  fillchar(v,sizeof(v),false);
  readln(m,n);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch);
          case ch of
            '.':map[i,j]:=0;
            '*':map[i,j]:=1;
            'K':
              begin
                map[i,j]:=1;
                sx:=i;
                sy:=j;
              end;
            'H':
              begin
                map[i,j]:=0;
                tx:=i;
                ty:=j;
              end;
            end;
        end;
      readln;
    end;
  v[sx,sy]:=true;
  q[1,1]:=sx;
  q[1,2]:=sy;
  q[1,3]:=0;
  r:=1;
  f:=0;
  while f<r do
    begin
      inc(f);
      for i:=1 to 8 do
        begin
          x:=q[f,1]+dx[i];
          y:=q[f,2]+dy[i];
          if (x>=1)and(y>=1)and(x<=n)and(y<=m)and(not v[x,y])and(map[x,y]=0)then
            begin
              inc(r);
              q[r,1]:=x;
              q[r,2]:=y;
              q[r,3]:=q[f,3]+1;
              v[x,y]:=true;
            end;
          if (x=tx)and(y=ty) then
            begin
              writeln(q[r,3]);
              halt;
            end;
        end;
    end;
  //close(input);
end.



