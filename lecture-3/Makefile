
VINC=/usr/share/verilator/include

all: walker

obj_dir/Vwalker.cpp: walker.v
	verilator -Wall --trace -cc walker.v

obj_dir/Vwalker__ALL.a: obj_dir/Vwalker.cpp
	make -C obj_dir -f Vwalker.mk

walker: walker.cpp obj_dir/Vwalker__ALL.a
	g++ -I${VINC} -I obj_dir/ ${VINC}/verilated.cpp ${VINC}/verilated_vcd_c.cpp  walker.cpp obj_dir/Vwalker__ALL.a -o walker

clean:
	rm -rf obj_dir walkertrace.vcd walker
