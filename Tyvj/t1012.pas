const
  a:array[0..9]of longint=(6,2,5,5,4,5,6,3,7,6);
var
  i,s,j,k,l,m,n:longint;
  function num(x:longint):longint;
    var
      s:string;
      i,j:longint;
    begin
      str(x,s);
      j:=length(s);
      num:=0;
      for i:=1 to j do
        num:=num+a[ord(s[i])-48];
      exit(num);
    end;
begin
  readln(n);
  dec(n,4);
  for i:=0 to 1000 do
    for j:=i to 1000 do
      begin
        k:=i+j;
        if num(i)+num(j)+num(k)=n then
          begin
            if i=j then inc(s);
            if i<>j then inc(s,2);
          end;
      end;
  writeln(s);
end.