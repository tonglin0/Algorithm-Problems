label
  l1;
var
  n:int64;
  max,min,z:int64;
  s:string;
  i,j,k,t,l,sw:longint;
  a:array[1..10000]of int64;
begin
  //assign(input,'1024.in');reset(input);
  l1:
  while not eof do
    begin
      readln(n);
      fillchar(a,sizeof(a),0);
      t:=1;
      a[1]:=n;
      sw:=trunc(ln(n)/ln(10))+1;
      //fillchar(a,sizeof(a),0);
      while true do
        begin
          l:=trunc(ln(n)/ln(10))+1;
          while l<sw do
            begin
              n:=n*10;
              inc(l);
            end;
          str(n,s);
          max:=0;
          while s<>'' do
            begin
              l:=length(s);
              z:=-1;
              for i:=1 to l do
                if ord(s[i])-48>z then
                  begin
                    k:=i;
                    z:=ord(s[i])-48;
                  end;
              max:=max*10+z;
              delete(s,k,1);
            end;
          min:=0;
          str(n,s);
          while s<>'' do
            begin
              l:=length(s);
              z:=10;
              for i:=1 to l do
                if ord(s[i])-48<z then
                  begin
                    k:=i;
                    z:=ord(s[i])-48;
                  end;
              min:=min*10+z;
              delete(s,k,1);
            end;
          n:=max-min;
          l:=trunc(ln(n)/ln(10))+1;
          while l<sw do
            begin
              inc(l);
              n:=n*10;
            end;
          for i:=1 to t do
            if a[i]=n then
              begin
                for j:=i to t-1 do
                  write(a[j],' ');
                writeln(a[t]);
                goto l1;
              end;
          inc(t);
          a[t]:=n;
        end;
    end;
end.


