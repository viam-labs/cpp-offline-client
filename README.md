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

## hack for testing offline mode with TLS

With wifi disabled, this works (with /etc/hosts setup from below).

(Note `local.viam.cloud`, note `:8080`).

```sh
$ ninja && LD_LIBRARY_PATH=/usr/local/lib VIAM_HOST=my-robot.XZYXZYXYZ.local.viam.cloud:8080 ./main
Resources:
	rdk:service:motion/builtin
	rdk:service:sensors/builtin
```

This *doesn't* work:

```sh
$ ninja && LD_LIBRARY_PATH=/usr/local/lib VIAM_HOST=localhost:8080 ./main
2024-09-03T19:27:26.778504Z ERROR viam_rust_utils::ffi::dial_ffi: Error building GRPC proxy reason : Unable to connect with or without mdns.
                    with_mdns err: Some(Unable to establish connection via mDNS; uri not found)
                    without_mdns err: Some(status: Unknown, message: "transport error", details: [], metadata: MetadataMap { headers: {} }

Caused by:
    0: transport error
    1: operation was canceled: connection closed
    2: connection closed)
terminate called after throwing an instance of 'viam::sdk::Exception'
  what():  viam::sdk::Exception: Unable to establish connecting path
Aborted (core dumped)
```

For first example, create an entry in /etc/hosts like:

```
127.0.0.1 my-robot.XZYXZYXYZ.local.viam.cloud
```

note: this MUST be 'local.viam.cloud', not the normal viam.cloud address.

Then cut your wifi; you should still be able to connect.

I think, but am not sure, that this is because cpp sdk doesn't have a `disable_webrtc` like python; it [tells you to use](https://github.com/viamrobotics/viam-cpp-sdk/blob/92e0fb4c09a55676338c163c959f3284ae429fac/src/viam/examples/README.md?plain=1#L86) a rustutils feature that [detects local.viam.cloud](https://github.com/viamrobotics/rust-utils/blob/f74b798d8a0f0f427a6b523987de0a6d64f26af0/src/rpc/dial.rs#L1300-L1312).

Rust can also detect this case from `localhost`, but seems to be trying TLS and failing.
