//uses sysutils;
const
  mn=1000007;
type
  pt=^node;
  node=record
    data:longint;
    next:pt;
  end;
var
  h:array[0..1000007] of pt;
  time:double;
  i,j,k,n,m,t:longint;
  p,q:pt;
  a,b:array[0..100001]of longint;
begin
  //assign(input,'1265.in');assign(output,'m.out');
  //reset(input);rewrite(output);
  //time:=now;
  for i:=0 to mn do
    h[i]:=nil;
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  read(n);
  for i:=1 to n do
    begin
      read(a[i]);
      k:=a[i] mod mn;
      if h[k]=nil then
        begin
          new(p);
          p^.data:=a[i];
          p^.next:=nil;
          h[k]:=p;
        end
      else
        begin
          p:=h[k]^.next;
          q:=h[k];
          while p<>nil do
            begin
              q:=p;
              p:=p^.next;
            end;
          new(p);
          p^.data:=a[i];
          p^.next:=nil;
          q^.next:=p;
        end;
    end;
  read(m);
  t:=0;
  for i:=1 to m do
    begin
      read(b[i]);
      k:=b[i] mod mn;
      if h[k]=nil then continue;
      if (h[k]^.data=b[i]) then
        inc(t)
      else
        begin
          p:=h[k]^.next;
          while p<>nil do
            begin
              if p^.data=b[i] then
                begin
                  inc(t);
                  break;
                end
              else
                p:=p^.next;
            end;
        end;
    end;
  if t=0 then
    writeln('A and B are disjoint')
  else if (m=n)and(n=t) then
    writeln('A equals B')
  else if (m>n)and(t=n) then
    writeln('A is a proper subset of B')
  else if (n>m)and(t=m) then
    writeln('B is a proper subset of A')
  else writeln('I''m confused!');
  //writeln((now-time)*86400:0:10);
  //close(input);close(output);
end.
