type
  node=record
    l,r,s:longint;
  end;
var
  t:array[0..200000]of node;
  i,j,k,m,n,s,ans,l,r:longint;
  procedure build(p,a,b:longint);
    var
      mid:longint;
    begin
      if a=b then
        begin
          t[p].l:=a;
          t[p].r:=b;
        end
      else
        begin
          t[p].l:=a;
          t[p].r:=b;
          mid:=(a+b)shr 1;
          build(p shl 1,a,mid);
          build(p shl 1+1,mid+1,b);
        end;
    end;
  procedure add(p,a,b:longint);
    var
      mid:longint;
    begin
      if (t[p].l=a)and(t[p].r=b) then
        inc(t[p].s)
      else
        begin
          mid:=(t[p].l+t[p].r)shr 1;
          if b<=mid then
            add(p shl 1,a,b)
          else if a>mid then
            add(p shl 1+1,a,b)
          else
            begin
              add(p shl 1,a,mid);
              add(p shl 1+1,mid+1,b);
            end;
        end;
    end;
  procedure find(p,a:longint);
    var
      mid:longint;
    begin
      if (t[p].l=a)and(t[p].r=a) then
        inc(ans,t[p].s)
      else
        begin
          inc(ans,t[p].s);
          mid:=(t[p].l+t[p].r)shr 1;
          if a<=mid then
            find(p shl 1,a)
          else if a>mid then
            find(p shl 1+1,a);
        end;
    end;
begin
  assign(input,'2042.in');assign(output,'2042.out');reset(input);rewrite(output);
  fillchar(t,sizeof(t),0);
  readln(n);
  build(1,0,50000);
  for i:=1 to n do
    begin
      read(l,r);
      add(1,l,r);
    end;
  readln(m);
  for i:=1 to m do
    begin
      read(k);
      ans:=0;
      find(1,k);
      writeln(ans);
    end;
  close(input);close(output);
end.

