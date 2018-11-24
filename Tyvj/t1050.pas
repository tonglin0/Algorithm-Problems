var
   ch:char;
   sa,sb:ansistring;
   i,j,la,lb,k,t,m,n:longint;
   f:Array[0..3000,0..3000]of longint;
   function max(x,y:longint):longint;
     begin
       if x>=y then exit(x)
         else exit(y);
     end;
begin
  fillchar(f,sizeof(f),0);
  sa:='';
  ch:='1';
  while ch<>' ' do
    begin
      read(ch);
      sa:=sa+ch;
    end;
  readln(sb);
  m:=length(sa);
  n:=length(sb);
  for i:=1 to m do
    begin
      for j:=1 to n do
        if sa[i]=sb[j] then
          f[i,j]:=f[i-1,j-1]+1
        else
          f[i,j]:=max(f[i-1,j],f[i,j-1]);
    end;
  writeln(f[m,n]);
end.

