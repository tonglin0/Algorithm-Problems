const
  dx:array[1..8]of longint=(-1,-1,-1,0,0,1,1,1);
  dy:array[1..8]of longint=(-1,0,1,-1,1,-1,0,1);
var
  map:array[1..101,1..101]of boolean;
  v:array[1..101,1..101]of boolean;
  ans,i,j,k,l,n,m:longint;
  ch:char;
  d:array[1..100]of longint;
  procedure work(x,y:longint);
    var
      i,j,mx,my:longint;
    begin
      for i:=1 to 8 do
        begin
          if ((i=1)or(i=2)or(i=3))and(y=1) then continue;
          if ((i=6)or(i=7)or(i=8))and(y=n) then continue;
          if ((i=1)or(i=4)or(i=6))and(x=1) then continue;
          if ((i=3)or(i=5)or(i=8))and(x=m) then continue;
          my:=y+dx[i];
          mx:=x+dy[i];
          if not v[mx,my] then
            begin
              v[mx,my]:=true;
              if map[mx,my] then begin map[mx,my]:=false;work(mx,my);end;
            end;
        end;
    end;
begin
  //assign(input,'uva.in');
  //assign(output,'uva.out');
  //reset(input);
  //rewrite(output);
  readln(m,n);
  k:=0;
  while m<>0 do
    begin
      inc(k);
      fillchar(map,sizeof(map),false);
      fillchar(v,sizeof(v),false);
      ans:=0;
      for i:=1 to m do
        begin
          for j:=1 to n do
            begin
              read(ch);
              if ch='*' then map[i,j]:=false
                else map[i,j]:=true;
            end;
          readln;
        end;
      for i:=1 to m do
        for j:=1 to n do
          begin
            if (v[i,j]=false)and(map[i,j]) then
              begin
                v[i,j]:=true;
                inc(ans);
                map[i,j]:=false;
                work(i,j);
              end;
           end;
      d[k]:=ans;
      readln(m,n);
    end;
  for i:=1 to k do
    writeln(d[i]);
  //close(input);
  //close(output);
end.
