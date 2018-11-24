var
  sa,sb,sc,s:string;
  ans,i,j,k,l,la,lb,n,m:longint;
  procedure work(a,b:string);
    begin
      for i:=ans to l do
        begin
          s:=copy(a,1,i);
          sc:=copy(b,length(b)-i+1,i);
          if (s=sc)and(i>ans) then ans:=i;
        end;
    end;
begin
  readln(sa);
  readln(sb);
  ans:=0;
  la:=length(sa);
  lb:=length(sb);
  if la>lb then l:=lb
    else l:=la;
  work(sa,sb);
  work(sb,sa);
  writeln(ans);
end.