cmd_Release/obj.target/clogger.node := flock ./Release/linker.lock g++ -shared -pthread -rdynamic -m64  -Wl,-soname=clogger.node -o Release/obj.target/clogger.node -Wl,--start-group Release/obj.target/clogger/clogger.o -Wl,--end-group 
