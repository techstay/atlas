# C++ Third-party Libraries Example Collection

Collection of practical usage examples for popular C++ third-party libraries, organized by library categories. Each example is a standalone runnable program demonstrating a single feature. All examples are written in modern C++23 standard (supports `std::print`, structured bindings, `auto`, `constexpr` and other new features).

## Directory Structure

- **[boost/](src/boost/)** — Comprehensive Boost library examples, organized by modules:
  - `01_core` — Core utilities: smart pointers, function/bind, error_code, uuid, optional, variant, any
  - `02_string` — String processing: format, lexical_cast, string_algo, tokenizer
  - `03_container` — Extended containers: circular_buffer, bimap, multi_index, dynamic_bitset
  - `04_data` — Data processing: property_tree serialization/deserialization
  - `05_async` — Asynchronous programming: lockfree queue, signals2 signal-slot
  - `06_utility` — Utility tools: endian byte order processing
- **[spdlog/](src/spdlog/)** — spdlog high-performance logging library examples:
  - `01_basic_logging` — Basic logging functionality usage

## Build and Run

### Prerequisites
- xmake build tool
- Boost library (xmake configured to automatically download dependencies)
- spdlog library (xmake configured to automatically download dependencies)

### Build all examples
```sh
xmake
```

### Run single example
```sh
xmake run <example-name>

# Example: run Boost smart pointer example
xmake run boost_01_core_02_smart_ptr

# Example: run spdlog basic logging example
xmake run spdlog_01_basic_logging
```

All `.cpp` files under the `src/` directory will be automatically recognized as independent executable targets.
