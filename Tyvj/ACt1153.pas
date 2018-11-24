type
  pt=^pk;
  pk=record
    data:longint;
    next:pt;
  end;
  node=record
    ind,oud,min:longint;
    head:pt;
  end;
var
  a:array[0..3001]of pt;
  g:Array[0..3000]of node;
  p,q,qq:pt;
  ins,v:array[0..3001]of boolean;
  st,money,low,f,dfn:array[0..3001]of longint;
  top,time,i,t,j,k,ans,n,m,s:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
  procedure dfs(x:longint);
    var
      i,j:longint;
      p:pt;
    begin
      inc(time);
      dfn[x]:=time;
      low[x]:=time;
      inc(top);
      ins[x]:=true;
      st[top]:=x;
      p:=a[x];
      while p<>nil do
        begin
          if not v[p^.data] then
            begin
              v[p^.data]:=true;
              dfs(p^.data);
              low[x]:=min(low[x],low[p^.data]);
            end
          else if ins[p^.data] then
            low[x]:=min(low[x],dfn[p^.data]);
          p:=p^.next;
        end;
      if low[x]=dfn[x] then
        begin
          inc(k);
          while st[top]<>x do
            begin
              f[st[top]]:=k;
              ins[st[top]]:=false;
              if (money[st[top]]<>0)and((money[st[top]]<g[k].min)or(g[k].min=-1)) then
                g[k].min:=money[st[top]];
              dec(top);
            end;
          f[st[top]]:=k;
          ins[st[top]]:=false;
          if (money[st[top]]<>0)and((money[st[top]]<g[k].min)or(g[k].min=-1)) then
            g[k].min:=money[st[top]];
          dec(top);
        end;
    end;
  procedure rebuild;
    var
      q,qq,p:pt;
    begin
      for i:=1 to n do
        begin
          p:=a[i];
          if p=nil then continue;
          while p<>nil do
            begin
              if f[i]<>f[p^.data] then
                begin
                  inc(g[f[i]].oud);
                  inc(g[f[p^.data]].ind);
                  q:=g[f[i]].head;
                  if q=nil then
                    begin
                      new(g[f[i]].head);
                      g[f[i]].head^.data:=f[p^.data];
                      p:=p^.next;
                      continue;
                    end
                  else
                    begin
                      while q^.next<>nil do
                        q:=q^.next;
                      new(qq);
                      qq^.data:=f[p^.data];
                      qq^.next:=nil;
                      q^.next:=qq;
                      p:=p^.next;
                      continue;
                    end;
                end;
              p:=p^.next;
            end;
        end;
    end;
  procedure flood(x:longint);
    var
      i:longint;
      b:pt;
    begin
      v[x]:=true;
      b:=g[x].head;
      while b<>nil do
        begin
          if not v[b^.data] then flood(b^.data);
          b:=b^.next;
        end;
    end;
  procedure tuopu;
    var
      ff:boolean;
      p:pt;
      i,j:longint;
    begin
      while true do
        begin
          ff:=false;
          for i:=1 to k do
            if (not ins[i])and(g[i].ind=0) then
              begin
                ff:=true;
                ins[i]:=true;
                if (not v[i])and(g[i].min>0) then
                  begin
                    inc(ans,g[i].min);
                    flood(i);
                  end;
                p:=g[i].head;
                while p<>nil do
                  begin
                    dec(g[p^.data].ind);
                    p:=p^.next;
                  end;
                break;
              end;
          if not ff then break;
        end;
      for i:=1 to n do
        if not v[f[i]] then
          begin
            writeln('NO');
            writeln(i);
            //close(input);
            //close(output);
            halt;
          end;
      writeln('YES');
      writeln(ans);
    end;
begin
  //assign(input,'age.in');assign(output,'age.out');reset(input);rewrite(output);
  for i:=0 to 3001 do
    a[i]:=nil;
  for i:=0 to 3000 do
    begin
      g[i].ind:=0;
      g[i].oud:=0;
      g[i].min:=-1;
      g[i].head:=nil;
    end;
  fillchar(st,sizeof(st),0);
  fillchar(f,sizeof(f),0);
  fillchar(dfn,sizeof(dfn),0);
  fillchar(low,sizeof(low),0);
  fillchar(v,sizeof(v),0);
  fillchar(ins,sizeof(ins),0);
  fillchar(money,sizeof(money),0);
  read(n);
  read(m);
  for i:=1 to m do
    begin
      read(k,t);
      money[k]:=t;
    end;
  read(m);
  for i:=1 to m do
    begin
      read(k,t);
      if a[k]=nil then
        begin
          new(p);
          p^.data:=t;
          p^.next:=nil;
          a[k]:=p;
          continue;
        end;
      p:=a[k]^.next;
      q:=a[k];
      while p<>nil do
        begin
          q:=p;
          p:=p^.next;
        end;
      new(p);
      p^.data:=t;
      p^.next:=nil;
      q^.next:=p;
    end;
  time:=0;
  top:=0;
  k:=0;
  for i:=1 to n do
    if not v[i] then
      begin
        v[i]:=true;
        dfs(i);
      end;
  rebuild;
  fillchar(ins,sizeof(ins),false);
  fillchar(v,sizeof(v),false);
  ans:=0;
  tuopu;
  //close(input);close(output);
end.
