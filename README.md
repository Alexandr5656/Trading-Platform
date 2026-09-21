# Trading-Platform

Semester-long capstone for a quant/low-latency infra course. This is a layered research and
execution platform: a Python layer for strategy definition, orchestration, backtesting, and
Alpaca paper-trading integration; a C++ core for the performance-sensitive pieces (event
processing, order book, matching engine, market-data parsing); and, starting mid-semester,
selective Rust components (market-data ingestion/replay, binary protocol parsing) chosen and
justified individually rather than as a wholesale rewrite. No real money is ever used — paper
trading only. Python dependencies are tracked in `requirements.txt`; the C++ build uses CMake
with warnings-as-errors enforced (`-Wall -Wextra -Werror` on GCC/Clang, `/W4 /WX` on MSVC).

## Building

```
cmake -S . -B build
cmake --build build
```

## Layout

- `cpp/week01/` — Week 1 C++ fundamentals exercises (stack vs. heap, const-correctness).
- `requirements.txt` — Python environment definition.
