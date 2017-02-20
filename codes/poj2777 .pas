type
  node=record
    c,l,r:longint;
  end;
var
  tree:array[1..400002]of node;
  ans,p,q,i,j,ii,n,m,l,k,te:longint;
  color:array[0..30]of boolean;
  ch:char;
  procedure build(p,min,max:longint);
    var
      mid:longint;
    begin
      tree[p].l:=min;
      tree[p].r:=max;
      tree[p].c:=1;
      if max-min>1 then
        begin
          mid:=(max+min) shr 1;
          build(p shl 1,min,mid);
          build(p shl 1+1,mid,max);
        end;
    end;
  procedure paint(p,a,b,k:longint);
    var
      mid:longint;
    begin
      if tree[p].c<>k then
        begin
          mid:=(tree[p].l+tree[p].r)shr 1;
          if (tree[p].l=a)and(tree[p].r=b) then tree[p].c:=k
          else
            begin
              if tree[p].c>=0 then
                begin
                  tree[p shl 1].c:=tree[p].c;
                  tree[p shl 1 +1].c:=tree[p].c;
                  tree[p].c:=-1;
                end;
              if mid>=b then
                paint(p shl 1,a,b,k)
              else if mid<=a then
                paint(p shl 1+1,a,b,k)
              else
                begin
                  paint(p shl 1,a,mid,k);
                  paint(p shl 1+1,mid,b,k);
                end;
            end;
        end;
    end;
  procedure count(p,min,max:longint);
    var
      mid:longint;
    begin
      if tree[p].c>0 then
        color[tree[p].c]:=true
      else
        begin
          mid:=(tree[p].l+tree[p].r)shr 1;
          if max<=mid then count(p shl 1,min,max)
          else if min>=mid then count(p shl 1+1,min,max)
          else
            begin
              count(p shl 1,min,mid);
              count(p shl 1+1,mid,max);
            end;
        end;
    end;
begin
  //assign(input,'2777.in');reset(input);
  fillchar(tree,sizeof(tree),0);
  readln(l,m,n);
  build(1,1,l+1);
  for ii:=1 to n do
    begin
      read(ch);
      if ch='C' then
        begin
          readln(p,q,k);
          if q<p then
            begin
              te:=p;
              p:=q;
              q:=te;
            end;
          inc(q);
          paint(1,p,q,k);
        end
      else
        begin
          readln(p,q);
          if q<p then
            begin
              te:=p;
              p:=q;
              q:=te;
            end;
          inc(q);
          fillchar(color,sizeof(color),false);
          count(1,p,q);
          ans:=0;
          for i:=1 to 30 do
            if color[i] then
              inc(ans);
          writeln(ans);
        end;
    end;
  //close(input);
end.
