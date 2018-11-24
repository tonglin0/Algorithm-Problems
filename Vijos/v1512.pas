var
  c:array[0..1025,0..1025]of longint;
  i,j,k,m,n,s,t,x,y:longint;
  function lowbit(k:longint):longint;
    begin
      lowbit:=k and (k xor (k-1));
    end;
  procedure add(x,y,k:longint);
    var
      z:longint;
    begin
      while x<=n do
        begin
          z:=y;
          while z<=n do
            begin
              inc(c[x,z],k);
              z:=z+lowbit(z);
            end;
          x:=x+lowbit(x);
        end;
    end;
  function get(x,y:longint):longint;
    var
      s,z:longint;
    begin
      s:=0;
      while x>0 do
        begin
          z:=y;
          while z>0 do
            begin
              s:=s+c[x,z];
              z:=z-lowbit(z);
            end;
          x:=x-lowbit(x);
        end;
      exit(s);
    end;
begin
  readln(n);
  fillchar(c,sizeof(c),0);
  read(m);
  while m<>3 do
    begin
      if m=1 then
        begin
          read(x,y,k);
          inc(x);
          inc(y);
          add(x,y,k);
        end;
      if m=2 then
        begin
          read(x,y,i,j);
          inc(x);
          inc(y);
          inc(i);
          inc(j);
          s:=get(i,j)-get(i,y-1)-get(x-1,j)+get(x-1,y-1);
          writeln(s);
        end;
      read(m);
    end;
end.




