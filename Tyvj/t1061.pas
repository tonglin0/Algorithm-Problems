var
  c:Array[0..201,0..201]of longint;
  p:Array[0..1002]of longint;
  mn,i,j,x,y,k,m,n,s,t,ans:longint;
  f:Array[0..1,0..201,0..201]of longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
begin
  assign(input,'1061.in');reset(input);
  fillchar(f,sizeof(f),127);
  mn:=f[0,0,0];
  fillchar(c,sizeof(c),0);
  fillchar(p,sizeof(p),0);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do
      read(c[i,j]);
  for i:=1 to m do
    read(p[i]);
  f[1,1,2]:=c[3,p[1]];
  f[1,1,3]:=c[2,p[1]];
  f[1,2,3]:=c[1,p[1]];
  for i:=2 to m do
    for x:=1 to n do
      for y:=1 to n do
        begin
          if f[(i-1)and 1,x,y]<>mn then
            begin
              f[i and 1,x,y]:=min(f[i and 1,x,y],f[(i-1)and 1,x,y]+c[p[i-1],p[i]]);
              f[i and 1,p[i-1],x]:=min(f[i and 1,p[i-1],x],f[(i-1)and 1,x,y]+c[y,p[i]]);
              f[i and 1,y,p[i-1]]:=min(f[i and 1,y,p[i-1]],f[(i-1)and 1,x,y]+c[x,p[i]]);
              f[(i-1)and 1,x,y]:=mn;
            end;
        end;
  ans:=maxlongint;
  for i:=1 to n do
    for j:=1 to n do
      if f[m and 1,i,j]<ans then
        ans:=f[m and 1,i,j];
  writeln(Ans);
end.

