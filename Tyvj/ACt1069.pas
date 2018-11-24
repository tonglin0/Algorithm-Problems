type
  pt=^pk;
  pk=record
    data:longint;
    next:pt;
  end;
var
  a:array[0..151,1..2]of longint;
  map:Array[0..151,0..151]of boolean;
  f:Array[0..151]of longint;
  num:array[0..151,0..151]of longint;
  c:array[0..151]of pt;
  maxf:Array[0..151]of double;
  dis:Array[0..151,0..151]of double;
  max:array[0..151]of double;
  x,y:array[0..151]of longint;
  ch:char;
  v:Array[0..151]of boolean;
  tx,aaa,bbb,ty,i,j,k,m,n,s,t,iii,time,ii,jj:longint;
  maxa,maxb,ans,xx,yy:double;
  p,q:pt;
  procedure dfs(x:longint);
    var
      i,j:longint;
      p,q:pt;
    begin
      v[x]:=true;
      f[x]:=time;
      inc(num[time,0]);
      num[time,num[time,0]]:=x;
      p:=c[x];
      while p<>nil do
        begin
          if not v[p^.data] then dfs(p^.data);
          p:=p^.next;
        end;
    end;
begin
  //assign(input,'1069.in');assign(output,'1069.out');reset(input);rewrite(output);
  fillchar(map,sizeof(map),false);
  fillchar(dis,sizeof(dis),0);
  fillchar(max,sizeof(max),0);
  fillchar(maxf,sizeof(maxf),0);
  fillchar(num,sizeof(num),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to 150 do
    c[i]:=nil;
  fillchar(x,sizeof(x),0);
  fillchar(y,sizeof(y),0);
  read(n);
  for i:=1 to n do
    begin
      readln(s,t);
      a[i,1]:=s;
      a[i,2]:=t;
    end;
  for i:=1 to n do
  begin
    for j:=1 to n do
      begin
        read(ch);
        s:=ord(ch)-48;
        if s<>0 then
          begin
            map[i,j]:=true;
            dis[i,j]:=sqrt(sqr(a[i,1]-a[j,1])+sqr(a[i,2]-a[j,2]));
            if c[i]=nil then
              begin
                new(c[i]);
                c[i]^.data:=j;
                c[i]^.next:=nil;
              end
            else
              begin
                p:=c[i];
                while p<>nil do
                  begin
                    q:=p;
                    p:=p^.next;
                  end;
                new(p);
                p^.data:=j;
                p^.next:=nil;
                q^.next:=p;
              end;
     {       if c[j]=nil then
              begin
                new(c[j]);
                c[j]^.data:=i;
                c[j]^.next:=nil;
              end
            else
              begin
                p:=c[j];
                while p<>nil do
                  begin
                    q:=p;
                    p:=p^.next;
                  end;
                new(p);
                p^.data:=i;
                p^.next:=nil;
                q^.next:=p;
              end;}
          end;
      end;
    readln;
    end;
  fillchar(v,sizeof(v),0);
  time:=0;
  for i:=1 to n do
    if not v[i] then
      begin
        inc(time);
        dfs(i);
      end;                     {
  tx:=0;
  ty:=0;
  for i:=1 to n do
    if v[i] then
      begin
        inc(tx);
        x[tx]:=i;
      end
    else
      begin
        inc(ty);
        y[ty]:=i;
      end;                      }
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if (i<>j)and(i<>k)and(k<>j)and(dis[i,k]<>0)and(dis[k,j]<>0)and((dis[i,k]+dis[k,j]<dis[i,j])or(dis[i,j]=0)) then
          dis[i,j]:=dis[i,k]+dis[k,j];
  {for i:=1 to n do
    begin
      for j:=1 to n do
        write(dis[i,j]:0:2,' ');
      writeln;
    end;
  halt;  }
  for i:=1 to n do
    begin
      for j:=1 to n do
        if (dis[i,j]<>0)and(dis[i,j]>max[i]) then
          max[i]:=dis[i,j];
    end;               {
  maxa:=0;
  maxb:=0;
  for i:=1 to n do
    if (v[i])and(max[i]>maxa) then
      maxa:=max[i];
  for i:=1 to n do
    if (not v[i])and(max[i]>maxb) then
      maxb:=max[i];
  for i:=1 to n do
    write(max[i]:0:2,' ');    }
  for i:=1 to n do
    for j:=1 to n do
      if (dis[i,j]<>0)and(dis[i,j]>maxf[f[i]]) then
        maxf[f[i]]:=dis[i,j];
  ans:=maxlongint;
  for i:=1 to time do
    for j:=1 to num[i,0] do
      begin            {
        ii:=x[i];
        jj:=y[j];     }
        ii:=num[i,j];
        for k:=i+1 to time do
          for t:=1 to num[k,0] do
            begin
              jj:=num[k,t];
              xx:=max[ii]+max[jj]+sqrt(sqr(a[ii,1]-a[jj,1])+sqr(a[ii,2]-a[jj,2]));
{        if xx<maxa then xx:=maxa;
        if xx<maxb then xx:=maxb; }
              for iii:=1 to time do
                if (maxf[iii]>xx) then
                  xx:=maxf[iii];
              if xx<ans then begin ans:=xx;aaa:=ii;bbb:=jj;end;
            end;
      end;
  writeln(ans:0:6);       {
  writeln(aaa,' ',bbb);
  writeln(max[aaa]:0:2,' ',max[bbb]:0:2);  }
  //close(input);close(output);
end.
