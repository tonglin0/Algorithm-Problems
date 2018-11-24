type
  arr=array[0..1000]of longint;
  node=record
    a:arr;
    l:longint;
  end;
var
  f:Array[0..100,0..100]of node;
  i,j,k,m,n,t,la,lb,l:longint;
  a,b:node;
  s:ansistring;
  procedure chenga(var a,b:arr;var la,lb:longint);
    var
      x:arr;
      i,j,l:longint;
    begin
      //if la=0 then la:=1;
      //if lb=0 then lb:=1;
      l:=la+lb;
      fillchar(x,sizeof(x),0);
      for i:=1 to la do
        for j:=1 to lb do
          begin               {
            append(output);
            //writeln(i+j-1,' i+j-1');
            //writeln('i=',i,' j=',j);
            writeln(x[i+j-1],' x[i+j-1]');
            close(output);   }
            x[i+j-1]:=x[i+j-1]+a[i]*b[j];
          end;
      //writeln('l= ',l);
      while (l>1)and(x[l]=0) do
        dec(l);
      for i:=1 to l do
        begin
          x[i+1]:=x[i+1]+x[i] div 10;
          x[i]:=x[i] mod 10;
        end;
      if x[l+1]>0 then
        inc(l);
      while x[l]>=10 do
        begin
          x[l+1]:=x[l] div 10;
          x[l]:=x[l] mod 10;
          inc(l);
        end;
      a:=x;
      la:=l;
    end;
  procedure get(k:longint);
    var
      i,j,l:longint;
    begin
      f[k,0].l:=k;
      for i:=1 to k do
        f[k,0].a[i]:=ord(s[k-i+1])-48;
      while (f[k,0].a[f[k,0].l]=0)and(f[k,0].l>1) do
        dec(f[k,0].l);
      for i:=1 to f[k,0].l do
        if f[k,0].a[i]<>0 then
          exit;
      //f[k,0].l:=1;
    end;
  procedure getnum(l,r:longint);
    var
      i,j:longint;
    begin
      b.l:=r-l+1;
      for i:=1 to b.l do
        b.a[i]:=ord(s[r-i+1])-48;
      while (b.a[b.l]=0)and(b.l>1) do
        dec(b.l);
      for i:=1 to b.l do
        if b.a[i]<>0 then exit;
      //b.l:=1;
    end;
  function dayu(var a,b:Arr;var la,lb:longint):boolean;
    var
      i,j,l:longint;
    begin
      if la>lb then exiT(true);
      if la<lb then exit(false);
      for i:=la downto 1 do
        if a[i]>b[i] then
          exit(true)
        else if b[i]>a[i] then
          exit(false);
      exit(false);
    end;
begin
  //assign(input,'1047.in');reset(input);assign(output,'1047.out');rewrite(output);
  fillchar(f,sizeof(f),0);
  readln(n,m);
  readln(s);
  for i:=1 to n do
    get(i);{
  for i:=1 to n do
    begin
      for j:=f[i,0].l downto 1 do
        write(f[i,0].a[j]);
      writeln;
    end;
  halt;}

  for j:=1 to m do
    for i:=j+1 to n-m+j do
      begin
        for k:=j to i-1 do
          begin
            fillchar(a,sizeof(A),0);
            fillchar(b,sizeof(b),0);
            getnum(k+1,i);    {
            write('from ',k+1,' to ',i,':');
            for la:=b.l downto 1 do
              write(b.a[la]);
            write('   l=',b.l);
            writeln;         }

            a.a:=f[k,j-1].a;
            a.l:=f[k,j-1].l;
            chenga(a.a,b.a,a.l,b.l);
            if dayu(a.a,f[i,j].a,a.l,f[i,j].l) then
              begin
                f[i,j].a:=a.a;
                f[i,j].l:=a.l;
              end;
          end;
      end;
  for i:=f[n,m].l downto 1 do
    write(f[n,m].a[i]);
  writeln;
  close(input);close(output);
end.
