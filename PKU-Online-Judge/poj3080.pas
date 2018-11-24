var
  s:array[1..10]of string;
  time,tim,max,i,j,k,n,maxl:integer;
  ans,st:string;
  flag:boolean;
begin                                              {
  assign(input,'3080.in');
  assign(output,'3080.out');
  reset(input);
  rewrite(output);                                }
  readln(time);
  for tim:=1 to time do
    begin
      readln(n);
      for i:=1 to n do
        readln(s[i]);
      max:=2;
      maxl:=1;
      ans:='';
      for i:=1 to 60 do
        begin
          for j:=max to 60-i+1 do
            begin
              st:=copy(s[1],i,j);
              flag:=true;
              for k:=2 to n do
                begin
                  if pos(st,s[k])=0 then
                    begin
                      flag:=false;
                      break;
                    end;
                end;
              if not flag then break;
              if j=maxl then
                begin
                  if st<ans then ans:=st;
                end
              else
                begin
                  maxl:=j;
                  ans:=st;
                end;
            end;
          if maxl>1 then max:=maxl;
        end;
      if max<3 then
        writeln('no significant commonalities')
      else
        writeln(ans);
    end;                                         {
  close(input);
  close(output);                                }
end.


