`default_nettype none

module thruwire(
    input  wire sw,
    output wire led
);
    assign led = sw;
endmodule
