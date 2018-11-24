type
  node=record
    sum,c:int64;
  end;
var
  t:array[0..800002]of node;
  i,j,k,n,m,s,a,b:longint;
  procedure clear(p,l,r:int64);
    begin
      inc(t[p].sum,t[p].c*(r-l));
      if r-l>1 then
        begin
          inc(t[p shl 1].c,t[p].c);
          inc(t[p shl 1+1].c,t[p].c);
        end;
      t[p].c:=0;
    end;
  procedure add(p,l,r,min,max,d:int64);
    var
      mid:longint;
    begin
      clear(p,l,r);
      if (l=min)and(r=max) then
        begin
          inc(t[p].sum,d*(r-l));
          if r-l>1 then
            begin
              inc(t[p shl 1].c,d);
              inc(t[p shl 1+1].c,d);
            end;
        end
      else
        begin
          mid:=(l+r)shr 1;
          if max<=mid then
            add(p shl 1,l,mid,min,max,d)
          else if min>=mid then
            add(p shl 1+1,mid,r,min,max,d)
          else
            begin
              add(p shl 1,l,mid,min,mid,d);
              add(p shl 1+1,mid,r,mid,max,d);
            end;
          clear(p shl 1,l,mid);
          clear(p shl 1+1,mid,r);
          t[p].sum:=t[p shl 1].sum+t[p shl 1+1].sum;
        end;
    end;
  function get(p,l,r,min,max:longint):int64;
    var
      ans:int64;
      mid:longint;
    begin
      clear(p,l,r);
      if (l=min)and(r=max) then
        exit(t[p].sum)
      else
        begin
          mid:=(l+r) shr 1;
          ans:=0;
          if max<=mid then inc(ans,get(p shl 1,l,mid,min,max))
          else if min>=mid then inc(ans,get(p shl 1+1,mid,r,min,max))
          else inc(ans,get(p shl 1,l,mid,min,mid)+get(p shl 1+1,mid,r,mid,max));
          clear(p shl 1,l,mid);
          clear(p shl 1+1,mid,r);
          t[p].sum:=t[p shl 1].sum+t[p shl 1+1].sum;
          exit(ans);
        end;
    end;
begin
  fillchar(t,sizeof(t),0);
  read(n);
  for i:=1 to n do
    begin
      read(k);
      add(1,1,n+1,i,i+1,k);
    end;
  read(m);
  for i:=1 to m do
    begin
      read(k);
      if k=1 then
        begin
          read(a,b,s);
          add(1,1,n+1,a,b+1,s);
        end
      else
        begin
          read(a,b);
          writeln(get(1,1,n+1,a,b+1));
        end;
    end;
end.


