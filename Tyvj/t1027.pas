const
  dx:array[1..4]of longint=(0,-1,0,1);
  dy:array[1..4]of longint=(-1,0,1,0);
var
  map:array[1..100,1..100]of longint;
  v:array[1..100,1..100]of boolean;
  x,y,mx,my,i,kx,ky,j,k,n,m,ans:longint;
begin
  fillchar(map,sizeof(map),0);
  fillchar(v,sizeof(v),false);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        read(map[i,j]);
      readln;
    end;
  x:=1;
  y:=1;
  ans:=map[1,1
  ];
  v[1,1]:=true;
  while not((x=n)and(y=m)) do
    begin
      k:=-1;
      for i:=1 to 4 do
        begin
          mx:=x+dx[i];
          my:=y+dy[i];
          if (mx>=1)and(my>=1)and(mx<=n)and(my<=m)and(not v[mx,my])and(map[mx,my]>k) then
            begin
              kx:=mx;
              ky:=my;
              k:=map[mx,my];
            end;
        end;
      inc(ans,k);
      x:=kx;
      y:=ky;
      v[x,y]:=true;
    end;
  writeln(ans);
end.


