var
  a,b:int64;
  c:qword;
  s:ansistring;
  i,j,k,n,m,l:longint;
begin
//while not eof do
//begin
  readln(a,b);
  if a=b then begin writeln(0);halt;end;
  if ((b<=0)and(a>=0))or((b<=0)and(a<=0)and(abs(a)<=abs(b)))or((b>=0)and(a>=0)and(abs(a)>=abs(b)))then
    begin
      c:=a-b;
      str(c,s);
      l:=length(s);
      if l<=3 then
        begin
          writeln(s);
          halt;
        end;
      n:=l mod 3;
      for i:=1 to n do
        write(s[i]);
      delete(s,1,n);
      k:=l div 3;
      for i:=1 to k do
        begin
          if (n=0)and(i=1) then write(s[1],s[2],s[3]) else
          write(',',s[1],s[2],s[3]);
          delete(s,1,3);
        end;
    end
  else
    begin
      write('-');
      c:=b-a;
      str(c,s);
      l:=length(s);
      if l<=3 then
        begin
          writeln(s);
          halt;
        end;
      n:=l mod 3;
      for i:=1 to n do
        write(s[i]);
      delete(s,1,n);
      k:=l div 3;
      for i:=1 to k do
        begin
          if (n=0)and(i=1) then write(s[1],s[2],s[3]) else
          write(',',s[1],s[2],s[3]);
          delete(s,1,3);
        end;
    end;
//end;
end.
