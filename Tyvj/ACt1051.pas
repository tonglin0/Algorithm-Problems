type
  node=record
    l,r:longint;
  end;
const
  mn=301;
var
  f:array[0..mn,0..mn]of longint;
  v:array[0..mn,0..mn]of boolean;
  a,fa:array[0..mn]of longint;
  t:array[0..1000]of node;
  i,j,k,m,n,s,ans:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
  function find(x,y:longint):longint;
    var
      i,j,k:longint;
    begin
      if x=0 then exit(0);
      if v[x,y] then exit(f[x,y]);
      if y<0 then exit(0);
      if y=0 then
        begin
          v[x,y]:=true;
          exit(0);
        end;
      if t[x].r=0 then
        begin
          v[x,y]:=true;
          f[x,y]:=find(t[x].l,y-1)+a[x];
          exit(f[x,y]);
        end;
      if t[x].l=0 then
        begin
          f[x,y]:=max(find(t[x].r,y),a[x]+find(t[x].r,y-1));
          v[x,y]:=true;
          exit(f[x,y]);
        end;
      f[x,y]:=find(t[x].r,y);
      for k:=0 to y-1 do
        f[x,y]:=max(f[x,y],find(t[x].l,k)+find(t[x].r,y-k-1)+a[x]);
      v[x,y]:=true;
      exit(f[x,y]);
    end;
begin
  //assign(input,'1051.in');reset(input);
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),false);
  fillchar(a,sizeof(a),0);
  fillchar(fa,sizeof(fa),0);
  fillchar(t,sizeof(t),0);
  readln(n,m);
  for i:=1 to n do
    begin
      readln(s,k);
      if fa[s]=0 then
        t[s].l:=i
      else
        t[fa[s]].r:=i;
      fa[s]:=i;
      a[i]:=k;
    end;
  f[t[0].l,m]:=find(t[0].l,m);
  writeln(f[t[0].l,m]);
end.
