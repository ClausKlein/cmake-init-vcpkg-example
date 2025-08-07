# 🛠️ `cmake-presets.md` – CMake Preset Usage Guide

This guide explains how to use the CMake presets defined in `CMakePresets.json` for builds using the **Unix Makefile generator**, such as on Linux and macOS systems.

> 📌 **Requires CMake ≥ 3.21** for preset support.

---

## 🔧 Configuration Presets

Presets define how to configure your build environment. These are invoked **before building**.

### ✅ Example: Configure for CI (Linux)
```bash
cmake --preset ci-Linux
```

This will:
- Use the `Unix Makefiles` generator
- Enforce C++17 standard
- Apply strict warning flags
- Use `Release` build type

### ✅ Enable Static Analysis Tools (via Inheritance)
Use:
- `clang-tidy`
- `cppcheck`

They are automatically included in presets like `ci-ubuntu`.

```bash
cmake --preset ci-ubuntu
```

---

## 🏗️ Build Presets (Make Targets)

After configuration, run builds using:

```bash
cmake --build --preset <preset-name>
```

Examples:
- **Linux Build**: `cmake --build --preset ci-Linux`
- **macOS Build**: `cmake --build --preset ci-Darwin`
- **CI with Static Analysis**: `cmake --build --preset ci-ubuntu`

---

## 📈 Code Coverage

To build with coverage instrumentation on Linux:

```bash
cmake --preset ci-coverage
cmake --build --preset ci-coverage
```

> Ensure `ENABLE_COVERAGE=ON` is handled in your `CMakeLists.txt`.

---

## 🧪 Sanitizers

To build with AddressSanitizer + UndefinedBehaviorSanitizer:

```bash
cmake --preset ci-sanitize
cmake --build --preset ci-sanitize
```

---

## 🧪 Testing

Run tests using CTest with the same preset:
```bash
ctest --preset ci-Linux
```

Or for other platforms:
```bash
ctest --preset ci-Windows
ctest --preset ci-Darwin
```

---

## 📦 Packaging & Installation

Although `installPresets` are not defined directly, you can invoke the `install` target using:

```bash
cmake --build --preset ci-Linux --target install
```

To package (if `CPack` is configured):
```bash
cpack --preset ci-Linux
```

> You must have `install()` commands and `include(CPack)` in your `CMakeLists.txt`.

---

## 📚 Summary of Useful Presets

| Preset Name   | Platform | Purpose                               |
|---------------|----------|----------------------------------------|
| `ci-Windows`  | Windows  | Release build with strict flags        |
| `ci-Darwin`   | macOS    | Release build with Apple Clang         |
| `ci-Linux`    | Linux    | Build + Clang-Tidy + Cppcheck          |
| `ci-coverage` | Linux    | Instrumented build for code coverage   |
| `ci-sanitize` | Linux    | Build with address/UB sanitizers       |

---

## 💡 Tips

- Run `cmake --list-presets` to see all available presets.
- Use `cmake --build --preset <name> --target install` to install targets.
- Set `VCPKG_ROOT` env variable if needed (`$HOME/vcpkg`).

---

© 2025 - CMake Preset Guide
