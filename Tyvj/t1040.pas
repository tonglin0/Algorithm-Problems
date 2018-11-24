var
  sa,sb,s:ansistring;
  a,b,c:array[1..1500]of longint;
  i,j,la,lb,k,n,m,l,ans,t:longint;
  function max(x,y:longint):longint;
    begin
      if x>=y then exit(x);
      exit(y);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),9);
  readln(s);
  t:=-1;
  l:=0;
  while true do
    begin
      t:=pos('+',s);
      if t=0 then break;
      sb:=copy(s,1,t-1);
      delete(s,1,t);
      lb:=length(sb);
      fillchar(b,sizeof(b),0);
      for i:=1 to lb do
        b[lb-i+1]:=ord(sb[i])-48;
      l:=max(l,lb);
      for i:=1 to l do
        begin
          a[i+1]:=a[i+1]+(a[i]+b[i])div 10;
          a[i]:=(a[i]+b[i])mod 10;
        end;
      if a[l+1]>0 then inc(l);
    end;
  lb:=length(s);
  fillchar(b,sizeof(b),0);
  for i:=1 to lb do
    b[lb-i+1]:=ord(s[i])-48;
  l:=max(l,lb);
  for i:=1 to l do
    begin
      a[i+1]:=a[i+1]+(a[i]+b[i])div 10;
      a[i]:=(a[i]+b[i])mod 10;
    end;
  if a[l+1]>0 then inc(l);
  for i:=l downto 1 do
    write(a[i]);
  writeln;
end.

