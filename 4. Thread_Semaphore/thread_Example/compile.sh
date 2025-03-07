export CC="gcc"
export CFLAGS="-Wunused"
export LDFLAGS="-lrt -lpthread"
export CPPFLAGS=""
export OBJ="main.o gpio.o"
export TARGET="main"

make -j