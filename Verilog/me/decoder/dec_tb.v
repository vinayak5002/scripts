module dec_tb;

    reg[2:0] in;
    wire[7:0] out;

    integer i;
    integer j;

    dec dec_tb(in, out);

    initial begin
        #10;
        // $monitor("input = %d output = %b",in, out);
        for(i = 0;i<8;i=i+1)
        begin
            in = i;
            #3;
            $display("\ninput: %d", in);
            for(j=0; j<8; j++)
            begin
                $display("output[%d] = %d",j, out[j]);
            end
        end
    end
endmodule