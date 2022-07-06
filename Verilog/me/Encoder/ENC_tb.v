module ENC_tb;

    reg[7:0] in;
    wire[2:0] out;

    integer i;

    ENC enc(in, out);

    initial begin
        $monitor("input = %b output = %b",in, out);

            in = 8'b00000001;
            #5;
            in = 8'b00000010;
            #5;
            in = 8'b00000100;
            #5;
            in = 8'b00001000;
            #5;
            in = 8'b00010000;
            #5;
            in = 8'b00100000;
            #5;
            in = 8'b01000000;
            #5;
            in = 8'b10000000;
            #5;

    end
endmodule