export CC="arm-linux-gnueabihf-gcc"
export CFLAGS="-Wunused"
export LDFLAGS="-lrt -lpthread"
export CPPFLAGS=""
export OBJ="main.c gpio.c"
export TARGET="main"

make -j