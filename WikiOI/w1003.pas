var
  a:Array[0..101,0..101]of longint;
  pre,dis:Array[0..101]of longint;
  v:array[0..101]of boolean;
  b:Array[0..101,1..2]of longint;
  i,j,k,n,m,s,t,ans,sum:longint;
  procedure dijk;
    var
      j,min,minj,i:longint;
    begin
      ans:=0;
      sum:=0;
      dis[1]:=0;
      for i:=1 to n do
        begin
          min:=dis[0];
          for j:=1 to n do
            if (not v[j])and(dis[j]<min) then
              begin
                min:=dis[j];
                minj:=j;
              end;
          v[minj]:=true;
          inc(ans,min);
          if min<>0 then
            begin
              inc(sum);
              b[sum,1]:=pre[minj];
              b[sum,2]:=minj;
              if b[sum,1]>b[sum,2] then
                begin
                  k:=b[sum,1];
                  b[sum,1]:=b[sum,2];
                  b[sum,2]:=k;
                end;
            end;
          for j:=1 to n do
            if a[minj,j]<dis[j] then
              begin
                dis[j]:=a[minj,j];
                pre[j]:=minj;
              end;
        end;
    end;
begin
  //assign(input,'1003.in');reset(input);
  fillchar(a,sizeof(a),0);
  fillchar(pre,sizeof(pre),0);
  fillchar(v,sizeof(v),false);
  fillchar(dis,sizeof(dis),127);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(A[i,j]);
  dijk;
  writeln(sum);
  for i:=1 to sum do
    writeln(b[i,1],' ',b[i,2]);
  writeln(ans);
end.
