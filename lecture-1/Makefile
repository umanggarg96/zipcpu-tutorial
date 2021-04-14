
all:
	verilator -Wall -cc thruwire.v
	cd obj_dir
	make -f obj_dir/Vthruwire.mk
	g++ -I /usr/share/verilator/include -I obj_dir/ /usr/share/verilator/include/verilated.cpp thruwire.cpp obj_dir/Vthruwire__ALL.a -o thruwire
