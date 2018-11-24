type
  node=record
    x,y:longint;
    str:string;
    row:longint;
  end;
  nod=record
    nu:longint;
    sum:longint;
  end;
var
  q:array[1..2000]of node;
  num:array[1..200,1..200]of nod;
  p:array[1..300]of string;
  map:array[1..300,1..300]of longint;
  time,ti,l,n,m,i,j,k,t,ii,jj,lie,f,r:longint;
  ch:char;
  flag:boolean;
  s:string;
begin            {
  assign(input,'1420.in');
  assign(output,'1420.out');
  reset(input);
  rewrite(output);}
  readln(time);
  for ti:=1 to time do
    begin
      readln(m,n);
      fillchar(p,sizeof(p),0);
      fillchar(num,sizeof(num),0);
      for i:=1 to n do
        for j:=1 to m do
          map[i,j]:=-1;
      fillchar(q,sizeof(q),0);
      s:='A';
      for i:=1 to m do
        begin
          p[i]:=s;
          l:=length(s);
          if ord(s[l])<>90 then
            begin
              s[l]:=chr(ord(s[l])+1);
              continue;
            end;
          if (l=1)and(ord(s[l])=90) then
            begin
              s:='AA';
              continue;
            end;
          if l<>1 then
            begin
              k:=l;
              while (l>=1)and(s[l]='Z') do
                dec(l);
              if l=0 then
                begin
                  inc(k);
                  s:='';
                  for jj:=1 to k do
                    s:=s+'A';
                  continue;
                end;
              s[l]:=chr(ord(s[l])+1);
              for jj:=k downto l+1 do
                s[jj]:='A';
            end;
        end;
      f:=0;
      r:=0;
      read(ch);
      for i:=1 to n do
        begin
          while (ch<>'=')and((ch>'9')or(ch<'0'))do read(ch);
          j:=0;
          //while ((ch>='A')and(ch>='Z'))or(ch=' ')or(ch='=')or(ch='+')or((ch>='0')and(ch<='9')) do
          while j<m do
            begin
              inc(j);
              if ch<>'=' then
                begin
                  k:=0;
                  while (ch<='9')and(ch>='0') do
                    begin
                      k:=k*10+ord(ch)-48;
                      read(ch);
                    end;
                  map[i,j]:=k;
                  if (i<>n)or(j<>m) then
                    while (ch<>'=')and((ch>'9')or(ch<'0'))do read(ch);
                  continue;
                end;
              ch:='+';
              while ch='+' do
                begin
                  read(ch);
                  s:='';
                  while (ch<='Z')and(ch>='A') do
                    begin
                      s:=s+ch;
                      read(ch);
                    end;
                  for ii:=1 to m do
                    if s=p[ii] then
                      begin
                        lie:=ii;
                        break;
                      end;
                  k:=0;
                  while (ch>='0')and(ch<='9')do
                    begin
                      k:=k*10+ord(ch)-48;
                      read(ch);
                    end;
                  flag:=true;
                  if map[k,lie]=-1 then
                    begin
                      flag:=false;
                      inc(r);
                      inc(num[i,j].nu);
                      q[r].x:=i;
                      q[r].y:=j;
                      q[r].str:=s;
                      q[r].row:=k;
                    end;
                  if flag then
                    begin
                      //if map[i,j]=-1 then map[i,j]:=0;
                      inc(num[i,j].sum,map[k,lie]);
                    end;
                  if (ch<>'+')and((i<>n)or(j<>m)) then
                    while (ch<>'=')and((ch>'9')or(ch<'0')) do read(ch);
                end;
            end;
        end;           {
      for i:=1 to r do
        writeln(q[i].x,' ',q[i].y,' ',q[i].row,' ',q[i].str);
      for i:=1 to n do
        begin
        for j:=1 to m do
          write(num[i,j].nu,' ');
        writeln;
        end;
      halt;             }
      for i:=1 to n do
        for j:=1 to m do
          begin
            if (map[i,j]=-1)and(num[i,j].nu=0) then
              map[i,j]:=num[i,j].sum;
          end;
      while f<r do
        begin
          inc(f);
          with q[f] do
            begin
              if map[x,y]<>-1 then
                begin
                  continue;
                end;
              flag:=false;
              for i:=1 to m do
                if (p[i]=str)and(map[row,i]<>-1) then
                  begin
                    inc(num[x,y].sum,map[row,i]);
                    dec(num[x,y].nu);
                    flag:=true;
                    if num[x,y].nu=0 then
                      begin
                        if map[x,y]=-1 then map[x,y]:=0;
                        inc(map[x,y],num[x,y].sum);
                      end;
                    break;
                  end;
              if not flag then
                begin
                  inc(r);
                  q[r]:=q[f];
                end;
            end;
        end;
      for i:=1 to n do
        begin
          for j:=1 to m-1 do
            write(map[i,j],' ');
          writeln(map[i,m]);
        end;
    end;            {
  close(input);
  close(output);   }
end.

