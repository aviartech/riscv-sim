# RISC-V Instruction Set Simulator

## Project Overview

This project implements a CPU simulator that can parse and execute a subset of RISC-V instructions — with a special focus on AI-style vector workloads. The goal is to provide a hands-on, extensible environment to explore CPU architecture concepts such as registers, memory, pipelines, and performance counters — without needing real hardware.

## Objectives

- **Simulate a basic CPU core with:**
  - Scalar registers: `r0`–`r7`
  - Vector registers: `v0`–`v3`
  - A simple memory model (load/store operations)
- **Support a minimal RISC-V-like instruction set:**
  - Scalar: `ADD`, `SUB`, `MUL`, `DIV`, `LOAD`, `STORE`
  - Vector: `VADD`, `VMUL`
- Implement a text-based instruction loader that parses a program file (like assembly) and executes instructions sequentially.
- Simulate a basic pipeline: **Fetch → Decode → Execute**
- Track performance counters (e.g., cycle count, instruction count).
- Print the final register and memory state for verification.

## Project Plan

### Phase 1 – Core Simulator
- [x] Define register file & memory model  
- [x] Implement parser for instruction file  
- [x] Implement instruction decoder & executor  
- [ ] Add basic pipeline (fetch/decode/execute stages)  
- [ ] Add performance counters (cycle count, IPC)  

### Phase 2 – Extensibility
- [ ] Add support for multiple instruction-set variants (e.g., scalar-only, scalar+vector)  
- [ ] Implement configurable memory size & layout  
- [ ] Allow user to choose which ISA variant to load at runtime  

### Phase 3 – AI Workload Simulation
- [ ] Implement simple vectorized operations for workloads (e.g., vector dot-product)  
- [ ] Compare performance across ISA variants  

### Phase 4 – Visualization (Stretch Goal)
- [ ] Display pipeline stages per cycle (like a Gantt chart)  
- [ ] Export performance data (CSV or JSON) for analysis  

