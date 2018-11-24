var
  map:array[1..2500,1..2500]of longint;
  v:array[1..2500]of boolean;
  d:array[1..2500]of longint;
  i,j,k,st,en,m,n,u,va,w:longint;
  procedure prim;
    var
      i,j,minj,min:longint;
    begin
      for i:=1 to n do
        d[i]:=maxlongint;
      d[st]:=0;
      for i:=1 to n do
        begin
          min:=maxlongint;
          for j:=1 to n do
            if (not v[j])and(d[j]<min) then
              begin
                min:=d[j];
                minj:=j;
              end;
          v[minj]:=true;
          if minj=en then
            begin
              writeln(min);
              halt;
            end;
          for j:=1 to n do
            if (map[minj,j]>0)and(map[minj,j]+min<d[j]) then
              d[j]:=map[minj,j]+min;
        end;
    end;
begin
  fillchar(map,sizeof(map),0);
  fillchar(v,sizeof(v),false);
  readln(n,m,st,en);
  for i:=1 to m do
    begin
      readln(u,va,w);
      map[u,va]:=w;
      map[va,u]:=w;
    end;
  prim;
  writeln(d[en]);
end.



