type
  node=record
    time,dis,po:longint;
  end;
var
  q:array[0..100000]of node;
  a,map:Array[0..1000,0..1000]of longint;
  v:Array[0..1000]of boolean;
  i,j,k,m,n,f,r,s,t,ans,min:longint;
begin
  //assign(input,'1238.in');reset(input);
  fillchar(q,sizeof(q),0);
  fillchar(a,sizeof(a),0);
  fillchar(map,sizeof(map),0);
  fillchar(v,sizeof(v),false);
  readln(n,m);
  for i:=1 to m do
    begin
      read(s,t,k);
      inc(s);
      inc(t);
      inc(a[s,0]);
      a[s,a[s,0]]:=t;
      map[s,t]:=k;
    end;
  f:=0;
  r:=1;
  q[1].time:=0;
  q[1].po:=1;
  q[1].dis:=0;
  v[1]:=true;
  min:=0;
  ans:=maxlongint;
  while f<>r do
    begin
      f:=f mod 100000 +1;
      k:=q[f].po;
      v[k]:=true;
      if (min<>0)and(q[f].time>min) then break;
      if k=2 then
        begin
          min:=q[f].time;
          if q[f].dis<ans then ans:=q[f].dis;
        end
      else
        begin
          for i:=1 to a[k,0] do
            if not v[a[k,i]] then
              begin
                r:=r mod 100000+1;
                q[r].po:=a[k,i];
                q[r].time:=q[f].time+1;
                q[r].dis:=q[f].dis+map[k,a[k,i]];
              end;
        end;
    end;
  writeln(ans);
end.


