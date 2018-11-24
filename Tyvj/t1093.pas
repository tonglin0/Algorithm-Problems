var
  c:array[0..9]of boolean;
  map:array[1..9,1..9]of longint;
  i,j,k,n,iii,m,ii,jj,kk,x,y:longint;
  flag:boolean;
begin
  //assign(input,'1093.in');reset(input);
  readln(n);
  for iii:=1 to n do
    begin
      flag:=true;
      for i:=1 to 9 do
        for j:=1 to 9 do
          read(map[i,j]);
      for i:=1 to 9 do
        begin
          fillchar(c,sizeof(c),false);
          for j:=1 to 9 do
            begin
              if c[map[i,j]] then flag:=false;
              if not c[map[i,j]] then c[map[i,j]]:=true;
            end;
        end;
      for i:=1 to 9 do
        begin
          fillchar(c,sizeof(c),false);
          for j:=1 to 9 do
            begin
              if c[map[j,i]] then flag:=false;
              if not c[map[j,i]] then c[map[j,i]]:=true;
            end;
        end;
      for i:=1 to 3 do
        for j:=1 to 3 do
          begin
            x:=1+3*(i-1);
            y:=1+3*(j-1);
            fillchar(c,sizeof(c),false);
            for ii:=x to x+2 do
              for jj:=y to y+2 do
                if c[map[ii,jj]] then flag:=false
                else c[map[ii,jj]]:=true;
          end;
      if flag then writeln('Right')
      else writeln('Wrong');
      readln;
    end;
  //close(input);
end.

