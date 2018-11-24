var
  map:array[0..101,0..101]of longint;
  dis:array[0..101]of longint;
  v:array[0..101]of boolean;
  i,j,n,m,k,s,t:longint;
  procedure dijk;
    var
      minj,min:longint;
    begin
      for i:=2 to n do
        dis[i]:=maxlongint;
      dis[1]:=0;
      s:=0;
      for i:=1 to n do
        begin
          min:=maxlongint;
          for j:=1 to n do
            if (not v[j])and(dis[j]<min) then
              begin
                minj:=j;
                min:=dis[j];
              end;
          v[minj]:=true;
          inc(s,min);
          for j:=1 to n do
            if (map[minj,j]>0)and(map[minj,j]<dis[j]) then
              dis[j]:=map[minj,j];
        end;
    end;
begin
  fillchar(map,sizeof(map),0);
  fillchar(v,sizeof(v),0);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(map[i,j]);
  dijk;
  writeln(s);
end.


