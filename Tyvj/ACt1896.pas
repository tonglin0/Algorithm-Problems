const
  dx:array[1..8]of longint=(-2,-2,-1,1,2,2,1,-1);
  dy:array[1..8]of longint=(-1,1,2,2,1,-1,-2,-2);
var
  f:array[0..21,0..21]of longint;
  a:array[0..21,0..21]of boolean;
  mx,my,i,j,n,m,x,y,k:longint;
begin
  fillchar(a,sizeof(a),true);
  fillchar(f,sizeof(f),0);
  readln(n,m,x,y);
  a[x,y]:=false;
  for i:=1 to 8 do
    begin
      mx:=x+dx[i];
      my:=y+dy[i];
      a[mx,my]:=false;
    end;
  for i:=1 to n do
    if a[i,0] then
      f[i,0]:=1
    else
      break;
  for i:=1 to m do
    if a[0,i] then
      f[0,i]:=1
    else
      break;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j] then
        f[i,j]:=f[i-1,j]+f[i,j-1];
  writeln(f[n,m]);
end.



