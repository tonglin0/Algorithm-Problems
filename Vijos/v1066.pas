type
  node=record
    x,y:longint;
  end;
var
  a:array[1..15002]of node;
  ans:array[0..15000]of longint;
  c:array[0..32002]of longint;
  n,x,y,i,j,k,t,p:longint;
  function lowbit(k:longint):longint;
    begin
      lowbit:=k and (k xor (k-1));
    end;
  function getsum(i:longint):longint;
    var
      s,k:longint;
    begin
      s:=0;
      k:=i;
      while k>0 do
        begin
          s:=s+c[k];
          k:=k-lowbit(k);
        end;
      exit(s);
    end;
  procedure add(i:longint);
    var
      k:longint;
    begin
      k:=i;
      while k<=t do
        begin
          inc(c[k]);
          inc(k,lowbit(k));
        end;
    end;
  procedure qsort(h,t:longint);
    var
      i,j,tt:longint;
      x:node;
    begin
      j:=t;
      i:=h;
      x:=a[h];
      randomize;
      tt:=random(t-h)+h;
      x:=a[tt];
      a[tt]:=a[h];
      a[h]:=x;
      while i<j do
        begin
          while (i<j)and((a[j].y>x.y)or((a[j].y=x.y)and(a[j].x>=x.x)))do
            dec(j);
          a[i]:=a[j];
          while (i<j)and((a[i].y<x.y)or((a[i].y=x.y)and(a[i].x<=x.x)))do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qsort(h,i-1);
      if j+1<t then qsort(j+1,t);
    end;
begin
  fillchar(c,sizeof(c),0);
  fillchar(a,sizeof(a),0);
  fillchar(ans,sizeof(ans),0);
  readln(n);
  t:=0;
  for i:=1 to n do
    begin
      readln(a[i].x,a[i].y);
      if a[i].x>t then t:=a[i].x;
    end;
  qsort(1,n);
  //for i:=1 to n do
  //  writeln(a[i].x,' ',a[i].y);
  //halt;
  for i:=1 to n do
    begin
      if (i>1)and(a[i].x=a[i-1].x)and(a[i].y=a[i-1].y)then
        begin
          inc(ans[p]);
          add(a[i].x);
          continue;
        end;
      p:=getsum(a[i].x);
      inc(ans[p]);
      add(a[i].x);
    end;
  for i:=0 to n-1 do
    writeln(ans[i]);
end.
