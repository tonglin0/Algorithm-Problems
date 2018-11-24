var
  a,b,c:array[1..20001]of longint;
  sa,sb:ansistring;
  i,j,k,n,m,la,lb,l:longint;
begin
  fillchar(a,sizeof(A),0);
  fillchar(b,sizeof(B),0);
  fillchar(c,sizeof(c),0);
  readln(sa);
  readln(sb);
  if (sa='0') or (sb='0') then
    begin
      writeln(0);
      halt;
    end;
  la:=length(sa);
  for i:=1 to la do
    a[i]:=ord(sa[la-i+1])-48;
  lb:=length(sb);
  for i:=1 to lb do
    b[i]:=ord(sb[lb-i+1])-48;
  l:=la+lb;
  for i:=1 to la do
    for j:=1 to lb do
      c[i+j-1]:=c[i+j-1]+a[i]*b[j];
  for i:=1 to l do
    begin
      c[i+1]:=c[i+1]+c[i] div 10;
      c[i]:=c[i] mod 10;
    end;
  while (l>1)and(c[l]=0) do
    dec(l);
  for i:=l downto 1 do
    write(c[i]);
end.


