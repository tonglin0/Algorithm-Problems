type
  node=record
    v,c:longint;
  end;
var
  t:array[0..400001]of node;
  i,j,k,n,m,x,y,s:longint;
  procedure clear(p,l,r:longint);
    begin
      inc(t[p].v,t[p].c);
      if l<>r then
        begin
          inc(t[p shl 1].c,t[p].c);
          inc(t[p shl 1+1].c,t[p].c);
        end;
      t[p].c:=0;
    end;
  procedure add(p,l,r,min,max,d:longint);
    var
      mid:longint;
    begin
      clear(p,l,r);
      if (l=min)and(r=max) then
        begin
          inc(t[p].v,d);
          if l<>r then
            begin
              inc(t[p shl 1].c,d);
              inc(t[p shl 1+1].c,d);
            end;
        end
      else
        begin
          mid:=(l+r) shr 1;
          if max<=mid then add(p shl 1,l,mid,min,max,d)
          else if min>mid then add(p shl 1+1,mid+1,r,min,max,d)
          else
            begin
              add(p shl 1,l,mid,min,mid,d);
              add(p shl 1+1,mid+1,r,mid+1,max,d);
            end;
        end;
    end;
  function get(p,l,r,min:longint):longint;
    var
      mid:longint;
    begin
      clear(p,l,r);
      if (l=min)and(r=min) then
        exit(t[p].v)
      else
        begin
          mid:=(l+r) shr 1;
          if min<=mid then
            exit(get(p shl 1,l,mid,min))
          else
            exit(get(p shl 1+1,mid+1,r,min));
        end;
    end;
begin
  fillchar(t,sizeof(t),0);
  read(n);
  for i:=1 to n do
    begin
      read(k);
      add(1,1,n,i,i,k);
    end;
  read(m);
  for i:=1 to m do
    begin
      read(k);
      if k=1 then
        begin
          read(x,y,s);
          add(1,1,n,x,y,s);
        end
      else
        begin
          read(k);
          writeln(get(1,1,n,k));
        end;
    end;
end.



