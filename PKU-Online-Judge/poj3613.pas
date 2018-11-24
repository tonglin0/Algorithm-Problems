type
  arr=array[0..101,0..101]of longint;
var
  aa,s:arr;
  u,v,w,min,ans,i,j,k,m,n,t,e,d:longint;
  no:array[0..1001]of longint;         {
  function cheng(a,b:arr):arr;
    var
      p:arr;
      i,j,k,min:longint;
    begin
      fillchar(p,sizeof(p),0);
      for i:=1 to t do
        for j:=1 to t do
          begin
            min:=maxlongint;
            for k:=1 to t do
              if a[i,k]<min-b[k,j] then
                min:=a[i,k]+b[k,j];
            p[i,j]:=min;
          end;
      cheng:=p;
    end;         }
  procedure find;
    var
      i,j,min:longint;
      te,kk,a,b,p:arr;
    begin
      s:=aa;
      te:=aa;
      dec(n);
      while n>0 do
        begin
          if n and 1=1 then
            begin
              a:=s;
              b:=te;
              //fillchar(p,sizeof(p),0);
              for i:=1 to t do
                for j:=1 to t do
                  begin
                    min:=maxlongint;
                    for k:=1 to t do
                      if a[i,k]<min-b[k,j] then
                        min:=a[i,k]+b[k,j];
                    p[i,j]:=min;
                  end;
              s:=p;
            end;
          n:=n shr 1;
          a:=te;
          b:=te;
          //fillchar(p,sizeof(p),0);
          for i:=1 to t do
            for j:=1 to t do
              begin
                min:=maxlongint;
                for k:=1 to t do
                  if a[i,k]<min-b[k,j] then
                    min:=a[i,k]+b[k,j];
                p[i,j]:=min;
              end;
          te:=p;
        end;
      e:=no[e];
      d:=no[d];
      //writeln(s[e,d]);
    end;
begin
  //assign(input,'3613.in');reset(input);
  fillchar(no,sizeof(no),0);
  fillchar(aa,sizeof(aa),0);
  readln(n,m,e,d);
  t:=0;
  for i:=1 to 100 do
    for j:=1 to 100 do
      aa[i,j]:=maxlongint;
  for i:=1 to m do
    begin
      read(w,u,v);
      if no[u]=0 then
        begin
          inc(t);
          no[u]:=t;
        end;
      if no[v]=0 then
        begin
          inc(t);
          no[v]:=t;
        end;
      if w<aa[no[u],no[v]] then
        begin
          aa[no[u],no[v]]:=w;
          aa[no[v],no[u]]:=w;
        end;
    end;
  find;
  writeln(s[e,d]);
end.

