type
  node=record
    data,lc,rc,fa:longint;
  end;
var
  t:array[1..100000]of node;
  i,j,k,l,sum:longint;
  ch:char;
  flag,fu:boolean;
  procedure build(x:longint);
    var
      s,i,j:longint;
    begin
      while ch<>')' do
        begin
          if t[x].data=0 then
            begin
              read(ch);
              fu:=false;
              while (ch<>'-')and(ch<>'(')and(ch<>')')and(not((ch<='9')and(ch>='0')))do read(ch);
              if ch='-' then begin fu:=true;read(ch);end;
              s:=0;
              while (ch>='0')and(ch<='9') do
                begin
                  s:=s*10+ord(ch)-48;
                  read(ch);
                end;
              if fu then s:=-s;
              while (ch<>'-')and(ch<>'(')and(ch<>')')and(not((ch<='9')and(ch>='0')))do read(ch);
              if s=0 then
                begin
                  t[x].data:=-95;
                  exit;
                end;
              t[x].data:=s;
            end;
          if ch='(' then
            begin
              if t[x].lc=0 then
                begin
                  build(x*2);
                  t[2*x].fa:=x;
                  t[x].lc:=2*x;
                  read(ch);
                  while (ch<>'-')and(ch<>'(')and(ch<>')')and(not((ch<='9')and(ch>='0')))do read(ch);
                end
              else
                begin
                  build(x*2+1);
                  t[2*x+1].fa:=x;
                  t[x].rc:=2*x+1;
                  read(ch);
                  while (ch<>'-')and(ch<>'(')and(ch<>')')and(not((ch<='9')and(ch>='0')))do read(ch);
                end;
            end;
        end;
    end;
  procedure dfs(x:longint);
    var
      i,j:longint;
    begin
      sum:=sum+t[x].data;
      if (sum=k)and(t[t[x].lc].data=-95)and(t[t[x].rc].data=-95) then
        begin
          writeln('yes');
          flag:=true;
          exit;
        end;
      if (not flag)and(t[t[x].lc].data<>-95)then
        begin
          dfs(t[x].lc);
        end;
      if (not flag)and(t[t[x].rc].data<>-95) then
        dfs(t[x].rc);
      sum:=sum-t[x].data;
    end;
begin              {
  assign(input,'1145.in');
  assign(output,'1145.out');
  reset(input);
  rewrite(output);}
  while not eof do
    begin
      fillchar(t,sizeof(t),0);
      read(ch);
      fu:=false;
      while (ch<>'-')and(ch<>'(')and(ch<>')')and(not((ch<='9')and(ch>='0')))do read(ch);
      if ch='-' then begin fu:=true;read(ch);end;
      k:=0;
      while (ch>='0')and(ch<='9')do
        begin
          k:=k*10+ord(ch)-48;
          read(ch);
        end;
      if fu then k:=-k;
      while (ch<>'-')and(ch<>'(')and(ch<>')')and(not((ch<='9')and(ch>='0')))do read(ch);
      if ch='(' then begin build(1);end;
      flag:=false;
      sum:=0;
      if t[1].data<>-95 then
        dfs(1);
      if not flag then writeln('no');
      readln;
    end;         {
  close(input);
  close(output);}
end.
