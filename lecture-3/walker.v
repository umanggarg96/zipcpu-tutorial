module walker (
    input  wire       clock,
    output reg  [7:0] led
);

    reg right;

    always @ (posedge clock) 
        if(right)
            led <= {led[6:0], led[7]};
        else
            led <= {led[0], led[7:1]};

    always @ (posedge clock) 
        if((~right & led[1]) || (right & led[6]))
            right <= ~right;



    initial begin led = 8'h01; 
        right = 1'b1;
    end

    always @ (posedge clk)
        assert($onehot(led));

endmodule
