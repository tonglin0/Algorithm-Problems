var
  a,v:array[0..200002]of longint;
  i,j,k,m,n,s,t,ans,min:longint;
begin
  //assign(input,'1063.in');assign(output,'a.out');reset(input);rewrite(output);
  fillchar(a,sizeof(a),0);
  fillchar(v,sizeof(v),0);
  read(n,m);
  for i:=1 to n do
    read(a[i]);
  i:=0;
  s:=0;
  j:=0;
  min:=maxlongint;
  while i<n do
    begin
      inc(i);
      if (a[i]<=m)and(a[i]>0)and(v[a[i]]=0) then
        begin
          inc(v[a[i]]);
          inc(s);
        end
      else if (a[i]<=m)and(a[i]>0) then
        inc(v[a[i]]);
      while s=m do
        begin
          inc(j);
          if i-j+1 <min then
            min:=i-j+1;
          if (a[j]<=m)and(a[j]>0) then
            dec(v[a[j]]);
          if (a[j]<=m)and(a[j]>0)and(v[a[j]]=0) then
            dec(s);
        end;
    end;
  if min<maxlongint then
    writeln(min)
  else
    writeln('NO');
  //close(input);close(output);
end.

