module dec(in, out);

    input[2:0] in;
    output[7:0] out;

    // wirte[2:0] in;
    reg[7:0] out;


    always @(in) begin
        
        case(in)
            0 : out = 8'b00000001;
            1 : out = 8'b00000010;
            2 : out = 8'b00000100;
            3 : out = 8'b00001000;
            4 : out = 8'b00010000;
            5 : out = 8'b00100000;
            6 : out = 8'b01000000;
            7 : out = 8'b10000000;
        endcase

    end
endmodule