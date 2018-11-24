var
  map:array[1..2000,1..2000]of longint;
  st:array[1..2000]of string;
  n,ans:longint;
  procedure init;
    var
      s:string;
      i,j,k:longint;
    begin
      fillchar(map,sizeof(map),0);
      fillchar(st,sizeof(st),0);
      for i:=1 to n do
        readln(st[i]);
    end;
  procedure search;
    var
      i,l,j,k:longint;
    begin
      for i:=1 to n-1 do
        begin
          for j:=i+1 to n do
            begin
              k:=0;
              for l:=1 to 7 do
                begin
                  if st[i][l]<>st[j][l] then
                    inc(k);
                end;
              map[i,j]:=k;
              map[j,i]:=k;
            end;
        end;
    end;
  procedure prim;
    var
      v:array[1..2000]of boolean;
      dis:array[1..2000]of longint;
      i,j,minj,min,k:longint;
    begin
      ans:=0;
      fillchar(v,sizeof(v),false);
      fillchar(dis,sizeof(dis),127);
      dis[1]:=0;
      for i:=1 to n do
        begin
          min:=maxlongint;
          for j:=1 to n do
            if (dis[j]<min)and(not v[j]) then
              begin
                min:=dis[j];
                minj:=j;
              end;
          inc(ans,min);
          v[minj]:=true;
          for j:=1 to n do
            begin
              if (not v[j])and(map[minj,j]<>0)and(map[minj,j]<dis[j]) then
                dis[j]:=map[minj,j];
            end;
        end;
    end;
begin
  {assign(input,'poj1789.in');
  assign(output,'poj1789.out');
  reset(input);
  rewrite(output);}
  readln(n);
  while n<>0 do
    begin
      init;
      search;
      prim;
      writeln('The highest possible quality is 1/',ans,'.');
      readln(n);
    end;           {
  close(input);
  close(output);    }
end.
