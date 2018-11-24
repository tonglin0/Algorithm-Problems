var
  a:array[1..10000]of longint;
  n,i,j,t,min1,min2,k,s:longint;
  procedure up(k:longint);
    var
      x,i,j,t:longint;
    begin
      t:=k div 2;
      x:=a[k];
      while (t>0)and(a[t]>x) do
        begin
          a[k]:=a[t];
          t:=t div 2;
          k:=k div 2;
        end;
      a[k]:=x;
    end;
  procedure del;
    var
      i,j,k,x:longint;
    begin
      a[1]:=a[t+1];
      x:=a[1];
      k:=1;
      while (k<=t div 2) do
        begin
          k:=k shl 1;
          if (k+1<=t)and(a[k+1]<a[k]) then inc(k);
          if a[k]<x then a[k div 2]:=a[k]
            else begin k:=k shr 1;break;end;
        end;
      a[k]:=x;
    end;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      up(i);
    end;
  s:=0;
  t:=n;
  for i:=1 to n-1 do
    begin
      min1:=a[1];
      inc(s,a[1]);
      dec(t);
      del;
      min2:=a[1];
      inc(s,a[1]);
      dec(t);
      del;
      inc(t);
      a[t]:=min1+min2;
      up(t);
    end;
  writeln(s);
end.

