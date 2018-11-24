var
  a:array[97..122]of longint;
  max,min,i,j,k,m,n,l:longint;
  s:string;
  function pr(n:longint):boolean;
    var
      i,j:longint;
    begin
      if n=1 then exit(false);
      if n=2 then exit(true);
      if n=0 then exit(false);
      m:=trunc(sqrt(n));
      for i:=2 to m do
        if n mod i=0 then exit(false);
      exit(true);
    end;
begin
  fillchar(a,sizeof(a),0);
  readln(s);
  l:=length(s);
  for i:=1 to l do
    inc(a[ord(s[i])]);
  max:=-1;
  min:=maxlongint;
  for i:=97 to 122 do
    begin
      if a[i]>max then max:=a[i];
      if (a[i]<min)and(a[i]>0) then min:=a[i];
    end;
  k:=0;
  if pr(max-min) then
    begin
      writeln('Lucky Word');
      k:=max-min;
    end
  else writeln('No Answer');
  writeln(k);
end.



