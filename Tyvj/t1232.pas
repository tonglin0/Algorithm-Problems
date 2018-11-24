type
  node2=record
    h,id:longint;
  end;
const
  mn=250001;
var
  far:array[0..250001,1..4]of longint;
  dis:array[0..250001]of longint;
  ins:Array[0..250010]of boolean;
  q:array[0..mn]of longint;
  a:array[0..501,0..501]of node2;
  map:Array[0..250001,0..4]of longint;
  f,r,i,j,k,m,n,s,t,x,y,x2,y2,st,en,x1,u,v,w,y1,mx,my:longint;
  ch:char;
  function relax(u,v,w:longint):boolean;
    begin
      if dis[u]+w<dis[v] then
        begin
          dis[v]:=dis[u]+w;
          exit(true);
        end;
      exit(false);
    end;
begin
  //assign(input,'1232.in');reset(input);assign(output,'1232.out');rewrite(output);
  fillchar(map,sizeof(map),0);
  fillchar(far,sizeof(Far),0);
  fillchar(dis,sizeof(dis),127);
  fillchar(ins,sizeof(ins),false);
  fillchar(q,sizeof(Q),0);
  fillchar(a,sizeof(A),0);
  readln(n,m);
  t:=0;
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(ch);
          inc(t);
          a[i,j].id:=t;
          if ch='.' then
            a[i,j].h:=1
          else
            a[i,j].h:=2;
        end;
      readln;
    end;
  t:=0;
  for i:=1 to n do
    for j:=1 to m do
      begin
        x:=i-1;
        y:=j;
        u:=a[i,j].id;
        if (x>0) then
          begin
            v:=a[x,y].id;
            inc(map[u,0]);
            map[u,map[u,0]]:=v;
            far[u,map[u,0]]:=abs(a[x,y].h-a[i,j].h)+1;
            inc(map[v,0]);
            map[v,map[v,0]]:=u;
            far[v,map[v,0]]:=abs(a[x,y].h-a[i,j].h)+1;
          end;
        x:=i;
        y:=j-1;
        if y>0 then
          begin
            v:=a[x,y].id;
            inc(map[u,0]);
            map[u,map[u,0]]:=v;
            far[u,map[u,0]]:=abs(a[x,y].h-a[i,j].h)+1;
            inc(map[v,0]);
            map[v,map[v,0]]:=u;
            far[v,map[v,0]]:=abs(a[x,y].h-a[i,j].h)+1;
          end;
      end;
  readln(x1,y1,x2,y2);
  st:=a[x1,y1].id;
  en:=a[x2,y2].id;
  dis[st]:=0;
  fillchar(ins,sizeof(ins),false);
  ins[st]:=true;
  f:=0;
  r:=1;
  q[1]:=st;
  while f<>r do
    begin
      f:=f mod mn+1;
      u:=q[f];
      ins[u]:=false;
      for i:=1 to map[u,0] do
        begin
          v:=map[u,i];
          if (relax(u,v,far[u,i])) then
            begin
              if (not ins[v]) then
                begin
                  r:=r mod mn+1;
                  ins[v]:=true;
                  q[r]:=v;
                end;
            end;
        end;
    end;
  writeln(dis[en]);
  //close(input);close(output);
end.
