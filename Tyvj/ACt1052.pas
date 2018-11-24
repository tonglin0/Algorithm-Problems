type
  node=record
    l,r:longint;
  end;
const
  mn=6001;
var
  l,a:Array[0..mn]of longint;
  ins:array[0..mn]of boolean;
  v:array[0..mn,1..2]of boolean;
  f:Array[0..mn,1..2]of longint;
  t:Array[0..mn]of node;
  i,j,k,m,n,s:longint;
  function max(x,y:longint):longint;
    begin
	  if x>y then exit(x);
	  exit(y);
	end;
  function find(i,j:longint):longint;
    var
	  k,s:longint;
	begin
	  if i=0 then exit(0);
	  if v[i,j] then exit(F[i,j]);
	  v[i,j]:=true;
	  if j=1 then
	    begin
		  k:=t[i].l;
		  s:=a[i];
		  while k<>0 do
		    begin
			  s:=s+find(k,2);
			  k:=t[k].r;
			end;
		  f[i,j]:=s;
		  exit(f[i,j]);
		 end
	  else
	    begin
		  k:=t[i].l;
		  s:=0;
		  while k<>0 do
		    begin
			  s:=s+max(find(k,1),find(k,2));
			  k:=t[k].r;
			end;
		  f[i,j]:=s;
		  exit(f[i,j]);
		end;
	end;
begin
  //assign(input,'1052.in');reset(input);
  fillchar(l,sizeof(l),0);
  fillchar(a,sizeof(a),0);
  fillchar(ins,sizeof(ins),false);
  fillchar(v,sizeof(v),0);
  fillchar(f,sizeof(f),0);
  fillchar(t,sizeof(t),0);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n-1 do
    begin
	  read(s,k);
          ins[s]:=true;
	  if l[k]=0 then
	    begin
		  t[k].l:=s;
		  l[k]:=s;
		end
	  else
	    begin
		  t[l[k]].r:=s;
		  l[k]:=s;
		 end;
	end;
  for i:=1 to n do
    if not ins[i] then
      begin
        m:=i;
        break;
      end;
    writeln(max(find(m,1),find(m,2)));
end.

