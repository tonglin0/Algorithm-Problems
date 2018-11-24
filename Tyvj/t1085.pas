var
  d:array[1..10]of longint;
  v:array[1..10]of boolean;
  a:array[1..10]of longint;
  n,m,k,t,i,j,ans:longint;
  procedure dfs(m:longint);
    var
      i,j:longint;
    begin
      if m=n+1 then
        begin
          inc(ans);
          exit;
        end;
      for i:=1 to n do
        if not v[i] then
          begin
            d[m]:=a[i];
            if (m=1)or((m<>n)and(abs(d[m]-d[m-1])<=k))or((m=n)and(abs(d[m]-d[m-1])<=k)and(abs(d[m]-d[1])<=k)) then
              begin
                v[i]:=true;
                dfs(m+1);
                v[i]:=false;
              end;
          end;
    end;
begin
  fillchar(a,sizeof(a),0);
  readln(n,k);
  for i:=1 to n do
    readln(a[i]);
  fillchar(d,sizeof(d),0);
  fillchar(v,sizeof(v),false);
  ans:=0;
  dfs(1);
  ans:=ans div n;
  writeln(Ans);
end.
