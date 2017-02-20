var
  f:Array[0..202]of longint;
  map:array[0..201,0..201]of double;
  dis:array[1..40200]of double;
  a:array[1..201,1..2]of longint;
  i,j,d,k,l,r,n,m,t,s,ii:longint;
  ans:double;
  function find(x:longint):longint;
    begin
      if f[x]=x then exit(X);
      f[x]:=find(f[x]);
      exit(F[x]);
    end;
  procedure qsort(h,t:longint);
    var
      i,j,tt:longint;
      x:double;
    begin
      i:=h;
      j:=t;
      randomize;
      tt:=random(t-h)+h;
      x:=dis[tt];
      dis[tt]:=dis[h];
      dis[h]:=x;
      while i<j do
        begin
          while(i<j)and(dis[j]>=x) do
            dec(j);
          dis[i]:=dis[j];
          while(i<j)and(dis[i]<=x) do
            inc(i);
          dis[j]:=dis[i];
        end;
      dis[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
begin
  ii:=0;
  readln(n);
  while n<>0 do
    begin
      inc(ii);
      d:=0;
      fillchar(map,sizeof(map),127);
      fillchar(d,sizeof(D),0);
      fillchar(a,sizeof(A),0);
      fillchar(f,sizeof(f),0);
      for i:=1 to n do
        begin
          read(a[i,1],a[i,2]);
          for j:=1 to i-1 do
            begin
              map[i,j]:=sqrt(sqr(a[i,1]-a[j,1])+sqr(a[i,2]-a[j,2]));
              map[j,i]:=map[i,j];
              inc(d);
              dis[d]:=map[i,j];
            end;
        end;
      qsort(1,d);
      l:=1;
      r:=d;
      while l<=r do
        begin
          m:=(l+r)div 2;
          for i:=1 to n do
            f[i]:=i;
          for i:=1 to n do
            for j:=1 to i-1 do
              if map[i,j]<=dis[m] then
                f[find(i)]:=find(j);
          if find(1)=find(2) then
            begin
              ans:=dis[m];
              r:=m-1;
            end
          else
            l:=m+1;
        end;
      writeln('Scenario #',ii);
      write('Frog Distance = ');
      writeln(ans:0:3);
      writeln;
      readln(n);
    end;
end.
