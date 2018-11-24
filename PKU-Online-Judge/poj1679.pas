type
  node=record
    po,si,nu:longint;
  end;
var
  map:array[0..80,0..80]of node;
  dis:array[1..6561,1..6561]of longint;
  p,m,i,j,sx,k,sy,tx,ty,c,a,b,s,t:longint;
  procedure init;
    var
      i,j:longint;
      ch:char;
    begin
      fillchar(map,sizeof(map),0);
      fillchar(dis,sizeof(dis),127);
      readln(a,b);
      readln(sx,sy,tx,ty);
      k:=0;
      for i:=0 to a-1 do
        begin
          for j:=0 to b-1 do
            begin
              inc(k);
              read(ch);
              map[i,j].si:=ord(ch)-48;
              //writeln(map[i,j].si);
              //halt;
              if (i=sx)and(j=sy) then s:=k;
              if (i=tx)and(j=ty) then t:=k;
              map[i,j].nu:=k;
            end;
          inc(k);
          if (i=sx)and(b=sy) then s:=k;
          if (i=tx)and(b=ty) then t:=k;
          map[i,b].nu:=k;
          map[i,b].si:=1;
          readln;
        end;
      for i:=0 to b do
        begin
          inc(k);
          if (a=sx)and(i=sy) then s:=k;
          if (a=tx)and(i=ty) then t:=k;
          map[a,i].nu:=k;
          map[a,i].si:=1;
        end;
    end;
  function find(x,y:longint):longint;
    var
      q:array[0..6561,1..3]of longint;
      mx,my,i,j,r,f:longint;
    begin
      fillchar(q,sizeof(q),0);
      f:=0;
      r:=1;
      q[1,1]:=x;
      q[1,2]:=y;
      q[1,3]:=0;
      while f<r do
        begin
          inc(f);
          if map[q[f,1],q[f,2]].si=1 then exit(q[f,3]);
          mx:=q[f,1]-1;
          my:=q[f,2]-1;
          if (mx>=0)and(my>=0) then
            begin
              if map[mx,my].si=1 then exit(q[f,3]);
            end;
          mx:=q[f,1];
          my:=q[f,2]-1;
          if (mx>=0)and(my>=0) then
            begin
              if map[mx,my].si=1 then exit(q[f,3]);
              inc(r);
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
            end;
          mx:=q[f,1]-1;
          my:=q[f,2];
          if (mx>=0)and(my>=0) then
            begin
              if map[mx,my].si=1 then exit(q[f,3]);
              inc(r);
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
            end;
          mx:=q[f,1]+1;
          my:=q[f,2];
          if (mx<=a)and(my<=b) then
            begin
              inc(r);
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
            end;
          mx:=q[f,1];
          my:=q[f,2]+1;
          if (mx<=a)and(my<=b) then
            begin
              inc(r);
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
            end;
        end;
    end;
  procedure finddis;
    var
      i,j,kk,x,y,mx,my:longint;
    begin
      for i:=0 to a do
        for j:=0 to b do
          begin
            mx:=i;
            my:=j-1;
            if (mx>=0)and(my>=0) then
              begin
                dis[map[i,j].nu,map[mx,my].nu]:=map[mx,my].po;
                if (mx>=1)and(map[mx,my].si=1)and(map[i-1,j-1].si=1) then
                  dis[map[i,j].nu,map[mx,my].nu]:=maxlongint;
              end;
            mx:=i-1;
            my:=j;
            if (mx>=0)and(my>=0) then
              begin
                dis[map[i,j].nu,map[mx,my].nu]:=map[mx,my].po;
                if (my>=1)and(map[mx,my].si=1)and(map[i-1,j-1].si=1) then
                  dis[map[i,j].nu,map[mx,my].nu]:=maxlongint;
              end;
            mx:=i;
            my:=j+1;
            if (mx<=a)and(my<=b) then
              begin
                dis[map[i,j].nu,map[mx,my].nu]:=map[mx,my].po;
                if (mx>=1)and(map[i,j].si=1)and(map[i-1,j].si=1) then
                  dis[map[i,j].nu,map[mx,my].nu]:=maxlongint;
              end;
            mx:=i+1;
            my:=j;
            if (mx<=a)and(my<=b) then
              begin
                dis[map[i,j].nu,map[mx,my].nu]:=map[mx,my].po;
                if (my>=1)and(map[i,j].si=1)and(map[i,j-1].si=1) then
                  dis[map[i,j].nu,map[mx,my].nu]:=maxlongint;
              end;
          end;
  end;
  procedure dijk;
    var
      i,j,minj,min:longint;
      v:array[1..6561]of boolean;
      d:array[1..6561]of longint;
    begin
      fillchar(d,sizeof(d),127);
      fillchar(v,sizeof(v),false);
      d[s]:=0;
      for i:=1 to c do
        begin
          min:=maxlongint;
          for j:=1 to c do
            if (not v[j])and(d[j]<min) then
              begin
                minj:=j;
                min:=d[j];
              end;
          if min=maxlongint then
            begin
              if d[t]<>maxlongint then writeln(d[t])
                else begin writeln('no solution');exit;end;
            end;
          v[minj]:=true;
          for j:=1 to c do
            if (not v[j])and(dis[minj,j]<>maxlongint)and(dis[minj,j]+min<d[j]) then
              d[j]:=min+dis[minj,j];
        end;
      if d[t]<>maxlongint then writeln(d[t])
        else writeln('no solution');
    end;
begin
  assign(input,'poj1697.in');
  //assign(output,'poj1697.out');
  reset(input);
  //rewrite(output);
  readln(m);
  for p:=1 to m do
    begin
      init;
      //writeln(map[4,4].si);
      c:=a+b;
      for i:=0 to a do
        for j:=0 to b do
          map[i,j].po:=c-find(i,j);
      //writeln(map[4,3].si,' ',map[4,3].po,' ',map[4,3].nu);
      finddis;
      //writeln(dis[10,11]);
      //halt;
      c:=(a+1)*(b+1);
      dijk;
    end;
  close(input);
  //close(output);
end.
