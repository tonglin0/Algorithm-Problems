var
  a,n,d,m,i,j,k,s:longint;
  function pri(k:longint):boolean;
    var
      i,j:longint;
    begin
      if k=1 then exit(false);
      for i:=2 to trunc(sqrt(k)) do
        if k mod i=0 then exit(false);
      exit(true);
    end;
begin
  assign(input,'3006.in');
  assign(output,'3006.out');
  reset(input);
  rewrite(output);
  readln(a,d,n);
  while a<>0 do
    begin
      i:=1;
      s:=a-d;
      while i<=n do
        begin
          inc(s,d);
          while not pri(s) do
            inc(s,d);
          inc(i);
        end;
      writeln(s);
      readln(a,d,n);
    end;
  close(input);
  close(output);
end.

