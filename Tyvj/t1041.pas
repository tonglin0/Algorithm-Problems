var
  t,i,j,k,m,n,l,la,lb:longint;
  a,b:array[1..256]of longint;
  s,sa,sb:string;
  ch:char;
  function max(x,y:longint):longint;
    begin
      if x>=y then exit(x);
      exit(y);
    end;
  procedure add;
    var
      i,j,k:longint;
    begin
      fillchar(b,sizeof(b),0);
      sb:=sa;
      lb:=length(sb);
      for i:=1 to lb do
        b[lb-i+1]:=ord(sb[i])-48;
      la:=max(la,lb);
      for i:=1 to la do
        begin
          a[i+1]:=a[i+1]+(a[i]+b[i])div 10;
          a[i]:=(a[i]+b[i])mod 10;
        end;
      if a[la+1]>0 then inc(la);
    end;
  procedure jian;
    var
      i,j:longint;
    begin
      fillchar(b,sizeof(b),0);
      sb:=sa;
      lb:=length(sb);
      for i:=1 to lb do
        b[lb-i+1]:=ord(sb[i])-48;
      for i:=1 to la do
        begin
          if a[i]<b[i] then
            begin
              a[i]:=a[i]+10;
              dec(a[i+1]);
            end;
          a[i]:=a[i]-b[i];
        end;
      while (la>1)and(a[la]=0)do
        dec(la);
    end;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  readln(s);
  l:=length(s);
  t:=pos('+',s);
  if t=0 then t:=pos('-',s);
  if t=0 then begin writeln(s);halt;end;
  sa:='';
  sb:='';
  la:=0;
  lb:=0;
  while true do
    begin
      if (s[1]='+')or(s[1]='-') then
        break;
      sa:=sa+s[1];
      delete(s,1,1);
    end;
  la:=length(sa);
  for i:=1 to la do
    a[la-i+1]:=ord(sa[i])-48;
  ch:=' ';
  l:=length(s);
  for i:=1 to l do
    begin
      if (s[i]<>'+')and(s[i]<>'-') then
        begin
          sa:=sa+s[i];
        end;
      if s[i]='+' then
        begin
          if ch='+' then add
            else if ch='-' then jian;
          ch:='+';
          sa:='';
        end;
      if s[i]='-' then
        begin
          if ch='+' then add
            else if ch='-' then jian;
          ch:='-';
          sa:='';
        end;
    end;
  if ch='+' then add
    else if ch='-' then jian;
  for i:=la downto 1 do
    write(a[i]);
end.
