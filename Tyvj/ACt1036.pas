var
  b:Array[0..2000001,1..2]of longint;
  a:Array[0..2000001]of longint;
  i,j,n,m,s,t,k:longint;
    procedure qs(h,t:longint);
    var
      i,j,x,tt:longint;
    begin
      i:=h;
      j:=t;
      tt:=random(t-h)+h;
      x:=a[tt];
      a[tt]:=a[h];
      a[h]:=x;
      while i<j do
        begin
          while(i<j)and(a[j]>=x) do
            dec(j);
          a[i]:=a[j];
          while(i<j)and(a[i]<=x) do
            inc(i);
          a[j]:=a[i];
        end;
      a[i]:=x;
      if i-1>h then qs(h,i-1);
      if j+1<t then qs(j+1,t);
    end;
 begin
   fillchar(a,sizeof(A),0);
   fillchar(b,sizeof(b),0);
   readln(n);
   for i:=1 to n do
     read(A[i]);
   qs(1,n);
   s:=0;
   a[0]:=-109;
   for i:=1 to n do
     if a[i]=a[i-1] then
       inc(b[s,2])
     else
       begin
		 inc(s);
		 b[s,1]:=a[i];
		 b[s,2]:=1;
	   end;
   for i:=1 to s do
     writeln(b[i,1],' ',b[i,2]);
end.
