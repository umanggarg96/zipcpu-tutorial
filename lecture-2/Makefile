
VINC=/usr/share/verilator/include

all: blinky

obj_dir/Vblinky.cpp: blinky.v
	verilator -Wall --trace -cc blinky.v

obj_dir/Vblinky__ALL.a: obj_dir/Vblinky.cpp
	make -C obj_dir -f Vblinky.mk

blinky: blinky.cpp obj_dir/Vblinky__ALL.a
	g++ -I${VINC} -I obj_dir/ ${VINC}/verilated.cpp ${VINC}/verilated_vcd_c.cpp  blinky.cpp obj_dir/Vblinky__ALL.a -o blinky

clean:
	rm -rf obj_dir blinkytrace.vcd blinky
