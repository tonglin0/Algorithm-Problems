type
  arr=array[1..100]of longint;
const
  p:set of char=['0'..'9'];
var
  sonsu:array[1..900]of longint;
  son:array[1..900]of arr;
  ans:array[1..900]of longint;
  f:array[1..900]of longint;
  //map:array[1..900,1..900]of boolean;
  into:array[1..900]of boolean;
  c:array[1..900]of word;
  ask:array[1..900,0..2000]of longint;
  n,m,i,j,k,ki,km:longint;
  head:longint;
  ch:char;
  function find(x:longint):longint;
    begin
      if x<>f[x] then f[x]:=find(f[x]);
      exit(f[x]);
    end;
  procedure dfs(u:longint);
    var
      i,j,k:longint;
    begin
      f[u]:=u;
      c[u]:=1;
      for i:=1 to sonsu[u] do
        if (c[son[u][i]]=0)then
          begin
            dfs(son[u][i]);
            f[son[u][i]]:=u;
          end;
      for i:=1 to ask[u,0] do
        begin
          //if ask[u,i]=u then begin inc(ans[u]);continue;end;
          if (c[ask[u,i]]=2) then
          begin
            k:=find(ask[u,i]);
            inc(ans[k]);
          end;
        end;
        c[u]:=2;
    end;
begin
  assign(input,'1470.in');
  assign(output,'1470.out');
  reset(input);
  rewrite(output);
  while not eof do
    begin
      fillchar(sonsu,sizeof(sonsu),0);
      fillchar(son,sizeof(son),0);
      fillchar(ask,sizeof(ask),0);
      fillchar(ans,sizeof(ans),0);
      fillchar(c,sizeof(c),0);
      fillchar(f,sizeof(f),0);
      //fillchar(map,sizeof(map),false);
      fillchar(into,sizeof(into),false);
      //fillchar(lca,sizeof(lca),0);
      n:=0;
      read(ch);
      while (not(ch in p))and not eof do
        read(ch);
      while ch in p do
        begin
          n:=n*10+ord(ch)-48;
          read(ch);
        end;
      for i:=1 to n do
        begin
          while not (ch in p) do
            read(ch);
          ki:=0;
          while ch in p do
            begin
              ki:=ki*10+ord(ch)-48;
              read(ch);
            end;
          while not (ch in p) do
            read(ch);
          km:=0;
          while ch in p do
            begin
              km:=km*10+ord(ch)-48;
              read(ch);
            end;
          while not (ch in p) do
            read(ch);
          for j:=1 to km do
            begin
              k:=0;
              while ch in p do
                begin
                  k:=k*10+ord(ch)-48;
                  read(ch);
                end;
              into[k]:=true;
              inc(sonsu[ki]);
              son[ki][sonsu[ki]]:=k;
              while not (ch in p) do
                read(ch);
            end;
        end;
      m:=0;
      while ch in p do
        begin
          m:=m*10+ord(ch)-48;
          read(ch);
        end;
      for i:=1 to m do
        begin
          while not (ch in p) do
            read(ch);
          ki:=0;
          while ch in p do
            begin
              ki:=ki*10+ord(ch)-48;
              read(ch);
            end;
          while not (ch in p) do
            read(ch);
          k:=0;
          while ch in p do
            begin
              k:=k*10+ord(ch)-48;
              read(ch);
            end;
          if k=ki then inc(ans[k]);
          inc(ask[ki,0]);
          ask[ki,ask[ki,0]]:=k;
          inc(ask[k,0]);
          ask[k,ask[k,0]]:=ki;
        end;
      for i:=1 to n do
        if not into[i] then
          begin
            head:=i;
            break;
          end;
      dfs(head);
      for i:=1 to n do
        if ans[i]>0 then
          begin
            write(i,':');
            writeln(ans[i]);
          end;
    end;
  close(input);
  close(output);
end.

