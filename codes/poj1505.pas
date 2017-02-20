var
  v:array[0..510]of boolean;
  a:array[0..510]of longint;
  case_,i,j,k,m,n,max,u:longint;
  mid,s,ans,min,l,r:int64;
begin
  read(case_);
  while case_>0 do
    begin
      dec(case_);
      fillchar(a,sizeof(a),0);
      readln(n,m);
      fillchar(v,sizeof(v),false);
      s:=0;
      max:=-1;
      for i:=1 to n do
        begin
          read(A[i]);
          if a[i]>max then
            max:=a[i];
          inc(s,a[i]);
        end;
      l:=max;
      r:=s;
      while l<r do
        begin
          u:=0;
          mid:=(l+r)shr 1;
          i:=n;
          while i>0 do
            begin
              s:=0;
              inc(u);
              while (i>0)and(s+a[i]<=mid) do
                begin
                  inc(s,a[i]);
                  dec(i);
                end;
            end;
          if u<=m then
            r:=mid
          else
            l:=mid+1;
        end;
      i:=n;
      u:=0;
      while i>0 do
        begin
          s:=0;
          inc(u);
          while(i>0)and(s+a[i]<=l) do
            begin
              inc(s,a[i]);
              dec(i);
            end;
          v[i]:=true;
        end;
      i:=1;
      while u<m do
        begin
          while v[i] do
            inc(i);
          v[i]:=true;
          inc(u);
        end;
      for i:=1 to n-1 do
        begin
          write(a[i],' ');
          if v[i] then
            write('/ ');
        end;
      writeln(a[n]);
    end;
end.

