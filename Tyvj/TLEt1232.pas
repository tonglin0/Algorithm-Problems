type
  node=record
    x,y,d:longint;
  end;
const
  mn=250000;
  dx:array[1..4]of longint=(0,-1,0,1);
  dy:array[1..4]of longint=(-1,0,1,0);
var
  fa:Array[0..501,0..501]of longint;
  a:Array[0..501,0..501]of longint;
  q:Array[0..mn]of node;
  ch:char;
  f,r,i,j,k,x1,y1,x2,y2,m,n,s,t,ans,mx,my:longint;
begin
  assign(output,'b.out');rewrite(output);
  assign(input,'1232.in');reset(input);
  fillchar(a,sizeof(a),0);
  fillchar(q,sizeof(q),0);
  fillchar(fa,sizeof(fa),127);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch);
          if ch='.' then
            a[i,j]:=0
          else
            a[i,j]:=1;
        end;
      readln;
    end;
  readln(x1,y1,x2,y2);
  fa[x1,y1]:=0;
  r:=1;
  f:=0;
  q[1].x:=x1;
  q[1].y:=y1;
  q[1].d:=0;
  ans:=maxlongint;
  while f<>r do
    begin
      f:=f mod mn+1;
      if (q[f].x=x2)and(q[f].y=y2) then
        begin
          if q[f].d<ans then
            ans:=q[f].d;
          continue;
        end;
      for i:=1 to 4 do
        begin
          mx:=q[f].x+dx[i];
          my:=q[f].y+dy[i];
          k:=q[f].d;
          if (mx>0)and(my>0)and(mx<=n)and(my<=m) then
            begin
              if a[mx,my]=a[q[f].x,q[f].y] then
                k:=k+1
              else
                k:=k+2;
              if k<fa[mx,my] then
                begin
                  fa[mx,my]:=k;
                  r:=r mod mn+1;
                  q[r].x:=mx;
                  q[r].y:=my;
                  q[r].d:=k;
                end;
            end;
        end;
    end;
  if fa[x2,y2]<ans then
    ans:=fa[x2,y2];
  writeln(ans);
  close(input);close(output);
end.
