var
  a:array[0..1100000]of longint;
  i,j,k,m,n,s,t:longint;
  procedure up(k:longint);
    var
      s,i,j:longint;
    begin
      s:=a[k];
      i:=k;
      while i>1 do
        begin
          if a[i shr 1]>s then
            begin
              a[i]:=a[i shr 1];
              i:=i shr 1;
            end
          else
            break;
        end;
      a[i]:=s;
    end;
  procedure down(k:longint);
    var
      s,i,j:longint;
    begin
      s:=a[k];
      i:=k;
      while i<=(t shr 1) do
        begin
          j:=i shl 1;
          if (j<t)and(a[j+1]<a[j]) then
            inc(j);
          if a[j]<s then
            begin
              a[i]:=a[j];
              i:=j;
            end
          else
            break;
        end;
      a[i]:=s;
    end;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      up(i);
    end;
  t:=n;
  for i:=1 to n-1 do
    begin
      write(a[1],' ');
      a[1]:=a[t];
      dec(t);
      down(1);
    end;
  writeln(a[1]);
end.
