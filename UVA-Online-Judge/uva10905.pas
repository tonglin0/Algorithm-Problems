var
  n,i,j,k,m,t,ans:longint;
  a:array[0..100]of ansistring;
  s,ss:ansistring;
  function xiaoyu(sa,sb:ansistring):boolean;
    var
      l,i,la,lb:longint;
      a,b:ansistring;
    begin
      a:=sa+sb;
      b:=sb+sa;
      if a<b then exit(true)
        else exit(false);
    end;
begin
  readln(n);
  while n<>0 do
    begin
      readln(s);
      for i:=1 to n-1 do
        begin
          t:=pos(' ',s);
          ss:=copy(s,1,t-1);
          delete(s,1,t);
          a[i]:=ss;
        end;
      a[n]:=s;
      for i:=1 to n do
        for j:=i+1 to n do
          if xiaoyu(a[i],a[j]) then
            begin
              s:=a[i];
              a[i]:=a[j];
              a[j]:=s;
            end;
      ss:='';
      for i:=1 to n do
        ss:=ss+a[i];
      writeln(ss);
      readln(n);
    end;
end.

