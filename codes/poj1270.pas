var
  into:array[97..122]of longint;
  map:array[97..122,97..122]of boolean;
  men:array[97..122]of boolean;
  v:array[97..122]of boolean;
  ans:array[1..21]of longint;
  ch:char;
  s,i,j,k,m,n,top:longint;
  flag:boolean;
  procedure dfs(k:longint);
    var
      i,j:longint;
    begin
      for i:=97 to 122 do
        if (not v[i])and(men[i])and(into[i]=0) then
          begin
            ans[k]:=i;
            if k=s then
              begin
                for j:=1 to s do
                  write(chr(ans[j]));
                writeln;
                exit;
              end;
            v[i]:=true;
            for j:=97 to 122 do
              if map[i,j] then dec(into[j]);
            dfs(k+1);
            v[i]:=false;
            for j:=97 to 122 do
              if map[i,j] then inc(into[j]);
          end;
    end;
begin               {
  assign(input,'1270.in');
  assign(output,'1270.out');
  reset(input);
  rewrite(output);   }
  flag:=false;
  while not eof do
    begin
      fillchar(map,sizeof(map),false);
      fillchar(men,sizeof(men),false);
      fillchar(v,sizeof(v),false);
      fillchar(into,sizeof(into),0);
      s:=0;
      repeat
          if not flag then read(ch);
          if flag then flag:=false;
          inc(s);
          men[ord(ch)]:=true;
          read(ch);
      until ch<>' ';
      read(ch);
      repeat
        read(ch);
        m:=ord(ch);
        read(ch);
        read(ch);
        n:=ord(ch);
        map[m,n]:=true;
        inc(into[n]);
        read(ch);
      until ch<>' ';
      while (not eof)and((ch>'v')or(ch<'a'))do begin flag:=true;read(ch);end;
      dfs(1);
      writeln;
    end;           {
  close(input);
  close(output);  }
end.


