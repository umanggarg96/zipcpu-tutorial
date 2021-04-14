#include <stdio.h>
#include <stdlib.h>
#include "Vblinky.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, Vblinky *tb, VerilatedVcdC *tfp) {
    tb -> eval();
    if(tfp) 
        tfp->dump(tickcount * 10 - 2);
    tb -> clock = 1;
    tb -> eval();
    if(tfp) 
        tfp->dump(tickcount * 10);
    tb -> clock = 0;
    tb -> eval();
    if(tfp) {
        tfp->dump(tickcount * 10 + 5);
        tfp ->flush();
    }
}

int main(int argc, char **argv) {
    int last_led;
    unsigned int tickcount;
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vblinky *tb = new Vblinky;
    VerilatedVcdC * tfp = new VerilatedVcdC;

    tb->trace(tfp, 99);
    tfp->open("blinkytrace.vcd");

    last_led = tb -> led;
    for(unsigned int k = 0; k < (1 << 30); ++k) {
        tick(++tickcount, tb, tfp);
        if(last_led != tb->led) {
            printf ("k = %7d, led = %d\n", k, tb->led);
            last_led = tb -> led;
        }
    }
}
