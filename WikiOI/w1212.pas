var
  a,b,i,j:longint;
  function gcd(a,b:longint):longint;
    begin
      if b=0 then exit(a);
      exit(gcd(b,a mod b));
    end;
begin
  readln(a,b);
  writeln(gcd(a,b));
end.