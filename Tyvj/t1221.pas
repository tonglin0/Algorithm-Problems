var
  map:array[1..1000,1..1000]of longint;
  v:array[1..1000]of boolean;
  d:array[1..1000]of longint;
  u,ans,va,w,n,m,k,i,j,en,l:longint;
  procedure outno;
    begin
      writeln('Sth wrong.');
    end;
  procedure prim;
    var
      j,i,min,minj:longint;
    begin
      for i:=1 to n do
        d[i]:=maxlongint;
      d[en]:=0;
      for i:=1 to n do
        begin
          min:=maxlongint;
          for j:=1 to n do
            if (not v[j])and(d[j]<min) then
              begin
                minj:=j;
                min:=d[j];
              end;
         { if min=maxlongint then
            begin
              outno;
              halt;
            end;}
          v[minj]:=true;
          for j:=1 to n do
            if (not v[j])and(map[minj,j]<>-1)and(min+map[minj,j]<d[j]) then
              d[j]:=min+map[minj,j];
        end;
    end;
begin
  fillchar(v,sizeof(v),false);
  readln(n,en,m);
  for i:=1 to n do
    for j:=1 to n do
      map[i,j]:=-1;
  for i:=1 to m do
    begin
      readln(u,va,w);
      if (map[u,va]=-1)or(map[u,va]>w) then
        begin
          map[u,va]:=w;
          map[va,u]:=w;
        end;
    end;
  prim;
  ans:=0;
  for i:=1 to n do
    if d[i]=maxlongint then
      begin
        outno;
        halt;
      end
    else
      inc(ans,d[i]);
  write(ans);
  writeln(' M(s) are needed.');
end.
