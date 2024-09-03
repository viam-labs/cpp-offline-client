# offline client demo

cmake setup:

```sh
mkdir build
/snap/bin/cmake -G Ninja -B build .
```

build & run:

```sh
cd build
ninja && LD_LIBRARY_PATH=/usr/local/lib ./main
```

## set up environment variables

`main.cpp` consumes secrets from the shell environment. You can provide these through a tool like direnv or dotenv, hardcode them in the main.cpp, or export them manually as below:

```sh
export VIAM_HOST=my-robot.XZYXZYXYZ.local.viam.cloud:8080
export VIAM_API_KEY=xyzxyzxyzxyzxyzxy
export VIAM_ENTITY_ID=xxxx-xxx-xxx-xxx
```

(note: `VIAM_HOST` has `local.viam.cloud` suffix and `:8080`; these are both necessary for offline mode)

## using TLS connection while offline

In `sudo vim`, create an entry in /etc/hosts like:

```
127.0.0.1 my-robot.XZYXZYXYZ.local.viam.cloud
```

(note: this **MUST** be 'local.viam.cloud', not the normal viam.cloud address)

```sh
$ ninja && LD_LIBRARY_PATH=/usr/local/lib ./main
Resources:
	rdk:service:motion/builtin
	rdk:service:sensors/builtin
```

Then cut your wifi; you should still be able to connect.
