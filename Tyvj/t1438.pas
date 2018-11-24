var
  fa,l:array[0..50001]of longint;
  i,j,p,q,k,m,n,s,t,ans:longint;
  function find(x:longint):longint;
    begin
      if fa[x]=x then exit(x);
      find:=find(fa[x]);
      l[x]:=(l[x]+l[fa[x]])mod 3;
      fa[x]:=find;
    end;
begin
  //assign(input,'1438.in');reset(input);
  fillchar(fa,sizeof(fa),0);
  fillchar(l,sizeof(l),0);
  read(n,m);
  for i:=1 to n do
    fa[i]:=i;
  ans:=0;
  for i:=1 to m do
    begin
      read(k,s,t);
      if (s>n)or(t>n) then
        begin
          inc(ans);
          //writeln('w',i);
          continue;
        end;
      if (k=2)and(s=t) then
        begin
          inc(ans);
          //writeln('w',i);
          continue;
        end;
      dec(k);
      p:=find(s);
      q:=find(t);
      if p=q then
        begin
          if (l[s]+k)mod 3<>l[t] then
            begin
              inc(ans);
              //writeln('w',i);
              continue;
            end
          else
            continue;
        end
      else
        begin
          fa[q]:=p;
          l[q]:=(3+l[s]+k-l[t])mod 3;
        end;
    end;
  writeln(ans);
end.
