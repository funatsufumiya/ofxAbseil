# ofxAbseil

[abseil-cpp](https://github.com/abseil/abseil-cpp) for openFrameworks (tested on v0.12.0, abseil version: `lts_2024_07_22`)

## Note

Some common name header `time.h` and `utf8.h` are renamed to `absl_time.h` and `absl_utf8.h` to avoid conflict with system headers.

(If more conflicts are found, please make PR.)

## Usage

see [example](example)

## Build notes

- `*_test.cc`, `*_benchmark.cc`, and related files are not included in this addon.

## LICENSE

Apache License 2.0

(Please check abseil [LICENSE](https://github.com/abseil/abseil-cpp/blob/master/LICENSE) for detail.)