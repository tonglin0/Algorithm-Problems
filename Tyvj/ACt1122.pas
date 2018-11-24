type
  pt=^pk;
  pk=record
    data:longint;
    next:pt;
  end;
  node=record
    min,max:longint;
    head:pt;
  end;
var
  nw:array[0..100001]of node;
  a,fan:array[0..100001]of pt;
  st,dfn,low,fa,zui,zuians,cost:array[0..100001]of longint;
  v,ins:array[0..100001]of boolean;
  i,j,k,m,n,s,t,aa,top,ans,time:longint;
  p,q,pp:pt;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
  procedure build(s,t:longint);
    var
      i,j,k:longint;
      p,q:pt;
    begin
      if a[s]=nil then
        begin
          new(a[s]);
          a[s]^.next:=nil;
          a[s]^.data:=t;
        end
      else
        begin
          p:=a[s];
          while p<>nil do
            begin
              q:=p;
              p:=p^.next;
            end;
          new(p);
          p^.next:=nil;
          p^.data:=t;
          q^.next:=p;
        end;
    end;
  /////////////////////////////////////////////////build
  procedure dfs(x:longint);
    var
      i,j:longint;
      p,q:pt;
    begin
      inc(time);
      dfn[x]:=time;
      low[x]:=time;
      inc(top);
      st[top]:=x;
      ins[x]:=true;
      p:=a[x];
      while p<>nil do
        begin
          i:=p^.data;
          if not v[i] then
            begin
              v[i]:=true;
              dfs(i);
              low[x]:=min(low[x],low[i]);
            end
          else if ins[i] then
            low[x]:=min(low[x],dfn[i]);
          p:=p^.next;
        end;
      if dfn[x]=low[x] then
        begin
          inc(k);
          while st[top]<>x do
            begin
              ins[st[top]]:=false;
              fa[st[top]]:=k;
              if cost[st[top]]>nw[k].max then
                nw[k].max:=cost[st[top]];
              nw[k].min:=min(nw[k].min,cost[st[top]]);
              dec(top);
            end;
          ins[x]:=false;
          fa[x]:=k;
          if cost[x]>nw[k].max then
            nw[k].max:=cost[x];
          nw[k].min:=min(nw[k].min,cost[x]);
          dec(top);
        end;
    end;
  ///////////////////////////////////////////dfs
  procedure rebuild;
    var
      i,j,u,fi,fu:longint;
      p,pp,q:pt;
    begin
      for i:=1 to n do
        begin
          p:=a[i];
          while p<>nil do
            begin
              u:=p^.data;
              if fa[i]<>fa[u] then
                begin
                  if nw[fa[i]].head=nil then
                    begin
                      new(nw[fa[i]].head);
                      nw[fa[i]].head^.next:=nil;
                      nw[fa[i]].head^.data:=fa[u];
                    end
                  else
                    begin
                      q:=nw[fa[i]].head;
                      while q<>nil do
                        begin
                          pp:=q;
                          q:=q^.next;
                        end;
                      new(q);
                      q^.next:=nil;
                      q^.data:=fa[u];
                      pp^.next:=q;
                    end;
                  if fan[fa[u]]=nil then
                    begin
                      new(fan[fa[u]]);
                      fan[fa[u]]^.next:=nil;
                      fan[fa[u]]^.data:=fa[i];
                    end
                  else
                    begin
                      q:=fan[fa[u]];
                      while q<>nil do
                        begin
                          pp:=q;
                          q:=q^.next;
                        end;
                      new(q);
                      q^.next:=nil;
                      q^.data:=fa[i];
                      pp^.next:=q;
                    end;
                end;
              p:=p^.next;
            end;
        end;
    end;
  ////////////////////////////////////////////rebuild
  procedure findans(x,l:longint);
    var
      i,j,da,xiao:longint;
      p,q:pt;
    begin
      if x=fa[n] then
        begin
          zui[x]:=min(zui[x],l);
          {zuians[x]:=max(zuians[x],r);
          xiao:=min(l,nw[x].min);
          da:=max(r,nw[x].max-xiao);
          if da>ans then
            ans:=da; }
          exit;
        end
      else
        begin
          xiao:=min(l,nw[x].min);
          zui[x]:=min(zui[x],xiao);
          //da:=max(r,nw[x].max-xiao);
          p:=nw[x].head;
          while p<>nil do
            begin
              j:=p^.data;
              if (xiao<zui[j]) then findans(p^.data,xiao);
              p:=p^.next;
            end;
        end;
    end;
  procedure fandfs(x:longint);
    var
      i,j:longint;
      p,q:pt;
    begin
      v[x]:=true;
      p:=fan[x];
      while p<>nil do
        begin
          if not v[p^.data] then fandfs(p^.data);
          p:=p^.next;
        end;
    end;
begin
  //assign(input,'1122.in');reset(input);
  fillchar(st,sizeof(st),0);
  fillchar(fa,sizeof(fa),0);
  fillchar(cost,sizeof(cost),0);
  fillchar(dfn,sizeof(dfn),0);
  fillchar(low,sizeof(low),0);
  fillchar(v,sizeof(v),0);
  fillchar(ins,sizeof(ins),0);
  for i:=1 to 100001 do
    begin
      nw[i].head:=nil;
      nw[i].min:=maxlongint;
      nw[i].max:=-1000;
      a[i]:=nil;
      fan[i]:=nil;
    end;
  readln(n,m);
  for i:=1 to n do
    read(cost[i]);
  for i:=1 to m do
    begin
      readln(s,t,k);
      if k=1 then
        build(s,t)
      else
        begin
          build(s,t);
          build(t,s);
        end;
    end;
  time:=0;
  k:=0;
  top:=0;
  for i:=1 to n do
    if not v[i] then
      begin
        v[i]:=true;
        dfs(i);
      end;{
  for i:=1 to n do
    write(fa[i],' ');
  writeln;
  writeln(k);
  halt; }
  rebuild;
  ans:=0;
  for i:=1 to k do
    zui[i]:=maxlongint;
  zui[1]:=nw[1].min;
  findans(fa[1],nw[fa[1]].min);
  fillchar(v,sizeof(v),false);
  //writeln('fa[n]=',fa[n]);
  //k right
  fandfs(fa[n]);{
  //writeln(k);halt;
  //k wrong
  for i:=1 to k do
    writeln(zui[i]);
  halt;}
  for i:=1 to k do
    if (v[i])and(nw[i].max-zui[i]>ans) then
      ans:=nw[i].max-zui[i];
  writeln(ans);
  //writeln('zui=',aa);
end.
