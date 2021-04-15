#include <stdio.h>
#include <stdlib.h>
#include "Vwalker.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, Vwalker *tb, VerilatedVcdC *tfp) {
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
    unsigned int tickcount;
    int led_val[] = {0x01, 0x02, 0x04, 0x08,
                     0x10, 0x20, 0x40, 0x80,
                     0x40, 0x20, 0x10, 0x08,
                     0x04, 0x02};

    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vwalker *tb = new Vwalker;
    VerilatedVcdC * tfp = new VerilatedVcdC;

    tb->trace(tfp, 99);
    tfp->open("walkertrace.vcd");

    tb -> eval();

    for(unsigned int k = 0; k < 100; ++k) {

        //checker
        if(led_val[k % 14] != tb->led) {
            printf("Error : Mismatch %0d expected, actual %0d\n", led_val[k % 14], tb->led);
        }

        tick(++tickcount, tb, tfp);

    }
}
