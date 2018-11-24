var
  zx,hx:string;
  t:Array[0..1000]of char;
  i,j,k,n,m,p,l:longint;
  procedure build(p,k,a,b:longint);
    var
      //x:array[1..26]of byte;
      max,po:byte;
    begin
      //if a>b then exit;
      t[p]:=zx[k];
      max:=0;
      //fillchar(x,sizoef(x),0);
      for i:=a to k-1 do
        if pos(zx[i],hx)>max then
          begin
            po:=i;
            max:=pos(zx[i],hx);
          end;
      if max<>0 then build(p shl 1,po,a,k-1);
      max:=0;
      for i:=k+1 to b do
        if pos(zx[i],hx)>max then
          begin
            po:=i;
            max:=pos(zx[i],hx);
          end;
      if max<>0 then build(p shl 1+1,po,k+1,b);
    end;
  procedure print(p:longint);
    begin
      if t[p]='!' then exit;
      write(t[p]);
      print(p shl 1);
      print(p shl 1+1);
    end;
begin
  readln(zx);
  readln(hx);
  l:=length(hx);
  k:=pos(hx[l],zx);
  for i:=1 to 1000 do
    t[i]:='!';
  build(1,k,1,l);
  print(1);
end.