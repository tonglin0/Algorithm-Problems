type
  node=record
    a,b:longint;
    w:double;
  end;
var
  dis:array[0..101]of double;
  num,st,en:array[0..101]of longint;
  q:Array[0..101]of longint;
  ins:Array[0..101]of boolean;
  aa:array[0..101,1..2]of longint;
  map:array[0..6000]of node;
  x,y,i,j,k,f,r,n,m,t,s:longint;
  procedure qsort(h,t:longint);
    var
      i,j,tt:longint;
      x:node;
    begin
      i:=h;
      j:=t;
      tt:=random(t-h)+h;
      x:=map[tt];
      map[tt]:=map[h];
      map[h]:=x;
      //x:=map[h];
      while i<j do
        begin
          while (i<j)and(map[j].a>=x.a) do
            dec(j);
          map[i]:=map[j];
          while (i<j)And(map[i].a<=x.a) do
            inc(i);
          map[j]:=map[i];
        end;
      map[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
  function relax(u,v:longint;w:double):boolean;
    begin
      if dis[u]+w<dis[v] then
        begin
          dis[v]:=dis[u]+w;
          exit(true);
        end
      else exit(false);
    end;
begin
  fillchar(num,sizeof(num),0);
  fillchar(st,sizeof(st),0);
  fillchar(en,sizeof(en),0);
  fillchar(q,sizeof(q),0);
  fillchar(ins,sizeof(ins),false);
  fillchar(map,sizeof(map),0);
  read(n);
  for i:=1 to n do
    read(aa[i,1],aa[i,2]);
  read(m);
  t:=0;
  for i:=1 to m do
    begin
      read(x,y);
      inc(t);
      map[t].a:=x;
      map[t].b:=y;
      map[t].w:=sqrt(sqr(abs(aa[x,1]-aa[y,1]))+sqr(aa[x,2]-aa[y,2]));
      inc(t);
      map[t].a:=y;
      map[t].b:=x;
      map[t].w:=map[t-1].w;
      inc(num[y]);
      inc(num[x]);
    end;
  read(x,y);
  randomize;
  qsort(1,t);       {
  for i:=1 to t do
    writeln(map[i].a,' ',map[i].b);
  halt;}
  st[1]:=1;
  en[1]:=st[1]+num[1]-1;
  for i:=2 to n do
    begin
      st[i]:=en[i-1]+1;
      en[i]:=st[i]+num[i]-1;
    end;
  f:=0;
  r:=1;
  for i:=1 to n do
    dis[i]:=maxlongint;
  dis[x]:=0;
  q[1]:=x;
  while f<>r do
    begin
      f:=f mod n+1;
      k:=q[f];
      ins[k]:=false;
      for i:=st[k] to en[k] do
        if (relax(k,map[i].b,map[i].w))and(not ins[map[i].b]) then
          begin
            r:=r mod n+1;
            ins[map[i].b]:=true;
            q[r]:=map[i].b;
          end;
    end;
  writeln(dis[y]:0:2);
end.