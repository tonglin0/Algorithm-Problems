var
  a,b,c:array[-13..27]of boolean;
  d:array[1..13]of longint;
  i,j,n,m,ans,k,t,s:longint;
  procedure work(k:longint);
    var
      i,j:longint;
    begin
      if k=n+1 then
        begin
          inc(ans);
          if s<3 then
            begin
              for i:=1 to n-1 do
                write(d[i],' ');
              writeln(d[n]);
              inc(s);
            end;
        end;
      for i:=1 to n do
        if not(a[i] or b[i-k] or c[i+k]) then
          begin
            a[i]:=true;
            b[i-k]:=true;
            c[i+k]:=true;
            d[k]:=i;
            work(k+1);
            a[i]:=false;
            b[i-k]:=false;
            c[i+k]:=false;
          end;
    end;
  procedure worka(k:longint);
    var
      i,j:longint;
    begin   {
      if k=n+1 then
        begin
          inc(ans);
          if s<3 then
            begin
              for i:=1 to n do
                write(d[i],' ');
              writeln(d[n]);
              inc(s);
            end;
        end; }
      if k=1 then
        begin
          for i:=1 to 6 do
            begin
              a[i]:=true;
              b[i-k]:=true;
              c[i+k]:=true;
              d[k]:=i;
              work(k+1);
              a[i]:=false;
              b[i-k]:=false;
              c[i+k]:=false;
            end;
        end;
    end;
  procedure workb(k:longint);
    var
      i,j:longint;
    begin
      d[k]:=7;
      a[7]:=true;
      b[6]:=true;
      c[8]:=true;
      j:=k+1;
      for i:=1 to 6 do
        if not(a[i] or b[i-j] or c[i+j]) then
          begin
            a[i]:=true;
            b[i-j]:=true;
            c[i+j]:=true;
            d[j]:=i;
            work(j+1);
            a[i]:=false;
            b[i-j]:=false;
            c[i+j]:=false;
          end;
      a[7]:=false;
      b[6]:=false;
      c[8]:=false;
    end;
begin
  readln(n);
  fillchar(a,sizeof(a),false);
  fillchar(b,sizeof(b),false);
  fillchar(c,sizeof(c),false);
  fillchar(d,sizeof(d),0);
  s:=0;
  ans:=0;
  if n=13 then
    begin
      worka(1);
      workb(1);
      ans:=ans shl 1;
      writeln(ans);
      halt;
    end;
  work(1);
  writeln(ans);
end.

