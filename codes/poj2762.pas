var
  fa,low,dfn,st:array[0..1001]of longint;
  a:array[0..1000,0..1000]of longint;
  v,ins:array[1..1000]of boolean;
  new:array[0..1000]of longint;
  na:array[0..1000,0..1000]of longint;
  flag:boolean;
  top,ii,time,i,j,n,m,k,t,s:longint;
  function min(x,y:longint):longint;
    begin
      if x<y then exit(x);
      exit(y);
    end;
  procedure dfs(x:longint);
    var
      i:longint;
    begin
      inc(time);
      dfn[x]:=time;
      low[x]:=time;
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
        begin
          inc(k);
          while st[top]<>x do
            begin
              fa[st[top]]:=k;
              ins[st[top]]:=false;
              dec(top);
            end;
          fa[st[top]]:=k;
          ins[st[top]]:=false;
          dec(top);
        end;
    end;
begin
  read(t);
  for ii:=1 to t do
    begin
      fillchar(low,sizeof(low),0);
      fillchar(dfn,sizeof(dfn),0);
      fillchar(st,sizeof(st),0);
      fillchar(a,sizeof(a),0);
      fillchar(fa,sizeof(Fa),0);
      fillchar(v,sizeof(v),false);
      fillchar(ins,sizeof(ins),0);
      fillchar(new,sizeof(new),0);
      fillchar(na,sizeof(na),0);
      read(n,m);
      for i:=1 to m do
        begin
          read(s,k);
          inc(a[s,0]);
          a[s,a[s,0]]:=k;
        end;
      top:=0;
      time:=0;
      k:=0;
      for i:=1 to n do
        if not v[i] then
          begin
            v[i]:=true;
            dfs(i);
          end;
      for i:=1 to n do
        for j:=1 to a[i,0] do
          if fa[i]<>fa[a[i,j]] then
            begin
              inc(new[fa[a[i,j]]]);
              inc(na[fa[i],0]);
              na[fa[i],na[fa[i],0]]:=fa[a[i,j]];
            end;
      fillchar(v,sizeof(v),0);
      flag:=true;
      for i:=1 to k do
        begin
          s:=0;
          for j:=1 to k do
            if (not v[j])and(new[j]=0) then
              begin
                inc(s);
                top:=j;
              end;
          if s>1 then
            begin
              writeln('No');
              flag:=false;
              break;
            end
          else
            begin
              for j:=1 to na[top,0] do
                dec(new[na[top,j]]);
              v[top]:=true;
            end;
        end;
      if flag then writeln('Yes');
    end;
end.
