const
  dx:array[1..4]of longint=(-1,0,1,0);
  dy:array[1..4]of longint=(0,1,0,-1);
  dm:array[1..4]of char=('n','e','s','w');
  dp:array[1..4]of char=('N','E','S','W');
type
  node=record
    me,fa,x,y,rx,ry:longint;
    s:ansistring;
  end;
var
  map:array[1..200,1..200]of longint;
  qm,qp:array[1..4000]of node;
  vm,vp:array[1..200,1..200]of boolean;
  movx,movy,n,m,tim,sx,sy,tx,ty,fm,rm,bx,by,f,r,mx,my,px,py:longint;
  canmove,cha,flag:boolean;
  str:ansistring;
  procedure init;
    var
      i,j:longint;
      ch:char;
    begin
      fillchar(map,sizeof(map),0);
      for i:=1 to n do
        begin
          for j:=1 to m do
            begin
              read(ch);
              case ch of
                '#':map[i,j]:=1;
                '.':map[i,j]:=0;
                'S':
                  begin
                    map[i,j]:=0;
                    sx:=i;
                    sy:=j;
                  end;
                'B':
                  begin
                    map[i,j]:=0;
                    bx:=i;
                    by:=j;
                  end;
                'T':
                  begin
                    map[i,j]:=0;
                    tx:=i;
                    ty:=j;
                  end;
              end;
            end;
          readln;
        end;
    end;
  procedure trymove;
    var
      i,j:longint;
    begin
      for i:=1 to m*n do
        begin
          qm[i].x:=0;
          qm[i].y:=0;
          qm[i].s:='';
          qm[i].rx:=0;
          qm[i].ry:=0;
        end;
      fillchar(vm,sizeof(vm),false);
      fm:=0;
      rm:=1;
      vm[qp[f].rx,qp[f].ry]:=true;
      qm[1].x:=qp[f].rx;
      qm[1].y:=qp[f].ry;
      str:='';
      while fm<rm do
        begin
          inc(fm);
          if (qm[fm].x=px)and(qm[fm].y=py) then
            begin
              canmove:=true;
              str:=qm[fm].s;
              //cha:=true;
              exit;
            end;
          for i:=1 to 4 do
            begin
              movx:=qm[fm].x+dx[i];
              movy:=qm[fm].y+dy[i];
              if(movx>=1)and(movy>=1)and(movx<=n)and(movy<=m)and(map[movx,movy]=0)and(not vm[movx,movy]) then
                begin
                  vm[movx,movy]:=true;
                  inc(rm);
                  qm[rm].x:=movx;
                  qm[rm].y:=movy;
                  qm[rm].s:=qm[fm].s+dm[i];
                end;
            end;
        end;
    end;
  procedure print;
    var
      i:longint;
    begin
      writeln('Maze #',tim);
      writeln(qp[f].s);
      writeln;
    end;
  procedure work;
    var
      i,j:longint;
    begin
      for i:=1 to n*m do
        begin
          qp[i].x:=0;
          qp[i].y:=0;
          qp[i].rx:=0;
          qp[i].ry:=0;
          qp[i].s:='';
        end;
      flag:=false;
      fillchar(vp,sizeof(vp),false);
      vp[bx,by]:=true;
      f:=0;
      r:=1;
      qp[1].x:=bx;
      qp[1].y:=by;
      qp[1].rx:=sx;
      qp[1].ry:=sy;
      while (f<r) do
        begin
          inc(f);                    {
          if f=24 then writeln(24); }
          map[qp[f].x,qp[f].y]:=1;
          if (qp[f].x=tx)and(qp[f].y=ty) then
            begin
              print;
              flag:=true;
              exit;
            end;
          for i:=1 to 4 do
            begin
              mx:=qp[f].x+dx[i];
              my:=qp[f].y+dy[i];                           {
              if f=24 then begin
                writeln(mx,' ',my,' ',vp[mx,my]);end;     }
              if(mx>=1)and(my>=1)and(mx<=n)and(my<=m)and(not vp[mx,my]) then
                begin
                  if map[mx,my]=1 then continue;
                  px:=qp[f].x-dx[i];
                  py:=qp[f].y-dy[i];
                  if (map[px,py]=1)or(px<1)or(py<1)or(px>n)or(py>m) then continue;
                  canmove:=false;
                  trymove;
                  if not canmove then continue;
                  vp[mx,my]:=true;
                  inc(r);
                  qp[r].x:=mx;
                  qp[r].y:=my;
                  qp[r].rx:=qp[f].x;
                  qp[r].ry:=qp[f].y;
                  qp[r].s:=qp[f].s+str+dp[i];
                  //writeln(f,' ',qp[f].x,' ',qp[f].y,'   ',r,' ',qp[r].x,' ',qp[r].y);
                end;
            end;
          //writeln(map[5,7]);
          map[qp[f].x,qp[f].y]:=0;
        end;
      writeln('Maze #',tim);
      writeln('Impossible.');
      writeln;
    end;
begin               {
  assign(input,'poj1475.in');
  assign(output,'poj1475.out');
  reset(input);
  rewrite(output); }
  tim:=0;
  readln(n,m);
  while n<>0 do
    begin
      inc(tim);
      init;
      work;{
      cha:=false;
      f:=1;
      qp[f].rx:=2;
      qp[f].ry:=4;
      px:=3;
      py:=5;}
      trymove;
      //writeln(cha);
      readln(n,m);
    end;          {
  close(input);
  close(output); }
end.

