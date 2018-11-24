type
  node=record
    l,r,c:longint;
  end;
var
  t:array[0..32100]of node;
  //v:array[0..8002]of boolean;
  c:array[0..8002]of longint;
  i,j,k,n,p,q,x,m,s,ll,rr:longint;
////////////////////////////////////////////////////////////
  procedure build(p,min,max:longint);
    var
      mid:longint;
    begin
      t[p].l:=min;
      t[p].r:=max;
      t[p].c:=0;
      if max-min>1 then
        begin
          mid:=(min+max)shr 1;
          build(p shl 1,min,mid);
          build(p shl 1+1,mid,max);
        end;
    end;
////////////////////////////////////////////////////////////
  procedure paint(p,a,b,x:longint);
    var
      mid:longint;
    begin
      if t[p].c<>x then
        begin
          if (t[p].l=a)and(t[p].r=b) then
            t[p].c:=x
          else
            begin
              if t[p].c>=0 then
                begin
                  t[p shl 1].c:=t[p].c;
                  t[p shl 1+1].c:=t[p].c;
                  t[p].c:=-1;
                end;
              mid:=(t[p].l+t[p].r) shr 1;
              if b<=mid then paint(p shl 1,a,b,x)
              else if a>=mid  then paint(p shl 1+1,a,b,x)
              else
                begin
                  paint(p shl 1,a,mid,x);
                  paint(p shl 1+1,mid,b,x);
                end;
            end;
        end;
    end;
  procedure count(p:longint;var cl,cr:longint);
    var
      mid,tl,tr:longint;
    begin
      if t[p].c>=0 then
        begin
          inc(c[t[p].c]);
          cl:=t[p].c;
          cr:=t[p].c;
        end
      else
        if (t[p].c<0)and(t[p].r-t[p].l>1) then
          begin
            count(p shl 1,cl,tl);
            count(p shl 1+1 ,tr,cr);
            if tl=tr then dec(c[tl]);
          end;
    end;
////////////////////////////////////////////////////////////
begin
  while not eof do
    begin
      readln(n);
      fillchar(t,sizeof(t),0);
      build(1,0,8000);
      //fillchar(v,sizeof(v),false);
      fillchar(c,sizeof(c),0);
      for i:=1 to n do
        begin
          readln(p,q,x);
          //v[x]:=true;
          inc(x);
          paint(1,p,q,x);
        end;
      count(1,ll,rr);
      for i:=1 to 8001 do
        if c[i]>0 then
          writeln(i-1,' ',c[i]);
      writeln;
    end;
end.
