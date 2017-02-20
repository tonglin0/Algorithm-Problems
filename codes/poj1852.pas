var
  ii,min,max,i,j,t,n,m:longint;
begin
  readln(t);
  for ii:=1 to t do
    begin
      readln(m,n);
      min:=-1;
      max:=-1;
      for i:=1 to n do
        begin
          read(j);
          if j>m-j then
            begin
              if j>max then max:=j;
              if m-j>min then min:=m-j;
            end
          else
            begin
              if m-j>max then max:=m-j;
              if j>min then min:=j;
            end;
        end;
      writeln(min,' ',max);
    end;
end.

