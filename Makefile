COMPILER = g++
INCLUDE = -Iinclude/config -Iinclude/env -Iinclude/handler/ping -Iinclude/handler/user -Iinclude/mysql -Iinclude/router -I/usr/include
CFLAGS = -std=c++11 -lboost_system -lcrypto -lssl -lcpprest -lmysqlcppconn
OBJS = src/config/config.o \
	src/env/env.o \
	src/handler/ping/ping.o \
	src/handler/user/user.o \
	src/mysql/mysql.o \
	src/router/router.o \
	src/main.o

.cpp.o:
	g++ -std=c++11 -c -w $(INCLUDE) -lboost_system -lcrypto -lssl -lcpprest -lmysqlcppconn $<
all: $(OBJS)
	$(COMPILER) *.o -o main $(CFLAGS) $(LFLAGS)
clean:
	rm -rf *.o main
	
