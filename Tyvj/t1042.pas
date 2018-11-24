var
  s,sa,sb,sc:string;
  i,j,n,a,b,c,k,l,m,la,lb,lc,t:longint;
  function getf(var i:longint):longint;
    begin
      sa:='';
      while (i>=1)and(s[i]>='0')and(s[i]<='9')do
        begin
          sa:=s[i]+sa;
          dec(i);
        end;
      val(sa,a);
      exit(a);
    end;
  function getb(var j:longint):longint;
    begin
      sb:='';
      while (j<=l)and(s[j]>='0')and(s[j]<='9') do
        begin
          sb:=sb+s[j];
          inc(j);
        end;
      val(sb,b);
      exit(b);
    end;
begin
  readln(s);
  t:=pos('^',s);
  while t<>0 do
    begin
      i:=t-1;
      sa:='';
      sb:='';
      while (i>=1)and(s[i]>='0')and(s[i]<='9')do
        begin
          sa:=s[i]+sa;
          dec(i);
        end;
      val(sa,a);
      j:=t+1;
      l:=length(s);
      while (j<=l)and(s[j]>='0')and(s[j]<='9') do
        begin
          sb:=sb+s[j];
          inc(j);
        end;
      val(sb,b);
      m:=a;
      for k:=1 to b-1 do
        m:=m*a;
      delete(s,i+1,j-i-1);
      str(m,sa);
      insert(sa,s,i+1);
      t:=pos('^',s);
    end;
  l:=length(s);
  i:=1;
  while i<l do
    begin
      inc(i);
      if (s[i]='/')or(s[i]='*') then
        begin
          j:=i+1;
          k:=i-1;
          a:=getf(k);
          b:=getb(j);
          if s[i]='/' then
            m:=a div b
          else m:=a*b;
          str(m,sa);
          delete(s,k+1,j-k-1);
          insert(sa,s,k+1);
          i:=k+1;
          l:=length(s);
        end;
    end;
  i:=1;
  l:=length(s);
  while i<l do
    begin
      inc(i);
      if (s[i]='+')or(s[i]='-') then
        begin
          j:=i+1;
          k:=i-1;
          a:=getf(k);
          b:=getb(j);
          if s[i]='+' then m:=a+b
          else m:=a-b;
          str(m,sa);
          delete(s,k+1,j-k-1);
          insert(sa,s,k+1);
          i:=k+1;
          l:=length(s);
        end;
    end;
  writeln(s);
end.

