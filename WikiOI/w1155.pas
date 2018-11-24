type
  node2=record
    v,p:longint;
  end;
  zuyuan=record
    a:array[1..4]of node2;
    s:longint;
  end;
  node=record
    v,p,l,r:longint;
  end;
var
  vis:array[0..60]of boolean;
  zu:array[0..60]of zuyuan;
  f:array[0..32000]of longint;
  i,j,k,m,ii,n,s,l:longint;
  pp,vv,v,p:Array[0..400]of longint;
  t:array[0..60]of node;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  fillchar(vis,sizeof(vis),true);
  fillchar(t,sizeof(t),0);
  fillchar(f,sizeof(f),0);
  fillchar(pp,sizeof(pp),0);
  fillchar(vv,sizeof(vv),0);
  fillchar(p,sizeof(p),0);
  fillchar(v,sizeof(v),0);
  readln(m,n);
  m:=m div 10;
  for i:=1 to n do
    begin
      readln(vv[i],pp[i],k);
      vv[i]:=vv[i] div 10;
      if k<>0 then
        begin
          vis[i]:=false;
          if t[k].l=0 then
            t[k].l:=i
          else
            t[k].r:=i;
        end;
    end;
  k:=0;
  for i:=1 to n do
  if vis[i] then
    begin
      inc(k);
      inc(zu[k].s);
      s:=zu[k].s;
      zu[k].a[s].p:=pp[i]*vv[i];
      zu[k].a[s].v:=vv[i];
      if t[i].l<>0 then
        begin
          inc(zu[k].s);
          s:=zu[k].s;
          zu[k].a[s].p:=vv[i]*pp[i]+vv[t[i].l]*pp[t[i].l];
          zu[k].a[s].v:=vv[i]+vv[t[i].l];
        end;
      if t[i].r<>0 then
        begin
          inc(zu[k].s);
          s:=zu[k].s;
          zu[k].a[s].v:=vv[i]+vv[t[i].r];
          zu[k].a[s].p:=vv[i]*pp[i]+vv[t[i].r]*pp[t[i].r];
          inc(zu[k].s);
          s:=zu[k].s;
          zu[k].a[s].v:=vv[i]+vv[t[i].l]+vv[t[i].r];
          zu[k].a[s].p:=vv[i]*pp[i]+vv[t[i].l]*pp[t[i].l]+vv[t[i].r]*pp[t[i].r];
        end;
    end;
  n:=k;
  for k:=1 to n do
    for j:=m downto 0 do
      for ii:=1 to zu[k].s do
        if j>=zu[k].a[ii].v then
          f[j]:=max(f[j],f[j-zu[k].a[ii].v]+zu[k].a[ii].p);
  writeln(f[m]*10);
end.
