type
  node=record
    a,b,min:longint;
  end;
var
  t:array[0..800001]of node;
  i,j,k,m,n,s,a,b,l,r:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
  procedure build(p,l,r:longint);
    var
      mid:longint;
    begin
      t[p].a:=l;
      t[p].b:=r;
      if l<>r then
        begin
          mid:=(l+r) shr 1;
          build(p shl 1,l,mid);
          build(p shl 1+1,mid+1,r);
        end;
    end;
  procedure change(p,k,d:longint);
    var
      mid:longint;
    begin
      if not((t[p].a=k)and(t[p].b=k)) then
        begin
          mid:=(t[p].a+t[p].b) shr 1;
          if k<=mid then
            change(p shl 1,k,d)
          else
            change(p shl 1+1,k,d);
          t[p].min:=min(t[p shl 1].min,t[p shl 1+1].min);
        end
      else
        t[p].min:=d;
    end;
  function find(p:longint):longint;
    var
      mid:longint;
    begin
      if (t[p].a>=a)and(t[p].b<=b) then
        exit(t[p].min);
      mid:=(t[p].a+t[p].b) shr 1;
      if (b<=mid) then
        exit(find(p shl 1))
      else if a>mid then
        exit(find(p shl 1+1))
      else
        exit(min(find(p shl 1),find(p shl 1+1)));
    end;
begin
  //assign(input,'1039.in');reset(input);assign(output,'1039.out');rewrite(output);
  fillchar(t,sizeof(t),0);
  readln(n,m);
  build(1,1,n);
  for i:=1 to n do
    begin
      read(k);
      change(1,i,k);
    end;        {
  for i:=1 to 40 do
    writeln('p=',i,' p.l=',t[i].a,'  p.r=',t[i].b,'  p.min=',t[i].min); }
  for i:=1 to m do
    begin
      read(k,a,b);
      if k=2 then
        change(1,a,b)
      else
        writeln(find(1));
    end;
  //close(input);close(output);
end.
