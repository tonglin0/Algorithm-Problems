//uses sysutils;
const
  mn=-2122219135;
var
  l,r:longint;
  //time:double;
  v:Array[0..200]of boolean;
  a,b,h,c:array[0..200]of longint;
  f:array[0..200,0..20,-420..420]of longint;
  p:array[0..200,0..20,-420..420]of boolean;
  i,j,k,m,n,s,t,ans,ii,case_:longint;
  function max(a,b:longint):longint;
    begin
      if a>b then exit(a);
      exit(b);
    end;
  function min(a,b:longint):longint;
    begin
      if a<b then exit(A);
      exit(b);
    end;
  procedure print(i,j,k:longint);
    begin
      if (i=0)or(j=0)then
        exit;
      if p[i,j,k] then
        begin
          v[i]:=true;
          inc(l,a[i]);
          inc(r,b[i]);
          print(i-1,j-1,k-c[i]);
        end
      else
        print(i-1,j,k);
    end;
begin
  //time:=now;
  //assign(input,'1015.in');reset(input);
  //assign(output,'1015.out');rewrite(output);
  case_:=0;
  readln(n,m);
  while not((n=0)and(m=0)) do
    begin
      inc(case_);
      fillchar(f,sizeof(f),129);
    {  writeln(f[1,1,1]);
      close(output);
      halt;     }
      fillchar(p,sizeof(p),false);
      fillchar(a,sizeof(a),0);
      fillchar(b,sizeof(b),0);
      fillchar(c,sizeof(c),0);
      fillchar(h,sizeof(h),0);
      for i:=1 to n do
        begin
          readln(a[i],b[i]);
          c[i]:=a[i]-b[i];
          h[i]:=a[i]+b[i];
        end;
      for i:=1 to n do
        for j:=1 to min(m,i) do
          for k:=max(j*(-20),-400) to min(j*20,400) do
            begin
              p[i,j,k]:=false;
              f[i,j,k]:=f[i-1,j,k];
              if ((j=1)and(c[i]=k)and(h[i]>f[i,j,k]))then
                begin
                  f[i,j,k]:=h[i];
                  p[i,j,k]:=true;
                end;
              if ((f[i-1,j-1,k-c[i]]<>mn)and(f[i-1,j-1,k-c[i]]+h[i]>f[i,j,k])) then
                begin
                  f[i,j,k]:=f[i-1,j-1,k-c[i]]+h[i];
                  p[i,j,k]:=true;
                end;
            end;{
      for i:=-400 to 400 do
        if f[n,m,i]>0 then
          write(i,' ');
      writeln;
      halt;   }
      for i:=0 to m*20 do
        begin
          if (f[n,m,i]=mn)and(f[n,m,-i]=mn) then continue;
          k:=i;
          if f[n,m,-k]>f[n,m,k] then
            k:=-k;
          l:=0;
          r:=0;
          fillchar(v,sizeof(v),0);
          print(n,m,k);
          //append(output);
          writeln('Jury #',case_);
          writeln('Best jury has value ',l,' for prosecution and value ',r,' for defence:');
          for ii:=1 to n do
            if v[ii] then
              write(' ',ii);
          writeln;
          writeln;
          //close(output);
          break;
        end;
      readln;
      readln(n,m);
    end;
  //writeln((now-time)*86400:0:10);
  //close(input);close(output);
end.


