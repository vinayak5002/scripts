// `include "DFF.v"

module DFF_tb;
    reg d;
    wire q;

    DFF dff(d, q);

    initial 
    begin
        $monitor("input d = %d output q = %d", d, q);

        d=0;
        // q=1'b0;
        #2;
        d=0;
        // q=1'b1;
        #2;
        d=1;
        // q=1'b0;
        #2;
        d=1;
        // q=1'b1;

    end
endmodule