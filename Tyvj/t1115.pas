var
  a,b:array[1..100]of longint;
  min,n,i,m,j,k:longint;
  flag:boolean;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  min:=maxlongint;
  for i:=1 to n do
    begin
      read(a[i]);
      if i=1 then continue;
      b[i-1]:=abs(a[i-1]-a[i]);
      if b[i-1]<min then min:=b[i-1];
    end;
  for i:=min downto 1 do
    begin
      flag:=true;
      for j:=1 to n-1 do
        if b[j] mod i<>0 then
          begin
            flag:=false;
            break;
          end;
      if flag then
        begin
          writeln(i);
          halt;
        end;
    end;
end.


