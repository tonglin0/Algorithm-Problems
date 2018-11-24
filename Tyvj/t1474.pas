var
  c:Array[0..1025,0..1025]of longint;
  a,b,x,y,i,j,k,m,n,s,t:longint;
  function low(x:longint):longint;
    begin
      low:=x and(-x);
    end;
  procedure add(x,y,d:longint);
    var
      i,j:longint;
    begin
      while x<=n do
        begin
          j:=y;
          while j<=n do
            begin
              inc(c[x,j],d);
              j:=j+low(j);
            end;
          x:=x+low(x);
        end;
    end;
  function get(x,y:longint):longint;
    var
      i,j,s:longint;
    begin
      s:=0;
      while x>0 do
        begin
          j:=y;
          while j>0 do
            begin
              s:=s+c[x,j];
              j:=j-low(j);
            end;
          x:=x-low(x);
        end;
      exit(s);
    end;
begin
  fillchar(c,sizeof(c),0);
  readln(n);
  read(m);
  while m<>3 do
    begin
      if m=1 then
        begin
          read(a,b,x);
          inc(a);
          inc(b);
          add(a,b,x);
        end
      else
        begin
          read(a,b,x,y);
          inc(a);
          inc(b);
          inc(x);
          inc(y);
          writeln(get(x,y)-get(x,b-1)-get(a-1,y)+get(a-1,b-1));
        end;
      read(m);
    end;
end.

