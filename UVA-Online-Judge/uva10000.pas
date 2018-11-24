var
  map:array[1..101,1..101]of longint;
  st,p,q,i,ii,j,k,n,m,max,t:longint;
begin
  //assign(input,'10000.in');reset(input);
  //assign(output,'10000.out');rewrite(output);
  readln(n);
  ii:=0;
  while n<>0 do
    begin
      inc(ii);
      fillchar(map,sizeof(map),0);
      readln(St);
      readln(p,q);
      while p<>0 do
        begin
          map[p,q]:=1;
          readln(p,q);
        end;
      for k:=1 to n do
        for i:=1 to n do
          for j:=1 to n do
            if (map[i,k]>0)and(map[k,j]>0)and(map[i,k]+map[k,j]>map[i,j]) then
              map[i,j]:=map[i,k]+map[k,j];
      max:=0;
      for i:=1 to n do
        if map[st,i]>max then
          begin
            max:=map[st,i];
            k:=i;
          end;
      write('Case ',ii,': The longest path from ',st,' has length ',max);
      writeln(', finishing at ',k,'.');
      writeln;
      readln(n);
    end;
  //close(input);    close(output);
end.



