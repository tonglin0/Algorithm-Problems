const
  dx:array[1..4]of longint=(0,-1,0,1);
  dy:array[1..4]of longint=(-1,0,1,0);
var
  p:array[0..5100]of longint;
  map:array[0..5100,0..5100]of longint;
  v:array[0..5100]of boolean;
  gx:array[0..5100,0..4]of longint;
  i,j,n,m,k,nx,ny,ans,x,y:longint;
  function find(i:longint):boolean;
    var
      j:longint;
    begin
      for j:=1 to gx[i,0] do
        if not v[gx[i,j]] then
          begin
            v[gx[i,j]]:=true;
            if (p[gx[i,j]]=0)or(find(p[gx[i,j]])) then
              begin
                p[gx[i,j]]:=i;
                exit(true);
              end;
          end;
      exit(false);
    end;
begin
  fillchar(p,sizeof(p),0);
  fillchar(map,sizeof(map),0);
  fillchar(gx,sizeof(gx),0);
  read(n,m);
  read(k);
  for i:=1 to k do
    begin
      read(nx,ny);
      map[nx,ny]:=-1;
    end;
  nx:=0;
  ny:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (map[i,j]>=0)and((i+j) and 1=1) then
        begin
          inc(ny);
          map[i,j]:=ny;
        end;
  for i:=1 to n do
    for j:=1 to m do
      if ((i+j)and 1=0)and(map[i,j]>=0) then
        begin
          inc(nx);
          map[i,j]:=nx;
          for k:=1 to 4 do
            begin
              x:=i+dx[k];
              y:=j+dy[k];
              if (x>0)and(y>0)and(x<=n)and(y<=m)and(map[x,y]>=0) then
                begin
                  inc(gx[nx,0]);
                  gx[nx,gx[nx,0]]:=map[x,y];
                end;
            end;
        end;
  ans:=0;
  for i:=1 to nx do
    begin
      fillchar(v,sizeof(v),0);
      if find(i) then inc(ans);
    end;
  writeln(ans);
end.

