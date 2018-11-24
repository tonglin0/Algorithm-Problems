type
  pt=^node;
  node=record
    data:longint;
    next:pt;
  end;
var
  f:array[0..10002]of longint;
  a:array[1..10001]of pt;
  i,j,m,n,k,t:longint;
  p,q:pt;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  //assign(input,'1034.in');assign(output,'a.out');reset(input);rewrite(output);
  fillchar(f,sizeof(f),0);
  for i:=1 to 10001 do
    a[i]:=nil;
  readln(n,m);
  for i:=1 to m do
    begin
      readln(k,t);
      inc(t,k);
      new(p);
      p:=a[k];
      if p=nil then
        begin
          new(p);
          p^.data:=t;
          a[k]:=p;
          continue;
        end;
      while p<>nil do
        begin
          q:=p;
          p:=p^.next;
        end;
      new(p);
      p^.data:=t;
      p^.next:=nil;
      q^.next:=p;
    end;
  f[n+1]:=0;
  for i:=n downto 1 do
    begin
      if a[i]=nil then
        begin
          f[i]:=f[i+1]+1;
          continue;
        end;
      new(p);
      p:=a[i];
      while p<>nil do
        begin
          f[i]:=max(f[i],f[p^.data]);
          p:=p^.next;
        end;
    end;
  writeln(f[1]);
  //close(input);close(output);
end.

