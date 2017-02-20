type
  node=record
    s,t,e:longint;
  end;
var
  f:array[1..100]of longint;
  ans:array[1..4950]of longint;
  v:array[1..100]of boolean;
  q:array[1..5000]of node;
  flag,fl:boolean;
  n,m,ii,jj,tem,temp,min:longint;
  procedure init;
    var
      i,j:longint;
    begin
      fillchar(f,sizeof(f),0);
      fillchar(ans,sizeof(ans),127);
      fillchar(v,sizeof(v),false);
      fillchar(q,sizeof(q),0);
      for i:=1 to m do
        begin
          with q[i] do
            begin
              readln(s,t,e);
              v[s]:=true;
              v[t]:=true;
            end;
        end;
      flag:=true;
      for i:=1 to n do
        if not v[i] then
          begin
            flag:=false;
            exit;
          end;
    end;
  procedure qsort(head,tail:longint);
    var
      x:node;
      te,i,j:longint;
    begin
      i:=head;
      j:=tail;
      randomize;
      te:=random(tail-head)+head;
      x:=q[te];
      q[te]:=q[head];
      q[head]:=x;
      while i<j do
        begin
          while (i<j)and(q[j].e>=x.e) do
            dec(j);
          q[i]:=q[j];
          while (i<j)and(q[i].e<=x.e) do
            inc(i);
          q[j]:=q[i];
        end;
      q[i]:=x;
      if i-1>head then qsort(head,i-1);
      if j+1<tail then qsort(j+1,tail);
    end;
  function find(x:longint):longint;
    begin
      if f[x]=x then exit(x);
      f[x]:=find(f[x]);
      exit(f[x]);
    end;
  procedure union(x,y:longint);
    begin
      f[find(x)]:=find(f[y]);
    end;
  procedure kruskal(k:longint);
    var
      i,j,ingraph:longint;
    begin
      ingraph:=1;
      i:=k;
      while (ingraph<n)and(i<=m) do
        begin
          if find(q[i].s)<>find(q[i].t) then
            begin
              inc(ingraph);
              union(q[i].s,q[i].t);
            end;
          inc(i);
        end;
      if (i>m)and(ingraph<n) then
        begin
          flag:=false;
          exit;
        end;
      dec(i);
      ans[k]:=q[i].e-q[k].e;
    end;
begin
  {assign(input,'poj3522.in');
  assign(output,'poj3522.out');
  reset(input);
  rewrite(output);   }
  readln(n,m);
  fl:=false;
  while n<>0 do
    begin
      if fl then writeln;
      flag:=true;
      init;
      if not flag then
        begin
          write(-1);
          readln(n,m);
          continue;
        end;
      qsort(1,m);
      tem:=m-n+2;
      min:=maxlongint;
      for ii:=1 to tem do
        begin
          for jj:=1 to n do
            f[jj]:=jj;
          flag:=true;
          kruskal(ii);
          if not flag then continue;
          if ans[ii]<min then min:=ans[ii];
        end;
      if min=maxlongint then begin write(-1);readln(n,m);continue;end;
      write(min);
      fl:=true;
      readln(n,m);
    end;               {
  close(input);
  close(output);      }
end.