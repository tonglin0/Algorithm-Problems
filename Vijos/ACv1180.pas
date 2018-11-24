type
  node=record
    data,l,r:longint;
  end;
var
  l,r:array[0..302]of longint;
  a:array[0..302]of node;
  t:array[0..302]of longint;
  f:Array[0..302,0..302]of longint;
  v:Array[0..302,0..302]of boolean;
  i,j,k,n,m,s:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
  function find(x,m:longint):longint;
    var
      i,j,k:longint;
    begin
      if f[x,m]>0 then exit(f[x,m]);
      if m=0 then exit(0);
      if x=0 then exit(0);
      for i:=0 to m-1 do
        if f[x,m]<find(a[x].l,i)+find(a[x].r,m-i-1)+a[x].data then
          begin
            f[x,m]:=find(a[x].l,i)+find(a[x].r,m-i-1)+a[x].data;
            l[x]:=i;
            r[x]:=m-i-1;
          end;
      if find(a[x].r,m)>=f[x,m] then
        begin
          f[x,m]:=find(a[x].r,m);
          l[x]:=0;
          r[x]:=m;
        end
      else
        v[x,m]:=true;
      exit(f[x,m]);
    end;
  procedure print(x,m:longint);
    var
      i,j:longint;
    begin
      if (x=0) then exit;
      if l[x]+r[x]=m-1 then
        begin
          writeln(x);
          print(a[x].l,l[x]);
          print(a[x].r,r[x]);
        end
      else
        print(a[x].r,m);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(V),false);
  fillchar(t,sizeof(t),0);
  fillchar(l,sizeof(l),0);
  fillchar(r,sizeof(r),0);
  readln(n,m);
  for i:=1 to n do
    begin
      readln(k,s);
      a[i].data:=s;
      if t[k]=0 then
        a[k].l:=i
      else
        a[t[k]].r:=i;
      t[k]:=i;
    end;
  f[a[0].l,m]:=find(a[0].l,m);       {
  for i:=0 to n do
    writeln(a[i].l,' ',a[i].r,' ',a[i].data);
  halt;        }
  writeln(f[a[0].l,m]);
  //for i:=1 to n do
  //  if v[i] then writeln(i);
  //print(a[0].l,m);
end.

