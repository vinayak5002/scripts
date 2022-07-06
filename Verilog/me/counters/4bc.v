module bc_4(clk, rstn, otp);
input clk, rstn;	
output[3:0] otp;

wire clk, rstn;
reg[3:0] otp;

always@(posedge clk)
begin
	if(! rstn)
	begin
		otp <= 0;
	end
		
	else
	begin
		otp <= otp + 1;
	end
end
endmodule	