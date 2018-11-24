var
  st,nu:array[1..10000]of longint;
  n,i,j,k,s,ta,tb:longint;
  flag:boolean;
  procedure init;
    var
      i,j:longint;
    begin
      fillchar(st,sizeof(st),0);
      fillchar(nu,sizeof(nu),0);
      nu[1]:=k;
      for i:=2 to n do
        read(nu[i]);
      nu[n+1]:=maxint;
    end;
  procedure pop;
    begin
      dec(ta);
      inc(tb);
    end;
begin               {
  assign(input,'1363.in');
  assign(output,'1363.out');
  reset(input);
  rewrite(output);   }
  readln(n);
  while n<>0 do
    begin
      read(k);
      while k<>0 do
        begin
          {if k=0 then
            begin
              writeln;
              readln;
              break;
            end;  }
          init;
          ta:=0;
          tb:=1;
          s:=1;
          while (ta>=0)and(s<=n)and(tb<=n)and(st[ta]<nu[tb])do
            begin
              inc(ta);
              st[ta]:=s;
              inc(s);
              while(ta>0)and(tb<=n)and(st[ta]=nu[tb]) do
                if ta>0 then pop;
            end;
          if (s=n+1)and(ta=0)and(tb=n+1) then
            writeln('Yes')
          else writeln('No');
          read(k);
        end;
      writeln;
      readln;
      readln(n);
      if n=0 then halt;
    end;           {
  close(input);
  close(output);  }
end.
