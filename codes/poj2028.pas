var
  v:array[0..51,0..101]of boolean;
  a:Array[0..101]of longint;
  i,j,k,m,n,s,q,ans:longint;
begin
  //assign(input,'2028.in');reset(input);
  readln(n,q);
  while not((n=0)and(q=0)) do
    begin
      fillchar(v,sizeof(v),false);
      fillchar(a,sizeof(a),0);
      ans:=0;
      s:=0;
      for i:=1 to n do
        begin
          read(m);
          for j:=1 to m do
            begin
              read(k);
              v[i,k]:=true;
            end;
        end;
      for i:=1 to n do
        for j:=0 to 100 do
          if v[i,j] then
            inc(a[j]);
      for i:=0 to 100 do
        if a[i]>s then
          begin
            ans:=i;
            s:=a[i];
          end;
      if s>=q then
        writeln(ans)
      else
        writeln(0);
      readln(n,q);
    end;
end.

