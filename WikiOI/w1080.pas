var
  t:array[0..400000]of longint;
  i,j,n,m,k,s,tt:longint;
/////////////////////////////////////////////////
  procedure build(p,l,r,i,delta:longint);
    var
      mid:longint;
    begin
      if l=r then
        inc(t[p],delta)
      else
        begin
          mid:=(l+r) shr 1;
          inc(t[p],delta);
          if i<=mid then build(p shl 1,l,mid,i,delta)
          else if i>=mid+1 then build(p shl 1+1,mid+1,r,i,delta);
        end;
    end;
////////////////////////////////////////////////////
  function count(p,l,r,min,max:longint):longint;
    var
      mid:longint;
    begin
      if (l=min)and(r=max) then exit(t[p]);
      mid:=(l+r) shr 1;
      if max<=mid then exit(count(p shl 1,l,mid,min,max))
      else if min>=mid+1 then exit(count(p shl 1+1,mid+1,r,min,max))
      else exit(count(p shl 1,l,mid,min,mid)+count(p shl 1+1,mid+1,r,mid+1,max));
    end;
begin
  fillchar(t,sizeof(t),0);
  readln(n);
  for i:=1 to n do
    begin
      read(k);
      build(1,1,n,i,k);
    end;
  readln(m);
  for i:=1 to m do
    begin
      readln(tt,k,s);
      if tt=1 then
        build(1,1,n,k,s)
      else
        writeln(count(1,1,n,k,s));
    end;
end.