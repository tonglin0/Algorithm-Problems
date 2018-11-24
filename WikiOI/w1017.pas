var
  f:Array[0..100,0..100]of qword;
  i,j,k,m,n,t:longint;
  s:ansistring;
  function get(l,r:qword):qword;
    var
      i:longint;
      ans:qword;
    begin
      ans:=0;
      for i:=l to r do
        ans:=ans*10+ord(s[i])-48;
      exit(ans);
    end;
  function max(x,y:qword):qword;
    begin
      if x>y then exit(x);
      exit(y);
    end;
begin
  assign(input,'1047.in');reset(input);
  fillchar(f,sizeof(f),0);
  readln(n,m);
  readln(s);
  for i:=1 to n do
    f[i,0]:=get(1,i);
  for j:=1 to m do
    for i:=j+1 to n-m+j do
      begin
        for k:=j to i-1 do
          f[i,j]:=max(f[i,j],f[k,j-1]*get(k+1,i));
      end;
  writeln(f[n,m]);
end.