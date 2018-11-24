const
  pi=3.1416;
var
  time,s,tim,i,j:longint;
  dis,r,x,y:real;
begin
  //assign(input,'poj.in');assign(output,'poj.out');reset(input);rewrite(output);
  readln(time);
  for tim:=1 to time do
    begin
      readln(x,y);
      dis:=sqrt(sqr(x)+sqr(y));
      i:=0;
      s:=0;
      while true do
        begin
          inc(i);
          s:=s+50;
          r:=sqrt(2*s/pi);
          if r>dis then
            begin
              writeln('Property ',tim,': This property will begin eroding in year ',i,'.');
              break;
            end;
        end;
    end;
  write('END OF OUTPUT.');
  //close(input);close(output);
end.




