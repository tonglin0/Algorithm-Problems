var
  l,r,fa:array[0..1001]of longint;
  i,j,k,m,n,s,t:longint;
begin
  //assign(input,'1033.in');reset(input);
  fillchar(l,sizeof(l),0);
  fillchar(r,sizeof(r),0);
  fillchar(fa,sizeof(fa),0);
  readln(n);
  dec(n);
  for i:=1 to n do
    begin
      read(k,s,t);
      l[k]:=s;
      r[k]:=t;
      fa[s]:=k;
      fa[t]:=k;
    end;
  s:=0;
  for i:=1 to n do
    if (l[i]=0)and(r[i]=0) then
      begin
        k:=0;
        t:=i;
        while t<>1 do
          begin
            inc(k);
            t:=fa[t];
          end;
        if k>s then s:=k;
      end;
  writeln(s+1);
end.

