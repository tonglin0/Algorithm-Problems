var
  b:array[1..10000]of boolean;
  s:array[1..10000]of longint;
  ii,r,top,ans,sum,i,j,k,m,n:longint;
begin
  fillchar(b,sizeof(b),false);
  fillchar(s,sizeof(s),0);
  readln(m,n);
  ans:=0;
  sum:=0;
  top:=0;
  r:=1;
  for ii:=1 to n do
    begin
      read(k);
      if b[k] then continue;
      if sum<m then
        begin
          inc(sum);
          b[k]:=true;
          inc(ans);
          top:=top mod 10000+1;
          s[top]:=k;
          continue;
        end;
      b[s[r]]:=false;
      r:=r mod 10000+1;
      b[k]:=true;
      inc(ans);
      top:=top mod 10000+1;
      s[top]:=k;
    end;
  writeln(ans);
end.

