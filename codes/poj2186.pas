type
  node=record
    ind,sum,outd:longint;
    //a:array[0..120]of longint;
  end;
var
  a:Array[0..100,0..20]of longint;
  dfn,low,st,fa:array[0..10000]of longint;
  ng:array[0..100]of node;
  v,ins:array[0..100]of boolean;
  i,j,k,ans,n,m,s,t,time,top:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
  procedure init;
    begin
      fillchar(a,sizeof(A),0);
      fillchar(dfn,sizeof(dfn),0);
      fillchar(low,sizeof(low),0);
      fillchar(st,sizeof(st),0);
      fillchar(ng,sizeof(ng),0);
      fillchar(fa,sizeof(fa),0);
      fillchar(v,sizeof(v),false);
      fillchar(ins,sizeof(ins),false);
      top:=0;
      time:=0;
      k:=0;
      read(n,m);
      for i:=1 to m do
        begin
          read(s,t);
          inc(a[s,0]);
          a[s,a[s,0]]:=t;
        end;
    end;
                                                        //init
  procedure pop(x:longint);
    var
      i:longint;
    begin
      inc(k);
      while st[top]<>x do
        begin
          i:=st[top];
          inc(ng[k].sum);
          fa[i]:=k;
          ins[i]:=false;
          dec(top);
        end;
      inc(ng[k].sum);
      fa[st[top]]:=k;
      ins[st[top]]:=false;
      dec(top);
    end;
                                                            //pop

  procedure dfs(x:longint);
    var
      i:longint;
    begin
      inc(time);
      low[x]:=time;
      dfn[x]:=time;
      inc(top);
      st[top]:=x;
      ins[x]:=true;
      for i:=1 to a[x,0] do
        if not v[a[x,i]] then
          begin
            v[a[x,i]]:=true;
            dfs(a[x,i]);
            low[x]:=min(low[x],low[a[x,i]]);
          end
        else if ins[a[x,i]] then
          low[x]:=min(low[x],dfn[a[x,i]]);
      if low[x]=dfn[x] then
        pop(x);
    end;
                                                       //dfs
  procedure rebuild;
    var
      i,j:longint;
    begin
      for i:=1 to n do
        for j:=1 to a[i,0] do
          if fa[i]<>fa[a[i,j]] then
            begin
              inc(ng[fa[i]].outd);
              inc(ng[fa[a[i,j]]].ind);
              //ng[fa[j]].a[ng[fa[j]].ind]]:=fa[i]
            end;
    end;
              {                                         //rebuild
  procedure floodfill(x:longint);
    var
      i,j:longint;
    begin      }

begin
  init;
  for i:=1 to n do
    if not v[i] then
      begin
        v[i]:=true;
        dfs(i);
      end;
  rebuild;
  t:=0;
  for i:=1 to k do
    if (ng[i].outd=0) then
      begin
        inc(t);
        ans:=ng[i].sum
                 {
        fillchar(v,sizeof(v),false);
        v[i]:=true;
        for j:=1 to ng[i].ind do
          if not v[ng[i].a[j]] then
            floodfill(ng[i].a[j]);
        for i:=1 to k do
          if not v[i] then
            continue; }
      end;
  if t=1 then
    begin
      writeln(ans);
      halt;
    end;
  writeln(0);
end.
