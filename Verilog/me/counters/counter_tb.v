module counter_tb();
reg clock, reset, enable;
wire[3:0] counter_out;

f_counter ct(clock, reset, enable, counter_out);

initial begin
	$dumpfile("test.vcd");
	$dumpvars(0,counter_tb);
	$monitor("clock: %b		reset: %b		enable: %b		output: %b", clock, reset, enable, counter_out);
	clock = 1; reset = 0; enable = 0;
	#5 reset = 1;
	#10 reset = 0;
	#5 enable = 1;
	#10 enable = 0;
	#10 $finish;
end

always begin
		#5 clock = ~clock;
end

endmodule // test