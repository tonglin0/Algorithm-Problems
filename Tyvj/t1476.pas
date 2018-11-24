var
  c:array[0..101,0..101,0..101]of longint;
  i,j,k,m,n,s,t,xa,xb,xc,ya,yb,yc:longint;
  function low(x:longint):longint;
    begin
      low:=x and(-x);
    end;
  procedure add(xa,xb,xc,d:longint);
    var
      i,j,k,s:longint;
    begin
      while xa<=n do
        begin
          i:=xb;
          while i<=n do
            begin
              j:=xc;
              while j<=n do
                begin
                  inc(c[xa,i,j],d);
                  j:=j+low(j);
                end;
              i:=i+low(i);
            end;
          xa:=xa+low(xa);
        end;
    end;
  function get(xa,xb,xc:longint):longint;
    var
      i,j,s:longint;
    begin
      s:=0;
      while xa>0 do
        begin
          i:=xb;
          while i>0 do
            begin
              j:=xc;
              while j>0 do
                begin
                  s:=s+c[xa,i,j];
                  j:=j-low(j);
                end;
              i:=i-low(i);
            end;
          xa:=xa-low(xa);
        end;
      exit(s);
    end;
begin
  fillchar(c,sizeof(c),0);
  read(n);
  read(m);
  while m<>3 do
    begin
      if m=1 then
        begin
          read(xa,xb,xc,k);
          inc(xa);
          inc(xb);
          inc(xc);
          add(xa,xb,xc,k);
        end
      else
        begin
          read(xa,xb,xc,ya,yb,yc);
          inc(xa);
          inc(xb);
          inc(xc);
          inc(ya);
          inc(yb);
          inc(yc);
          writeln(get(ya,yb,yc)-get(ya,yb,xc-1)-get(xa-1,yb,yc)-get(ya,xb-1,yc)+get(ya,xb-1,xc-1)+get(xa-1,xb-1,yc)+get(xa-1,yb,xc-1)-get(xa-1,xb-1,xc-1));
        end;
      read(m);
    end;
end.

