module walker (
    input  wire       clock,
    input  wire       request,
    output reg  [7:0] led,
    output reg        busy
);

    reg right;

    always @ (posedge clock) begin
        if(busy) begin
            if(right & led[6])
                right <= ~right;
            if(~right &  led[0]) begin
                busy <= 1'b0;
                led <= 8'b0;
            end else 
                led <= right ?  {led[6:0], led[7]} :  {led[0], led[7:1]};
        end
        if(~busy && request) begin
            busy <= 1'b1;
            led <= 8'b1;
            right <= 1'b1;
        end
    end
        

    // always @ (posedge clk)
    //     assert($onehot(led));

endmodule
