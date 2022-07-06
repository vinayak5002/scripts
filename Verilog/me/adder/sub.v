module sub(select,a,b,o);
    input[1:0] select;
    input[3:0] a;
    input[3:0] b;
    output[3:0] o;

    reg[3:0] o;
    wire[3:0] a;
    wire[3:0] b;

    integer i;
    integer k;

    always @(a or b)
    begin
        i = a;
        k = b;
        if(select==0) begin
            o = (i+k);
        end
        else begin
            o = (i-k);
        end
    end
endmodule