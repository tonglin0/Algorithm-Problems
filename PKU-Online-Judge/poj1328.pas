var
  a:array[0..1002,1..2]of double;
  i,j,k,m,ans,case_,n,s,t:longint;
  l,d,r,x,y:double;
  flag:boolean;
  procedure qs(h,t:longint);
    var
      xl,xr:double;
      i,j,tt:longint;
    begin
      i:=h;
      j:=t;
      tt:=random(t-h)+h;
      xl:=a[tt,1];
      a[tt,1]:=a[h,1];
      a[h,1]:=xl;
      xr:=a[tt,2];
      a[tt,2]:=a[h,2];
      a[h,2]:=xr;
      while i<j do
        begin
          while (i<j)and(a[j,2]>=xr) do
            dec(j);
          a[i,1]:=a[j,1];
          a[i,2]:=a[j,2];
          while (i<j)And(a[i,2]<=xr) do
            inc(i);
          a[j,1]:=a[i,1];
          a[j,2]:=a[i,2];
        end;
      a[i,1]:=xl;
      a[i,2]:=xr;
      if i-1>h then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
begin
  assign(input,'1328.in');assign(output,'1328.out');reset(input);rewrite(output);
  case_:=0;
  randomize;
  readln(n,d);
  while not ((n=0)and(d=0)) do
    begin
      inc(case_);
      flag:=true;
      fillchar(a,sizeof(a),0);
      for i:=1 to n do
        begin
          readln(x,y);
          if y>d then
            flag:=false;
          if flag then l:=x-sqrt(sqr(d)-sqr(y));
          if flag then r:=x+sqrt(sqr(d)-sqr(y));
          a[i,1]:=l;
          a[i,2]:=r;
        end;
      if not flag then
        begin
          writeln('Case ',case_,': -1');
          readln;
          readln(n,d);
          continue;
        end;
      qs(1,n);
      ans:=0;
      i:=n;
      while i>0 do
        begin
          r:=a[i,2];
          l:=a[i,1];
          j:=i-1;
          while (j>0)and(a[j,2]>=l) do
            begin
              if a[j,1]>l then
                l:=a[j,1];
              dec(j);
            end;
          inc(ans);
          i:=j;
        end;
      writeln('Case ',case_,': ',ans);
      readln;
      readln(n,d);
    end;
  close(input);close(output);
end.
