# Query Optimizer Simulation

A C++ implementation demonstrating cost-based query optimization for join algorithms.

## Features
- *Query Parsing*: Basic SQL parser for SELECT/JOIN/WHERE
- *Cost Estimation*: Chooses between Hash Join, Merge Join, Nested Loop
- *Execution Planning*: Generates step-by-step query plan

## Build & Run
```bash
make && ./query_optimizer
