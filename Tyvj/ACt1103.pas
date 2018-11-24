var
  i,j,k,m,n,t,s:longint;
  flag:boolean;
begin
  readln(n);
  flag:=false;
  for i:=1 to n+1 do
    begin
      read(m);
      if m=0 then continue;
      //if (not flag)and(m>0) then flag:=true;
      if m<0 then write('-');
      if (m>0)and flag then write('+');
      if (abs(m)<>1)or(i=n+1) then write(abs(m));
      if i<>n+1 then write('x');
      if (i<>n)and(i<>n+1) then write('^',n-i+1);
      flag:=true;
    end;
end.


