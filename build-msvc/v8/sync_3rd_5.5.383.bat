git clone https://chromium.googlesource.com/chromium/src/build          build
cd build && git checkout  67604e142e078a7797689afbfce9a04a432e943e && cd .. && pwd

git clone https://chromium.googlesource.com/external/gyp       tools/gyp
cd tools/gyp && git checkout  e7079f0e0e14108ab0dba58728ff219637458563 && cd ../.. && pwd


git clone https://chromium.googlesource.com/chromium/deps/icu   third_party/icu
cd third_party/icu  && git checkout  b0bd3ee50bc2e768d7a17cbc60d87f517f024dbe && cd ../.. && pwd


git clone https://chromium.googlesource.com/chromium/src/third_party/instrumented_libraries      third_party/instrumented_libraries
cd third_party/instrumented_libraries && git checkout  45f5814b1543e41ea0be54c771e3840ea52cca4a && cd ../.. && pwd


git clone https://chromium.googlesource.com/chromium/buildtools   buildtools
cd buildtools && git checkout  39b1db2ab4aa4b2ccaa263c29bdf63e7c1ee28aa && cd .. && pwd


git clone https://chromium.googlesource.com/chromium/src/base/trace_event/common    base/trace_event/common
cd base/trace_event/common && git checkout  e0fa02a02f61430dae2bddfd89a334ea4389f495 && cd ../../.. && pwd


git clone https://chromium.googlesource.com/chromium/src/third_party/WebKit/Source/platform/inspector_protocol     third_party/WebKit/Source/platform/inspector_protocol
cd third_party/WebKit/Source/platform/inspector_protocol && git checkout  3280c57c4c575ce82ccd13e4a403492fb4ca624b && cd ../../ ../../..


git clone https://chromium.googlesource.com/chromium/src/third_party/jinja2     third_party/jinja2
cd third_party/jinja2 && git checkout  b61a2c009a579593a259c1b300e0ad02bf48fd78 && cd ../.. && pwd


git clone https://chromium.googlesource.com/chromium/src/third_party/markupsafe    third_party/markupsafe
cd third_party/markupsafe && git checkout  484a5661041cac13bfc688a26ec5434b05d18961 && cd ../.. && pwd


git clone https://chromium.googlesource.com/external/swarming.client        tools/swarming_client
cd tools/swarming_client && git checkout  380e32662312eb107f06fcba6409b0409f8fef72 && cd ../.. && pwd


git clone https://chromium.googlesource.com/external/github.com/google/googletest      testing/gtest
cd testing/gtest && git checkout  6f8a66431cb592dad629028a50b3dd418a408c87 && cd ../.. && pwd


git clone https://chromium.googlesource.com/external/googlemock      testing/gmock
cd testing/gmock && git checkout  0421b6f358139f02e102c9c332ce19a33faf75be && cd ../.. && pwd


git clone https://chromium.googlesource.com/v8/deps/third_party/benchmarks       test/benchmarks/data
cd test/benchmarks/data && git checkout  05d7188267b4560491ff9155c5ee13e207ecd65f && cd ../../.. && pwd


git clone https://chromium.googlesource.com/v8/deps/third_party/mozilla-tests    test/mozilla/data
cd test/mozilla/data && git checkout  f6c578a10ea707b1a8ab0b88943fe5115ce2b9be && cd ../../.. && pwd


git clone https://chromium.googlesource.com/external/github.com/tc39/ecmascript_simd     test/simdjs/data
cd test/simdjs/data && git checkout  baf493985cb9ea7cdbd0d68704860a8156de9556 && cd ../../.. && pwd


git clone https://chromium.googlesource.com/external/github.com/tc39/test262        test/test262/data
cd test/test262/data && git checkout  29c23844494a7cc2fbebc6948d2cb0bcaddb24e7 && cd ../../.. && pwd


git clone https://chromium.googlesource.com/external/github.com/test262-utils/test262-harness-py       test/test262/harness
cd test/test262/harness && git checkout  cbd968f54f7a95c6556d53ba852292a4c49d11d8 && cd ../../.. && pwd


git clone https://chromium.googlesource.com/chromium/src/tools/clang      tools/clang
cd tools/clang && git checkout  1f92f999fc374a479e98a189ebdfe25c09484486 && cd ../.. && pwd


git clone https://chromium.googlesource.com/chromium/deps/cygwin      third_party/cygwin
cd third_party/cygwin && git checkout  c89e446b273697fadf3a10ff1007a97c0b7de6df && cd ../.. && pwd

pause
