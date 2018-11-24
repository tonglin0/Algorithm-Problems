type
  node=record
    nu,k,r:longint;
  end;
var
  y:array[1..1000]of longint;
  x:array[1..1000]of node;
  v:array[1..1000]of boolean;
  g:array[1..1000,0..201]of longint;
  f:array[1..1000]of longint;
  n,m,i,xx,yy,j,k,ans,s,a,t,b:longint;
  p:array[1..1000]of boolean;
  function pri(m:longint):boolean;
    var
      i,j:longint;
    begin
      if m=1 then exit(false);
      j:=trunc(sqrt(m));
      for i:=2 to j do
        if m mod i=0 then
          exit(false);
      exit(true);
    end;
  function find(u:longint):boolean;
    var
      i,j:longint;
    begin
      for i:=1 to g[x[u].nu,0] do
        if not v[g[x[u].nu,i]] then
          begin
            v[g[x[u].nu,i]]:=true;
            if (f[g[x[u].nu,i]]=0)or(find(f[g[x[u].nu,i]])) then
              begin
                f[g[x[u].nu,i]]:=u;
                exit(true);
              end;
          end;
      exit(false);
    end;
  procedure qsort(h,t:longint);
    var
      z:node;
      tt,i,j:longint;
    begin
      i:=h;
      j:=t;
      randomize;
      tt:=random(t-h);
      inc(tt,h);
      z:=x[tt];
      x[tt]:=x[h];
      x[h]:=z;
      while i<j do
        begin
          while (i<j)and(x[j].k<=z.k) do
            dec(j);
          x[i]:=x[j];
          while (i<j)and(x[i].k>=z.k) do
            inc(i);
          x[j]:=x[i];
        end;
      x[i]:=z;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
begin
  fillchar(x,sizeof(x),0);
  fillchar(p,sizeof(p),false);
  fillchar(y,sizeof(y),0);
  fillchar(g,sizeof(g),0);
  readln(n);
  xx:=0;
  yy:=0;
  for i:=1 to n do
    begin
      read(s);
      if not pri(s) then
        begin
          inc(xx);
          x[xx].nu:=i;
        end
      else
        begin
          inc(yy);
          y[yy]:=i;
          p[i]:=true;
        end;
    end;
  k:=0;
  for i:=1 to n do
    begin
      readln(a,b);
      if p[i] then continue;
      inc(k);
      x[k].k:=a;
      x[k].r:=b;
      a:=i-b;
      if a<1 then a:=1;
      b:=i+b;
      if b>n then b:=n;
      for j:=a to b do
        if p[j] then
          begin
            inc(g[i,0]);
            g[i,g[i,0]]:=j;
          end;
    end;
  qsort(1,xx);
  s:=0;
  ans:=0;
  for i:=1 to xx do
    begin
      fillchar(v,sizeof(v),false);
      if find(i) then
        begin
          inc(s);
          inc(ans,x[i].k);
        end;
    end;
  writeln(s);
  writeln(ans);
end.

