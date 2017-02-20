type
  node=record
    id,sa,he,bo,nu:longint;
  end;
var
  v:array[1..30000]of boolean;
  q:array[1..30001]of node;
  p,n,m,ii:longint;
  flag:boolean;
  procedure init;
    var
      i,j:longint;
    begin
      fillchar(q,sizeof(q),0);
      readln(n,m);
      for i:=1 to n do
        readln(q[i].id,q[i].sa,q[i].he);
    end;
  procedure qsort(head,tail:longint);
    var
      i,j,t:longint;
      x:node;
    begin
      i:=head;
      j:=tail;
      //t:=(head+tail)div 2;
      randomize;
      t:=random(tail-head)+head;
      x:=q[t];
      q[t]:=q[head];
      q[head]:=x;
      while i<j do
        begin
          while (i<j)and(q[j].sa>x.sa) do
            dec(j);
          q[i]:=q[j];
          while (i<j)and(q[i].sa<x.sa) do
            inc(i);
          q[j]:=q[i];
        end;
      q[i]:=x;
      if i-1>head then qsort(head,i-1);
      if j+1<tail then qsort(j+1,tail);
    end;
  procedure find(k:longint);
    var
      i,j:longint;
    begin
      for i:=1 to k-1 do
        begin
          if q[i].bo=k then
            begin
              v[i]:=true;
              find(i);
            end;
        end;
    end;
  procedure work;
    var
      i,j,k,sum:longint;
    begin
      for i:=1 to n do
        begin
          //fillchar(v,sizeof(v),false);
          flag:=false;
          for j:=i+1 to n do
            begin
              if (q[j].sa>q[i].sa)and(q[j].he>=q[i].he) then
                begin
                  q[i].bo:=j;
                  flag:=true;
                  break;
                end;
            end;
          if not flag then q[i].bo:=0;
          for j:=1 to i-1 do
            begin
              if q[j].bo=i then
                inc(q[i].nu,q[j].nu+1);
            end;
          //find(i);
          //for j:=1 to n do
            //if v[j] then inc(q[i].nu);
        end;
          for j:=1 to m do
            begin
              readln(k);
              for i:=1 to n do
                if q[i].id=k then
                  begin
                    k:=i;
                    break;
                  end;
              if q[k].bo=0 then write('0 ') else
              write(q[q[k].bo].id,' ');
              //fillchar(v,sizeof(v),false);
              //find(k);
              //for i:=1 to  k-1 do
                //if v[i] then inc(q[k].nu);
              writeln(q[k].nu);
            end;
    end;
begin                         {
  assign(input,'1634.in');
  assign(output,'1634.out');
  reset(input);
  rewrite(output);             }
  readln(p);
  for ii:=1 to p do
    begin
      init;
      qsort(1,n);
      work;
    end;                        {
  close(input);
  close(output);                 }
end.
