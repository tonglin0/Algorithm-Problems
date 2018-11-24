const
  d:array[1..3]of char=('I','B','F');
type
  node=record
    lc,rc,data:longint;
  end;
var
  s:ansistring;
  t:array[1..2050]of node;
  i,j,k,n,m,l:longint;
  procedure build(x:longint;s:ansistring);
    var
      l,i,j:longint;
      sa,sb:ansistring;
    begin
      l:=length(s);
      if l=1 then
        begin
          if s='1' then
            begin
              t[x].data:=1;
              exit;
            end;
          if s='0' then
            begin
              t[x].data:=2;
              exit;
            end;
        end;
      l:=l div 2;
      sa:=copy(s,1,l);
      sb:=copy(s,l+1,l);
      build(2*x,sa);
      build(2*x+1,sb);
      t[x].lc:=2*x;
      t[x].rc:=2*x+1;
      if t[2*x].data=t[2*x+1].data then
        t[x].data:=t[2*x].data
      else t[x].data:=3;
    end;
  procedure print(x:longint);
    var
      i,j:longint;
    begin
      if t[x].lc>0 then
        begin
          print(t[x].lc);
          print(t[x].rc);
        end;
      write(d[t[x].data]);
    end;
begin
  //assign(input,'fbi.in');reset(input);
  readln(n);
  fillchar(t,sizeof(t),0);
  readln(s);
  //writeln(length(s));
  build(1,s);
  print(1);
  //close(input);
end.
