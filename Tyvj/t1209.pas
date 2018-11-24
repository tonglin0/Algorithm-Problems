var
  a,f,pre:Array[0..100]of longint;
  v:Array[0..100]of boolean;
  i,j,k,m,n,s,t,ans,sum:longint;
  st,ss:ansistring;
  flag:boolean;
  procedure kill(k:longint);
    var
      i,j:longint;
    begin
      v[k]:=false;
      if pre[k]<>0 then kill(pre[k]);
    end;
begin
  //assign(input,'1209.in');reset(input);
  readln(st);
  flag:=true;
  n:=0;
  ans:=0;
  fillchar(v,sizeof(v),true);
  fillchar(a,sizeof(A),0);
  t:=pos(',',st);
  while t<>0 do
    begin
      inc(n);
      ss:=copy(st,1,t-1);
      val(ss,a[n]);
      delete(st,1,t);
      t:=pos(',',st);
    end;
  inc(n);
  val(st,a[n]);
  ans:=0;
  while n>0 do
    begin
      fillchar(f,sizeof(f),0);
      fillchar(pre,sizeof(pre),0);
      f[1]:=1;
      for i:=2 to n do
        begin
          for j:=1 to i-1 do
            if (a[j]>=a[i])and(f[j]>f[i]) then
              begin
                f[i]:=f[j];
                pre[i]:=j;
              end;
          inc(f[i]);
        end;
      s:=0;
      for i:=1 to n do
        if f[i]>s then
          begin
            s:=f[i];
            k:=i;
          end;
      fillchar(v,sizeof(v),true);
      if flag then write(s,',');
      flag:=false;
      kill(k);
      j:=0;
      for i:=1 to n do
        if v[i] then
          begin
            inc(Ans);
            break;
          end;
      for i:=1 to n do
        if v[i] then
          begin
            inc(j);
            a[j]:=a[i];
          end;
      n:=j;
    end;
  writeln(ans);
end.
