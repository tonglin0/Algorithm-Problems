type
  arr=array[0..1000]of byte;
  node=record
    a:arr;
    l:longint;
  end;
var
  f:array[0..80,0..80]of node;
  v:array[0..80,0..80]of boolean;
  a:array[0..80,0..80]of node;
  d:array[0..80]of node;
  p:array[0..80,0..80]of longint;
  ans,b,aa,bb:node;
  la,lb,l,ii,jj,lans,ld,i,j,k,m,n,s,lf,t,c:longint;
  function max(x,y:longint):longint;
    begin
      if x>y then exit(x);
      exit(y);
    end;
  function chengc(a:Arr;la,d:longint):arr;
    var
      i,j,k:longint;
    begin
      for i:=1 to la do
        a[i]:=a[i]*d;
      for i:=1 to la do
        if a[i]>=10 then
          begin
            a[i+1]:=a[i+1]+a[i] div 10;
            a[i]:=a[i] mod 10;
          end;
      if a[la+1]>0 then inc(la);
      while a[la]>=10 do
        begin
          a[la+1]:=a[la] div 10;
          a[la]:=a[la] mod 10;
          inc(la);
        end;
      l:=la;
      exit(a);
    end;
  procedure chenga(var a,b:arr;var la,lb:longint);
    var
      x:arr;
      i,j,l:longint;
    begin
      fillchar(x,sizeof(x),0);
      for i:=1 to la do
        for j:=1 to lb do
          x[i+j-1]:=x[i+j-1]+a[i]*b[j];
      l:=la+lb;
      while (l>1)and(x[l]=0) do
        dec(l);
      for i:=1 to l do
        if x[i]>=10 then
          begin
            x[i+1]:=x[i+1]+x[i] div 10;
            x[i]:=x[i] mod 10;
          end;
      if x[l+1]>0 then inc(l);
      while x[l]>=10 do
        begin
          x[l+1]:=x[l] div 10;
          x[l]:=x[l] mod 10;
          inc(l);
        end;
      a:=x;
      la:=l;
    end;
  procedure jia(var a,b:arr;var la,lb:longint);
    var
      x:arr;
      i,j,l:longint;
    begin
      fillchar(x,sizeof(x),0);
      l:=max(la,lb);
      for i:=1 to l do
        x[i]:=a[i]+b[i];
      for i:=1 to l do
        begin
          x[i+1]:=x[i+1]+x[i] div 10;
          x[i]:=x[i] mod 10;
        end;
      if x[l+1]>0 then
        inc(l);
      a:=x;
      la:=l;
    end;
  function dayu(var a,b:arr;var la,lb:longint):boolean;
    var
      i,j:longint;
    begin
      if la>lb then exit(true);
      if la<lb then exit(false);
      for i:=la downto 1 do
        if a[i]>b[i] then
          exit(true)
        else if b[i]>a[i] then
          exit(false);
      exit(false);
    end;
begin
  //assign(input,'1054.in');reset(input);
  fillchar(f,sizeof(f),0);
  fillchar(a,sizeof(a),0);
  fillchar(d,sizeof(d),0);
  fillchar(ans,sizeof(ans),0);
  fillchar(p,sizeof(p),0);
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
      read(p[i,j]);
  d[1].a[1]:=2;
  d[1].l:=1;
  for i:=2 to m do
    begin
      d[i].a:=chengc(d[i-1].a,d[i-1].l,2);
      d[i].l:=l;
    end;               {
  for i:=1 to m do
    begin
      for j:=d[i].l downto 1 do
        write(d[i].a[j]);
      writeln;
    end;
  halt;               }


  ans.l:=0;
  for i:=1 to n do
    for j:=1 to m do
      begin
        a[i,j].l:=0;
        if p[i,j]=0 then
          begin
            a[i,j].l:=1;
            continue;
          end;
        while p[i,j]>0 do
          begin
            inc(a[i,j].l);
            a[i,j].a[a[i,j].l]:=p[i,j] mod 10;
            p[i,j]:=p[i,j] div 10;
          end;
      end;   {
  for i:=1 to n do
    for j:=1 to m do
      begin
        for k:=a[i,j].l downto 1 do
          write(a[i,j].a[k]);
        write(' ');
      end;
  halt;     }

  for ii:=1 to n do
    begin
      //fillchar(v,sizeof(v),false);
      fillchar(f,sizeof(f),0);
      for i:=1 to m do
        begin
          //f[i,1].a:=a[ii,i].a;
          f[i,0].l:=1;
        end;
        for j:=1 to m do
          for i:=1 to m-j+1 do
            begin
              c:=m-j+1;
              fillchar(aa,sizeof(aa),0);
              fillchar(bb,sizeof(bb),0);
              aa.a:=a[ii,i+j-1].a;
              aa.l:=a[ii,i+j-1].l;
              chenga(aa.a,d[c].a,aa.l,d[c].l);
              jia(aa.a,f[i,j-1].a,aa.l,f[i,j-1].l);
              bb.a:=a[ii,i].a;
              bb.l:=a[ii,i].l;
              chenga(bb.a,d[c].a,bb.l,d[c].l);
              jia(bb.a,f[i+1,j-1].a,bb.l,f[i+1,j-1].l);
              if dayu(aa.a,bb.a,aa.l,bb.l) then
                begin
                  f[i,j].a:=aa.a;
                  f[i,j].l:=aa.l;
                end
              else
                begin
                  f[i,j].a:=bb.a;
                  f[i,j].l:=bb.l;
                end;
            end;
      jia(ans.a,f[1,m].a,ans.l,f[1,m].l);
    end;
  for i:=ans.l downto 1 do
    write(ans.a[i]);
  writeln;
end.

