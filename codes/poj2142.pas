var
  flag:boolean;
  a,b,c,min,ans,x,y,x0,y0,d,t,i,ansx,ansy,j,k,m,n:longint;
  function ex_gcd(a,b:longint):longint;
    var
      t:longint;
    begin
      if b=0 then
        begin
          x:=1;
          y:=0;
          exit(a);
        end
      else
        begin
          ex_gcd:=ex_gcd(b,a mod b);
          t:=x;
          x:=y;
          y:=t-(a div b)*y;
        end;
    end;
begin
  readln(a,b,c);
  while not((a=0)and(b=0)and(c=0)) do
    begin
      flag:=false;
      if a<b then
        begin
          flag:=true;
          t:=a;
          a:=b;
          b:=t;
        end;
      d:=ex_gcd(a,b);
      //writeln('x=',x,'y=',y);
      k:=c div d;
      x0:=x*k;
      y0:=y*k;
      a:=a div d;
      b:=b div d;
      t:=y0 div a;
      //writeln('t=',t,' x0=',x0,' y0=',y0);
      ans:=maxlongint;
      for i:=t-1 to t+1 do
        begin
          x:=x0+i*b;
          y:=y0-i*a;
          if abs(x)+abs(y)<ans then
            begin
              //writeln('true');
              ans:=abs(x)+abs(y);
              ansx:=abs(x);
              ansy:=abs(y);
            end;
        end;
      if flag then
        writeln(ansy,' ',ansx)
      else
        writeln(ansx,' ',ansy);
      readln(A,b,c);
    end;
end.

