var
  a:array[-800..800,-800..800]of byte;
  i,j,ii,jj,k,n,m,s,sx,sy,hx,hy,ex,ey,gx,gy,x,y:longint;
  procedure check(a,b:longint);
    begin
      if a<sx then sx:=a;
      if a>ex then ex:=a;
      if b<sy then sy:=b;
      if b>ey then ey:=b;
    end;
  procedure dr(x,y:longint);
    var
      i,j,k:longint;
    begin
      a[x,y]:=ord('+');
      for i:=1 to 3 do
        a[x,y+i]:=ord('-');
      a[x,y+4]:=ord('+');
      a[x-1,y]:=124;
      a[x-2,y]:=124;
      a[x-3,y]:=ord('+');
      for i:=1 to 3 do
        a[x-3,y+i]:=ord('-');
      a[x-3,y+4]:=ord('+');
      for i:=x-2 to x-1 do
        for j:=y+1 to y+3 do
          a[i,j]:=ord(' ');
      a[x-1,y+4]:=124;
      a[x-2,y+4]:=124;
      a[x-4,y+1]:=ord('/');
      a[x-4,y+5]:=ord('/');
      a[x-1,y+5]:=ord('/');
      a[x-2,y+6]:=ord('+');
      a[x-3,y+6]:=124;
      a[x-4,y+6]:=124;
      a[x-5,y+2]:=ord('+');
      a[x-5,y+6]:=ord('+');
      for i:=y+3 to y+5 do
        a[x-5,i]:=ord('-');
      for i:=y+2 to y+4 do
        a[x-4,i]:=ord(' ');
      for i:=x-3 to x-2 do
        a[i,y+5]:=ord(' ');
    end;
begin
  //assign(output,'1.out');
  //rewrite(output);
  fillchar(a,sizeof(a),0);
  readln(m,n);
  sx:=1;
  sy:=1;
  ex:=1;
  ey:=1;
  hx:=-1;
  hy:=3;
  gx:=1;
  gy:=1;
  for ii:=1 to m do
    begin
      hx:=hx+2;
      hy:=hy-2;
      check(hx,hy);
      gx:=hx;
      gy:=hy;
      for jj:=1 to n do
        begin
          read(k);
          x:=gx;
          y:=gy;
          check(x,y);
          for i:=1 to k do
            begin
              dr(x,y);
              check(x-5,y+6);
              x:=x-3;
            end;
          gy:=gy+4;
          check(gx,gy);
        end;
      readln;
    end;
  for i:=sx to ex do
    begin
      for j:=sy to ey do
        if a[i,j]=0 then
          write('.')
        else write(chr(a[i,j]));
      writeln;
    end;
  //close(output);
end.



