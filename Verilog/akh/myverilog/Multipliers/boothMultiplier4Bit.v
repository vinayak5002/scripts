////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2020 Akilesh Kannan <akileshkannan@gmail.com>
//
// File: boothMultiplier4Bit.v
// Modified: 2020-07-15
// Description: 4 bit Booth Multiplier
//              Signed Multiplication
//
// License: MIT
//
////////////////////////////////////////////////////////////////////////

`default_nettype None

`timescale 1ns/1ps

module boothMultiplier4Bit(output reg[7:0] prod, output reg busy, input[3:0] mc, input[3:0] mp, input clk, input start);

    reg [3:0] A, Q, M;
    reg Q_1;
    reg [2:0] count;
    wire [3:0] sum, difference;

    always @(posedge clk) begin
        if (start) begin
            A <= 0;
            M <= mc;
            Q <= mp;
            Q_1 <= 1'b0;
            count <= 0;
        end
        else begin
            busy <= 1'b1;
            case ({Q[0], Q_1})
                2'b0_1 : {A, Q, Q_1} <= {sum[3], sum, Q};
                2'b1_0 : {A, Q, Q_1} <= {difference[3], difference, Q};
                default: {A, Q, Q_1} <= {A[3], A, Q};
            endcase
            count <= count + 1'b1;
            if(count == 4) begin
                busy <= 1'b0;
                prod <= {A, Q};
                count <= 0;
            end
        end
    end

    assign sum = A + M;
    assign difference = A + ~M + 1'b1;
endmodule
