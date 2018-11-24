var
  a,b,c,i,m,n,j,t,l:longint;
  s,sa:ansistring;
  flag:boolean;
  function fan(s:ansistring):ansistring;
    var
      ss:ansistring;
      l:longint;
    begin
      ss:='';
      l:=length(s);
      for i:=l downto 1 do
        ss:=ss+s[i];
      exit(ss);
    end;
begin
  //assign(input,'1053.in');assign(output,'1053.out');
  reset(input);rewrite(output);
  readln(a,b,c);
  readln(sa);
  t:=pos('--',sa);
  while t<>0 do
    begin
      delete(sa,t,2);
      insert('????',sa,t);
      t:=pos('--',sa);
    end;
  if sa[1]='-' then
    begin
      write('-');
      delete(sa,1,1);
    end;
  l:=length(sa);
  flag:=false;
  if sa[l]='-' then
    begin
      flag:=true;
      delete(sa,l,1);
    end;
  t:=pos('-',sa);
  while t<>0 do
    begin
      s:='';
      if (abs(ord(sa[t+1])-ord(sa[t-1]))>26)or(ord(sa[t+1])-ord(sa[t-1])<=0) then
        begin
          delete(sa,t,1);
          insert('!',sa,t);
          t:=pos('-',sa);
          continue;
        end;
      if ord(sa[t+1])-ord(sa[t-1])=1 then
        begin
          delete(sa,t,1);
          t:=pos('-',sa);
          continue;
        end;
      if sa[t-1]<='9' then
        begin
          m:=ord(sa[t+1])-ord(sa[t-1])-1;
          if a=3 then
            begin
              for i:=1 to m do
                for j:=1 to b do
                  s:=s+'*';
              delete(sa,t,1);
              insert(s,sa,t);
              t:=pos('-',sa);
              continue;
            end
          else
            begin
              for i:=1 to m do
                for j:=1 to b do
                  s:=s+chr(ord(sa[t-1])+i);
              if c=2 then s:=fan(s);
              delete(sa,t,1);
              insert(s,sa,t);
              t:=pos('-',sa);
              continue;
            end;
        end;
      m:=ord(sa[t+1])-ord(sa[t-1])-1;
        if a=3 then
          begin
            for i:=1 to m do
              for j:=1 to b do
                s:=s+'*';
            delete(sa,t,1);
            insert(s,sa,t);
            t:=pos('-',sa);
            continue;
          end
        else if a=1 then
          begin
            for i:=1 to m do
              for j:=1 to b do
                s:=s+chr(ord(sa[t-1])+i);
            if c=2 then s:=fan(s);
            delete(sa,t,1);
            insert(s,sa,t);
            t:=pos('-',sa);
            continue;
          end
        else if a=2 then
          begin
            for i:=1 to m do
              for j:=1 to b do
                s:=s+chr(ord(sa[t-1])+i-32);
            if c=2 then s:=fan(s);
            delete(sa,t,1);
            insert(s,sa,t);
            t:=pos('-',sa);
            continue;
          end;
    end;
  t:=pos('!',sa);
  while t<>0 do
    begin
      delete(sa,t,1);
      insert('-',sa,t);
      t:=pos('!',sa);
    end;

    t:=pos('????',sa);
  while t<>0 do
    begin
      delete(sa,t,4);
      insert('--',sa,t);
      t:=pos('????',sa);
    end;
    write(sa);
  if flag then write('-');

  //close(input);close(output);
end.


