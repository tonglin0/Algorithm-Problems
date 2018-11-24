var
  a,b,c:array[1..1000]of integer;
  s:string;
  flag:boolean;
  po,l,jj,ii,i,j,k,m,n,r:longint;
  procedure mul;
    begin
      jj:=6;
      if po<>0 then dec(jj);
      for ii:=1 to n-1 do
            begin
              fillchar(c,sizeof(c),0);
              for j:=1 to l do
                for k:=1 to jj do
                  c[j+k-1]:=c[j+k-1]+a[j]*b[k];
              l:=l+6;
              if po<>0 then dec(l);
              for i:=1 to l do
                if c[i]>=10 then
                  begin
                    c[i+1]:=c[i+1]+c[i] div 10;
                    c[i]:=c[i] mod 10;
                  end;
              while (c[l]=0)and(l>1) do dec(l);
              a:=c;
            end;
    end;
begin   {
  assign(input,'1001.in');//assign(output,'poj.out');
  reset(input);//rewrite(output);     }
  while not eof do
    begin
      fillchar(c,sizeof(c),0);
      fillchar(a,sizeof(a),0);
      fillchar(b,sizeof(b),0);
      readln(s);
      n:=0;
      for i:=8 to 9 do
        if (ord(s[i])>=48)and(ord(s[i])<=57) then
          n:=n*10+ord(s[i])-48;
      if n=0 then begin writeln(1);continue;end;
      po:=pos('.',s);
      if po=0 then
        begin
          for i:=1 to 6 do
            b[i]:=ord(s[6-i+1])-48;
          a:=b;
          l:=6;
          mul;
          if n=1 then
            begin
              c:=a;
              while (c[l]=0)and(l>1) do
                dec(l);
            end;
          for i:=l downto 1 do
            write(c[i]);
          writeln;
        end;
      if po<>0 then
        begin
          l:=6;
          for i:=l downto po+1 do
            b[l-i+1]:=ord(s[i])-48;
          for i:=po-1 downto 1 do
            b[l-i]:=ord(s[i])-48;
          a:=b;
          mul;
          po:=6-po;
          po:=po*n;
          //writeln(po);
          //writeln(l);
          if n=1 then
            begin
              c:=a;
              while (l>1)and(c[l]=0)do
                dec(l);
            end;
          for i:=l downto po+1 do
            write(c[i]);
          flag:=false;
          for jj:=1 to po do
            if c[jj]<>0 then
              begin
                flag:=true;
                break;
              end;
          if flag then
            begin
              write('.');
              for i:=po downto jj do
              write(c[i]);
            end;
          if (not flag)and(l=1)and(c[l]=0)and(po<>0) then write(0);
          writeln;
        end;
    end;
  //close(input);close(output);
end.



