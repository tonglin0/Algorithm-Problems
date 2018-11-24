var
  map:array[1..20,1..20]of longint;
  v:array[1..20]of boolean;
  p:array[1..100,1..2]of longint;
  k,i,j,n,m,l:longint;
  function dij(a,b:longint):longint;
    var
      i,j,min,minj:longint;
      dis:array[1..20]of longint;
    begin
      for i:=1 to 20 do
        dis[i]:=maxint;
      fillchar(v,sizeof(v),false);
      dis[a]:=0;
      for i:=1 to 19 do
        begin
          min:=maxint;
          for j:=1 to 20 do
            if (not v[j])and(dis[j]<min) then
              begin
                min:=dis[j];
                minj:=j;
              end;
          v[minj]:=true;
          for j:=1 to 20 do
            if (map[minj,j]=1)and(dis[minj]+map[minj,j]<dis[j]) then
              dis[j]:=dis[minj]+map[minj,j];
        end;
      dij:=dis[b];
    end;
begin
  //assign(input,'uva.in');
  //assign(output,'uva.out');
  //reset(input);
  //rewrite(output);
  k:=0;
  while not eof do
    begin
      inc(k);
      for i:=1 to 20 do
        for j:=1 to 20 do
          map[i,j]:=maxint;
      fillchar(p,sizeof(p),0);
      for i:=1 to 19 do
        begin
          read(n);
          for j:=1 to n do
            begin
              read(m);
              map[i,m]:=1;
              map[m,i]:=1;
            end;
          readln;
        end;
      readln(n);
      for i:=1 to n do
        readln(p[i,1],p[i,2]);
      writeln('Test Set #',k);
      for i:=1 to n do
        begin
          write(p[i,1]:2,' to ',p[i,2]:2,':');
          l:=dij(p[i,1],p[i,2]);
          writeln(l:2);
        end;
      writeln;
    end;
  //close(input);
  //close(output);
end.
