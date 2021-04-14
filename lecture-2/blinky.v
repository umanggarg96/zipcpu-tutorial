`default_nettype none

module blinky(
    input  wire clock,
    output wire led
);

    reg [26:0] counter;
    initial counter = 0;
    always @(posedge clock)
        counter <= counter + 1;

    assign led = counter[26];
endmodule
