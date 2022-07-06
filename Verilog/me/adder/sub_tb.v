module sub_tb;
    reg[1:0] select;
    reg[3:0] a;
    reg[3:0] b;
    wire[3:0] o;

    integer i;
    integer j;
    sub the_circuit(select,a,b,o);

initial begin
    $monitor("select = %d, a = %d b = %d, o = %b", select, a, b, o);
    #3;
    select = 0;
    #3;
    for(i=0; i<8; i+=1)
    begin
        a = i;
        #3;
        for(j=0; j<8; j+=1)
        begin
            b = j;
            #3;
        end
    end
    #3;
    select = 1;
    $display("\n");
    #3;
    for(i=0; i<8; i+=1)
    begin
        a = i;
        #3;
        for(j=0; j<i; j+=1)
        begin
            b = j;
            #3;
        end
    end
    $finish;
end
endmodule
