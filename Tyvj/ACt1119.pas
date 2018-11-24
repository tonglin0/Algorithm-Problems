var
  i,j,k,m,n,s,t,a,b:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(a,b);
      s:=1;
      a:=a mod 1012;
      t:=a;
      while b>0 do
        begin
          if b and 1=1 then
            s:=s*t mod 1012;
          b:=b shr 1;
          t:=t*t mod 1012;
        end;
      writeln(s);
    end;
end.
