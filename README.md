# ofxAbseil

[abseil-cpp](https://github.com/abseil/abseil-cpp) for openFrameworks (tested on v0.12.0 Win/Mac/Linux/iOS, abseil version: `lts_2024_07_22`)

## Notes

- Some Windows workaround fixes (e.g. ::min(), ::max() problem, disable RawLog, etc) are applied.
- `*_test.cc`, `*_benchmark.cc`, and related files are not included in this addon.

## Usage

See [example](example). (NOTE: Please use `projectGenerator` before run it)

```cpp
#include "absl/strings/str_join.h"
#include "absl/types/optional.h"
#include "absl/hash/hash.h"
#include "absl/container/flat_hash_map.h"
#include "absl/types/any.h"

void ofApp::setup(){
    ofLogToConsole();

    // test of absl str_join

    std::vector<std::string> v = {"foo", "bar", "baz"};
    std::string s = absl::StrJoin(v, "-");

    ofLogNotice("ofApp") << "absl::StrJoin(v, \"-\") = " << s;

    // test of absl optional

    absl::optional<int> o1 = 42;
    absl::optional<int> o2 = absl::nullopt;
    
    ofLogNotice("ofApp") << "absl::optional: o1 = " << o1.value_or(0);
    ofLogNotice("ofApp") << "absl::optional: o2 = " << o2.value_or(0);
    
    // test of absl hash
    
    absl::Hash<std::string> hasher;
    std::string str = "hello";
    size_t hash = hasher(str);

    ofLogNotice("ofApp") << "absl::Hash<std::string>: hash = " << hash;

    // test of hash map of any type

    absl::flat_hash_map<std::string, absl::any> map;
    map["int"] = 42;
    map["string"] = std::string("hello");

    ofLogNotice("ofApp") << "absl::flat_hash_map<std::string, absl::any>: map[\"int\"] = " << absl::any_cast<int>(map["int"]);
    ofLogNotice("ofApp") << "absl::flat_hash_map<std::string, absl::any>: map[\"string\"] = " << absl::any_cast<std::string>(map["string"]);
}

// Result:
// [notice ] ofApp: absl::StrJoin(v, "-") = foo-bar-baz
// [notice ] ofApp: absl::optional: o1 = 42
// [notice ] ofApp: absl::optional: o2 = 0
// [notice ] ofApp: absl::Hash<std::string>: hash = 8734633936850012531
// [notice ] ofApp: absl::flat_hash_map<std::string, absl::any>: map["int"] = 42
// [notice ] ofApp: absl::flat_hash_map<std::string, absl::any>: map["string"] = hello
```

## LICENSE

Apache License 2.0

(Please check abseil [LICENSE](https://github.com/abseil/abseil-cpp/blob/master/LICENSE) for detail.)

## Side notes

- If you would like to use `std::ranges` alternative (not included in abseil), use [ofxRangeV3](https://github.com/funatsufumiya/ofxRangeV3)
