var
  v:array[0..20000]of boolean;
  a:array[0..200]of longint;
  f:Array[-1..100000]of longint;
  i,j,l,r,k,m,n,s,t,ans:longint;
  procedure qs(h,t:longint);
    var
      x,i,j,tt:longint;
    begin
      tt:=random(t-h)+h;
      i:=h;
      j:=t;
      x:=a[tt];
      a[tt]:=a[h];
      a[h]:=x;
      while i<j do
        begin
          while(i<j)and(a[j]>=x) do
            dec(j);
          a[i]:=a[j];
          while(i<j)and(a[i]<=x) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
begin
  assign(input,'river4.in');reset(input);
  fillchar(v,sizeof(v),false);
  fillchar(f,sizeof(f),127);
  readln(l);
  readln(s,t,n);
  for i:=1 to n do
    read(a[i]);
  if s=t then
    begin
      ans:=0;
      for i:=1 to n do
        if a[i] mod s=0 then
          inc(ans);
      writeln(ans);
      halt;
    end;
  randomize;
  qs(1,n);
  a[0]:=0;
  for i:=1 to n do
    if a[i]-a[i-1]>t then
      begin
        k:=(a[i]-a[i-1]) div t*t;
        a[i]:=a[i]-k;
        for j:=i+1 to n do
          a[j]:=a[j]-k;
      end;
  for i:=1 to n do
    v[a[i]]:=true;
  l:=a[n]+t;
  for i:=s to t do
    if v[i] then
      f[i]:=1
    else
      f[i]:=0;
  for i:=t+1 to l do
    begin
      for j:=s to t do
        if (f[i-j]<>f[-1])and(f[i-j]<f[i]) then
          f[i]:=f[i-j];
      if v[i] then
        inc(f[i]);
    end;
  ans:=maxlongint;
  for i:=a[n] to l do
    if f[i]<ans then
      ans:=f[i];
  writeln(ans);
end.
