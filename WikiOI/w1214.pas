type
  node=record
    l,r:longint;
  end;
var
  v:Array[0..1001]of boolean;
  a:array[0..1001]of node;
  i,j,n,m,x,y,t,k,s:longint;
  procedure qs(h,t:longint);
    var
      x:node;
      i,j,tt:longint;
    begin
      i:=h;
      j:=t;
      tt:=random(t-h)+h;
      x:=a[tt];
      a[tt]:=a[h];
      a[h]:=x;
      while i<j do
        begin
          while (i<j)and(a[j].r>=x.r) do
            dec(j);
          a[i]:=a[j];
          while (i<j)and(a[i].r<=x.r) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
begin
  fillchar(a,sizeof(a),0);
  read(n);
  for i:=1 to n do
    begin
	  read(a[i].l,a[i].r);
	  if a[i].l>a[i].r then
	    begin
		  t:=a[i].l;
		  a[i].l:=a[i].r;
		  a[i].r:=t;
		 end;
    end;
  randomize;
  qs(1,n);
  fillchar(v,sizeof(v),true);
  k:=-10000;
  i:=1;
  while i<=n do
    begin
	  while (i<=n)and(a[i].l<k) do
	    begin
		  v[i]:=false;
		  inc(i);
		 end;
	  k:=a[i].r;
	  inc(i);
	 end;
  s:=0;
  for i:=1 to n do
    if v[i] then
	  inc(s);
  writeln(s);
end.

