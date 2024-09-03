# offline client demo

cmake setup:

```sh
mkdir build
/snap/bin/cmake -G Ninja -B build .
pushd build && ninja all && popd
```

build & run:

```sh
ninja && LD_LIBRARY_PATH=/usr/local/lib ./main
```
