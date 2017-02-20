var
  map:array[1..26,1..26]of longint;
  d:array[1..26]of longint;
  v:Array[1..26]of boolean;
  i,j,k,n,ans,m,s,ss,t:longint;
  ch:char;
  procedure prim;
    var
      i,j,min,minj,k:longint;
    begin
      fillchar(v,sizeof(v),false);
      fillchar(d,sizeof(d),127);
      d[1]:=0;
      for i:=1 to n do
        begin
          min:=maxlongint;
          for j:=1 to n do
            if (d[j]<min)and(not v[j]) then
              begin
                min:=d[j];
                minj:=j;
              end;
          v[minj]:=true;
          inc(ans,min);
          for j:=1 to n do
            if (map[minj,j]<>0)and(map[minj,j]<d[j]) then
              d[j]:=map[minj,j];
        end;
    end;
begin
  //assign(input,'1251.in');reset(input);assign(output,'1251.out');rewrite(output);
  readln(n);
  while n<>0 do
    begin
      ans:=0;
      fillchar(map,sizeof(map),0);
      for i:=1 to n-1 do
        begin
          read(ch);
          k:=ord(ch)-64;
          read(ch);
          read(ch);
          s:=0;
          s:=s*10+ord(ch)-48;
          read(ch);
          while (ch>='0')and(ch<='9') do
            begin
              s:=s*10+ord(ch)-48;
              read(ch);
            end;
          for j:=1 to s do
            begin
              read(ch);
              t:=ord(ch)-64;
              read(ch);
              read(ch);
              ss:=0;
              while (ch>='0')and(ch<='9') do
                begin
                  ss:=ss*10+ord(ch)-48;
                  read(ch);
                end;
              map[k,t]:=ss;
              map[t,k]:=ss;
            end;
          readln;
        end;
      prim;
      writeln(ans);
      readln(n);
    end;
  //close(input);close(output);
end.


