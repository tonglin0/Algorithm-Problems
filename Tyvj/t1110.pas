var
  c:array[65..90]of char;
  vv,v:array[65..90]of boolean;
  s,sa,sb:string;
  i,j,l,la,n,m:longint;
begin
  for i:=65 to 90 do
    c[i]:=' ';
  fillchar(v,sizeof(v),false);
  readln(sa);
  readln(sb);
  readln(s);
  la:=length(sa);
  for i:=1 to la do
    begin
      v[ord(sa[i])]:=true;
      if (c[ord(sa[i])]<>' ')and(c[ord(sa[i])]<>sb[i]) then
        begin
          writeln('Failed');
          halt;
        end;
      c[ord(sa[i])]:=sb[i];
    end;
  fillchar(vv,sizeof(vv),false);
  for i:=65 to 90 do
    if vv[ord(c[i])] then
      begin
        writeln('Failed');
        halt;
      end
    else vv[ord(c[i])]:=true;
  for i:=65 to 90 do
    if not v[i] then
      begin
        writeln('Failed');
        halt;
      end;
  l:=length(s);
  for i:=1 to l do
    write(c[ord(s[i])]);
  writeln;
end.


