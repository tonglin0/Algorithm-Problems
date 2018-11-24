var
  a:array[0..101,0..101]of longint;
  map:array[0..101,0..101]of double;
  q:array[1..101,1..2]of longint;
  v:array[0..101]of boolean;
  dis:array[0..101]of double;
  i,j,n,m,k,s,t,st,en:longint;
  procedure dijk;
    var
      min:double;
      minj:longint;
    begin
      for i:=1 to n do
        dis[i]:=maxlongint;
      dis[st]:=0;
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
          if minj=en then exit;
          for j:=1 to a[minj,0] do
            if dis[minj]+map[minj,a[minj,j]]<dis[a[minj,j]] then
              dis[a[minj,j]]:=dis[minj]+map[minj,a[minj,j]];
        end;
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(q,sizeof(q),0);
  fillchar(map,sizeof(map),0);
  fillchar(v,sizeof(v),false);
  read(n);
  for i:=1 to n do
    read(q[i,1],q[i,2]);
  read(m);
  for i:=1 to n do
    for j:=1 to n do
      map[i,j]:=sqrt(sqr(abs(q[i,1]-q[j,1]))+sqr(abs(q[i,2]-q[j,2])));
  for i:=1 to m do
    begin
      read(k,t);
      inc(a[k,0]);
      a[k,a[k,0]]:=t;
      inc(a[t,0]);
      a[t,a[t,0]]:=k;
    end;
  read(st,en);
  dijk;
  writeln(dis[en]:0:2);
end.



