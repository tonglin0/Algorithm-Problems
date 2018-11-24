var
  c:array[0..100100]of longint;
  i,j,k,n,m,s,t:longint;
///////////////////////////////////////////
  function low(i:longint):longint;
    begin
      exit(i and (-i));
    end;
///////////////////////////////////////////
  procedure add(i,d:longint);
    var
      j:longint;
    begin
      j:=i;
      while j<=n do
        begin
          inc(c[j],d);
          inc(j,low(j));
        end;
    end;
////////////////////////////////////////////
  function sum(i:longint):longint;
    var
      s,j:longint;
    begin
      j:=i;
      s:=0;
      while j>0 do
        begin
          s:=s+c[j];
          dec(j,low(j));
        end;
      exit(s);
    end;
//////////////////////////////////////////////
begin
  fillchar(c,sizeof(c),0);
  readln(n);
  for i:=1 to n do
    begin
      read(k);
      add(i,k);
    end;
  readln(m);
  for i:=1 to m do
    begin
      readln(t,k,s);
      if t=1 then
        add(k,s)
      else
        writeln(sum(s)-sum(k-1));
    end;
end.


