type
  node=record
    po,si,nu:integer;
  end;
  edge=record
    u,v,w:integer;
  end;
var
  e:array[1..26400]of edge;
  map:array[0..80,0..80]of node;
  //dis:array[1..2400,1..2400]of integer;
  p,m,i,j,sx,k,sy,top,tx,ty,c,a,b,s,t:integer;
  procedure init;
    var
      i,j:integer;
      ch:char;
    begin
      fillchar(e,sizeof(e),0);
      top:=0;
      fillchar(map,sizeof(map),0);
      readln(a,b);
      c:=(a+1)*(b+1);
      {for i:=1 to c do
        for j:=1 to c do
          dis[i,j]:=maxint;    }
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
          map[i,b].si:=0;
          readln;
        end;
      for i:=0 to b do
        begin
          inc(k);
          if (a=sx)and(i=sy) then s:=k;
          if (a=tx)and(i=ty) then t:=k;
          map[a,i].nu:=k;
          map[a,i].si:=0;
        end;  {
      for i:=0 to a do
        begin
          for j:=0 to b do
            begin
              write(map[i,j].si,' ');
            end;
          writeln;
        end;
      halt;  }
    end;
  function find(x,y:integer):integer;
    var
      q:array[1..3000,1..3]of integer;
      co:array[0..80,0..80]of boolean;
      mx,my,i,j,r,f:integer;
    begin
      fillchar(q,sizeof(q),0);
      fillchar(co,sizeof(co),false);
      f:=0;
      r:=1;
      q[1,1]:=x;
      q[1,2]:=y;
      q[1,3]:=0;
      while f<r do
        begin
          inc(f);
          //f:=f mod 3000;
          //co[q[f,1],q[f,2]]:=true;
          if (map[q[f,1],q[f,2]].si=1)//and(q[f,1]<>a)and(q[f,2]<>b)
            then exit(q[f,3]);
          mx:=q[f,1]-1;
          my:=q[f,2]-1;
          if (mx>=0)and(my>=0)then
            begin
              if (map[mx,my].si=1)
                then exit(q[f,3]);
            end;
          mx:=q[f,1];
          my:=q[f,2]-1;
          if (mx>=0)and(my>=0) then
            begin
              if (map[mx,my].si=1)//and(mx<>a)
                then exit(q[f,3]);
                if not co[mx,my] then begin
              inc(r);
              //r:=r mod 3000;
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
              co[mx,my]:=true;             end;
            end;
          mx:=q[f,1]-1;
          my:=q[f,2];
          if (mx>=0)and(my>=0) then
            begin
              if (map[mx,my].si=1)//and(my<>b)
                then exit(q[f,3]);
                if not co[mx,my] then begin
              inc(r);
              //r:=r mod 3000;
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
              co[mx,my]:=true;         end;
            end;
          mx:=q[f,1]+1;
          my:=q[f,2];
          if (mx<=a)and(my<=b) then
            begin
              if not co[mx,my] then begin
              inc(r);
              //r:=r mod 3000;
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
              co[mx,my]:=true;        end;
            end;
          mx:=q[f,1];
          my:=q[f,2]+1;
          if (mx<=a)and(my<=b) then
            begin
              if not co[mx,my] then begin
              inc(r);
              //r:=r mod 3000;
              q[r,1]:=mx;
              q[r,2]:=my;
              q[r,3]:=q[f,3]+1;
              co[mx,my]:=true;     end;
            end;
        end;
    end;
  procedure finddis;
    var
      i,j,kk,x,nn,y,mx,my:integer;
    begin
      for i:=0 to a do
        for j:=0 to b do
          begin
            nn:=map[i,j].nu;
            mx:=i;
            my:=j-1;
            if (mx>=0)and(my>=0) then
              begin
                inc(top);
                e[top].u:=nn;
                e[top].v:=map[mx,my].nu;
                e[top].w:=map[mx,my].po;
                if (i-1>=0)and(j-1>=0)and(map[mx,my].si=1)and(map[i-1,j-1].si=1) then
                  dec(top);
                //if (i=0)or(i=a)
              end;
            mx:=i-1;
            my:=j;
            if (mx>=0)and(my>=0) then
              begin
                inc(top);
                e[top].u:=nn;
                e[top].v:=map[mx,my].nu;
                e[top].w:=map[mx,my].po;
                if (i>=1)and(j>=1)and(map[mx,my].si=1)and(map[i-1,j-1].si=1) then
                  dec(top);
              end;
            mx:=i;
            my:=j+1;
            if (mx<=a)and(my<=b) then
              begin
                inc(top);
                e[top].u:=nn;
                e[top].v:=map[mx,my].nu;
                e[top].w:=map[mx,my].po;
                if (i>=1)and(map[i,j].si=1)and(map[i-1,j].si=1) then
                  dec(top);
              end;
            mx:=i+1;
            my:=j;
            if (mx<=a)and(my<=b) then
              begin
                inc(top);
                e[top].u:=nn;
                e[top].v:=map[mx,my].nu;
                e[top].w:=map[mx,my].po;
                if (j>=1)and(map[i,j].si=1)and(map[i,j-1].si=1) then
                  dec(top);
              end;
          end;
  end;
  procedure dijk;
    var
      i,j,minj,min:integer;
      vis:array[1..6600]of boolean;
      d:array[1..6600]of integer;
    begin
      for i:=1 to c do
        d[i]:=maxint;
      fillchar(vis,sizeof(vis),false);
      d[s]:=0;
      for i:=1 to c do
        begin
          min:=maxint;
          for j:=1 to c do
            if (not vis[j])and(d[j]<min) then
              begin
                minj:=j;
                min:=d[j];
              end;
          if min=maxint then
            begin
              if d[t]<>maxint then begin writeln(d[t]+map[sx,sy].po);exit;end
                else begin writeln('no solution');exit;end;
            end;
          vis[minj]:=true;
          //write(minj,' ');
          for j:=1 to top do
            begin
              if (minj=e[j].u)and(not vis[e[j].v])and(e[j].w<>maxint)and(min+e[j].w<d[e[j].v])then
                d[e[j].v]:=min+e[j].w;
              //if (minj=e[j].v)and(not vis[e[j].u])and(min+e[j].w<d[e[j].u])then
                //d[e[j].u]:=min+e[j].w;
            end;
        end;
      if d[t]<>maxint then writeln(d[t]+map[sx,sy].po)
        else writeln('no solution');
    end;
begin              {
  assign(input,'1697.in');
  assign(output,'poj1697.out');
  reset(input);
  rewrite(output);  }
  readln(m);
  for p:=1 to m do
    begin
      init;
      //writeln(map[2,2].si);
      //halt;
      c:=a+b;                                   {
      for i:=0 to a do   begin
        for j:=0 to b do
          begin
          map[i,j].po:=c-find(i,j);
          write(map[i,j].po,' ');
        end;         writeln;
        end;                          }
      for i:=0 to a do
        for j:=0 to b do
          map[i,j].po:=c-find(i,j);
      //writeln(map[2,2].po,' ',map[2,5].nu);
      //halt;
      finddis;
      //writeln(dis[1,2]);
      //halt;
      c:=(a+1)*(b+1); {
      for i:=1 to top do
        if e[i].u=32 then
          writeln(e[i].u,' ',e[i].v,' ',e[i].w);
      writeln('no');   }
      //halt;
      dijk;
    end;          {
  close(input);
  close(output); }
end.
