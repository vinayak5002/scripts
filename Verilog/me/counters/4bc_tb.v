module bc_4_tb();

reg clk, rstn;
wire[3:0] otp;

bc_4 uut(clk, rstn, otp);

initial begin 
	$dumpfile("test1.vcd");
	$dumpvars(0, bc_4_tb);

clk <= 0; rstn <= 0;

#20 rstn <= 1;
#80 rstn <= 0;
#50 rstn <= 1;
#20 $finish;

end

always begin
#5 clk = ~clk;	
end
endmodule
