type
  node=record
    l,r:longword;
  end;
var
  t:array[0..100]of node;
  f:Array[0..100,0..100]of longword;
  v:Array[0..100,0..100]of boolean;
  a:Array[0..100]of longword;
  mm:array[0..100,0..100]of longword;
  i,j,k,m,ans,n,s:longword;
  procedure pre(i,j:longword);
    begin
      write(mm[i,j],' ');
      if mm[i,mm[i,j]-1]<>0 then pre(i,mm[i,j]-1);
      if mm[mm[i,j]+1,j]<>0 then pre(mm[i,j]+1,j);
    end;
  function find(p,i,j,o:longword):longword;
    var
      w,k:longword;
    begin
      if v[i,j] then exit(f[i,j]);
      v[i,j]:=true;
      if i>j then
        begin
          f[i,j]:=1;
          exit(1);
        end;
      if i=j then
        begin
          f[i,j]:=a[i];
          mm[i,j]:=i;
    //      if o=1 then t[p].l:=i
      //      else t[p].r:=i;
          exit(a[i]);
        end;
      for k:=i to j do
        begin
          w:=find(k,i,k-1,1)*find(k,k+1,j,2)+a[k];
          if w>f[i,j] then
            begin
              f[i,j]:=w;
              mm[i,j]:=k;
        //      if o=1 then t[p].l:=k
          //    else t[p].r:=k;
            end;
        end;
      exit(f[i,j]);
    end;
begin
  fillchar(t,sizeof(t),0);
  fillchar(mm,sizeof(mm),0);
  fillchar(f,sizeof(f),0);
  fillchar(v,sizeof(v),false);
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  ans:=0;
  for i:=1 to n do
    begin
      s:=find(i,1,i-1,1)*find(i,i+1,n,2)+a[i];
      if s>ans then
        begin
          mm[1,n]:=i;
          ans:=s;
        end;
    end;
  writeln(ans);               {
  writeln(mm[1,n]);
  writeln(mm[1,3],' ',mm[3,5])
  writeln(t[m].l,' ',t[m].r);
  writeln(t[4].l,' ',t[4].r);halt;     }
  pre(1,n);
end.
