const
  mn=100001;
var
  b:array[1..mn]of boolean;
  a:array[1..mn,0..100]of longint;
  c,l,r:array[0..mn]of longint;
  p,q,i,j,k,m,n,t,s:longint;
  v:array[1..mn]of boolean;
  ch:char;
  procedure dfs(k:longint);
    var
      i:longint;
    begin
      v[k]:=true;
      inc(t);
      l[k]:=t;
      for i:=1 to a[k,0] do
        if not v[a[k,i]] then
          dfs(a[k,i]);
      r[k]:=t;
    end;
  function lowbit(i:longint):longint;
    begin
      exit(i and (-i));
    end;
  procedure change(k,delta:longint);
    var
      i,j:longint;
    begin
      i:=k;
      while i<=n do
        begin
          c[i]:=c[i]+delta;
          //b[i]:=not b[i];
          i:=i+lowbit(i);
        end;
    end;
  function get(k:longint):longint;
    var
      s,i:longint;
    begin
      i:=k;
      s:=0;
      while i>0 do
        begin
          s:=s+c[i];
          i:=i-lowbit(i);
        end;
      exit(s);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(v,sizeof(v),false);
  fillchar(c,sizeof(c),0);
  fillchar(l,sizeof(l),0);
  fillchar(b,sizeof(b),true);
  fillchar(r,sizeof(r),0);
  readln(n);
  for i:=1 to n-1 do
    begin
      readln(p,q);
      inc(a[p,0]);
      a[p,a[p,0]]:=q;
      inc(a[q,0]);
      a[q,a[q,0]]:=p;
    end;
  t:=0;
  dfs(1);
  for i:=1 to n do
    change(l[i],1);
  readln(m);
  for i:=1 to m do
    begin
      readln(ch,k);
      if ch='C' then
        begin
          if b[k] then
            change(l[k],-1)
          else change(l[k],1);
          b[k]:=not b[k];
        end;
      if ch='Q' then
        writeln(get(r[k])-get(l[k]-1));
    end;
end.
