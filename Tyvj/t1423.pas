var
  map:array[1..100,1..100]of longint;
  ans,i,j,k,m,n,a,b,x,y:longint;
begin
  fillchar(map,sizeof(map),0);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(a,b);
      map[a,b]:=1;
      map[b,a]:=1;
    end;
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if (map[j,i]>0)and(map[i,k]>0)and((map[j,i]+map[i,k]<map[j,k])or(map[j,k]=0))then
          begin
            map[j,k]:=map[j,i]+map[i,k];
            map[k,j]:=map[j,k];
          end;
  ans:=-1;
  for i:=1 to n do
    for j:=1 to n do
      if map[i,j]>ans then ans:=map[i,j];
  writeln(ans);
end.

