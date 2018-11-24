var
  f:array[0..41,0..6]of qword;
  v:array[0..41,0..6]of boolean;
  s:string;
  ans:qword;
  i,j,k,n,m:longint;
  function get(x,y:longint):qword;
    var
      i,j:longint;
      ans:qword;
    begin
      ans:=0;
      for i:=x to y do
        ans:=ans*10+ord(s[i])-48;
      exit(ans);
    end;
  function max(x,y:qword):qword;
    begin
      if x>y then exit(x);
      exit(y);
    end;
  function find(i,j:longint):qword;
    var
      k:longint;
    begin
      if v[i,j] then exit(f[i,j]);
      v[i,j]:=true;
      if j=0 then
        begin
          f[i,j]:=get(1,i);
          exit(f[i,j]);
        end;
      for k:=j to i-1 do
        f[i,j]:=max(f[i,j],find(k,j-1)*get(k+1,i));
      //exit(f[i,j]);
      find:=f[i,j];
    end;
begin
  assign(input,'1047.in');reset(input);
  for i:=0 to 41 do
    for j:=0 to 6 do
      f[i,j]:=0;
  fillchar(v,sizeof(v),false);
  readln(m,n);
  readln(s);
  ans:=find(m,n);
  writeln(ans);
end.


