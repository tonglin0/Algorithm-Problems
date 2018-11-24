type
  node=record
    v,c:longint;
  end;
var
  c:array[0..100002]of node;
  a,b,i,j,k,n,m,t,s:longint;
  function low(i:longint):longint;
    begin
      exit(i and (-i));
    end;
  procedure add(i,d:longint);
    var
      j:longint;
    begin
      j:=i;
      while j<=n do
        begin
          inc(c[j].c,d);
          inc(j,low(j));
        end;
    end;
  function get(x:longint):longint;
    var
      j,s:longint;
    begin
      j:=x;
      s:=c[x].v+c[x].c;
      j:=j-low(j);
      while j>0 do
        begin
          inc(s,c[j].c);
          dec(j,low(j));
        end;
      exit(s);
    end;
begin
  fillchar(c,sizeof(c),0);
  read(n);
  for i:=1 to n do
    begin
      read(c[i].v);
    end;
  read(m);
  for i:=1 to m do
    begin
      read(k);
      if k=1 then
        begin
          read(a,b,t);
          add(a,t);
          add(b+1,-t);
        end
      else
        begin
          read(t);
          writeln(get(t));
        end;
    end;
end.
