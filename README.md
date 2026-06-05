*This project has been created as part of the 42 curriculum by nda-roch, side-oli.*

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations, while producing the **fewest possible number of moves**.

The program reads a list of integers from the command line, builds a linked-list stack, and outputs to `stdout` the sequence of operations needed to sort stack `a` in ascending order.

### Available operations

|Operation|Effect                                     |
|---------|-------------------------------------------|
|`sa`     |Swap the top two elements of stack a       |
|`sb`     |Swap the top two elements of stack b       |
|`ss`     |`sa` and `sb` simultaneously               |
|`pa`     |Push top of stack b onto stack a           |
|`pb`     |Push top of stack a onto stack b           |
|`ra`     |Rotate stack a upward (top becomes bottom) |
|`rb`     |Rotate stack b upward                      |
|`rr`     |`ra` and `rb` simultaneously               |
|`rra`    |Reverse rotate stack a (bottom becomes top)|
|`rrb`    |Reverse rotate stack b                     |
|`rrr`    |`rra` and `rrb` simultaneously             |

-----

## Algorithms

This project implements **three sorting strategies** and an **adaptive router** that selects the best one automatically based on input size and disorder level.

### 1. Selection Sort (`--simple`) — O(n²)

**How it works:** On each iteration, the position of the minimum element in stack `a` is located using `get_min_pos()`. The stack is then rotated — forward (`ra`) or backward (`rra`), whichever requires fewer moves — to bring that minimum to the top, and it is pushed to stack `b` (`pb`). Once stack `a` is empty, all elements are pushed back to `a` (`pa`) in sorted order.

**Justification:** Selection sort is simple and predictable. It is optimal for very small inputs (≤ 5 elements) because the overhead of more complex algorithms outweighs their benefits. It is also used as a fallback for nearly-sorted inputs, where the disorder metric is low and few rotations are needed.

**Complexity:** O(n²) moves in the worst case — each of the n elements requires up to n rotations to locate and bring to the top.

-----

### 2. Chunk Sort (`--medium`) — O(n√n)

**How it works:** Before sorting, values are **normalized** — replaced by their rank (0 to n−1) via `normalize()` — so that the algorithm works on a contiguous range of integers regardless of the original values. Stack `a` is then divided into chunks of fixed size (15 for n ≤ 100, 35 for n > 100). Elements are pushed from `a` to `b` chunk by chunk. Within each chunk, elements that belong to the lower half of the chunk are immediately rotated to the bottom of `b` (`rb`) so that `b` stays roughly sorted in descending order. Once all elements are in `b`, they are pushed back to `a` greedily: the position of the maximum of `b` is found using `get_max_pos()` and the shorter path (rotate or reverse-rotate) is used to bring it to the top before pushing it to `a`.

**Justification:** Chunk sort achieves a much better operation count than selection sort for medium-sized inputs. The chunk size is tuned empirically: chunks of ~15 for 100 elements and ~35 for 500 elements consistently stay under the 42 project limits of 700 and 5500 operations respectively. With an optimal chunk size proportional to √n, the total operation count is O(n√n).

**Complexity:** O(n√n) — n elements distributed across √n chunks, each requiring O(√n) rotations on average.

-----

### 3. Radix Sort (`--complex`) — O(n log n)

**How it works:** After normalization, this algorithm sorts using the binary representation of each rank. It proceeds bit by bit from the least significant bit (LSB) to the most significant bit needed to represent n−1. In each pass, every element at the top of stack `a` is inspected: if the current bit is `0` it is pushed to `b` (`pb`), otherwise it is rotated to the bottom of `a` (`ra`). After all elements have been processed, everything is pushed back from `b` to `a` (`pa`). After log₂(n) passes, the stack is sorted.

**Justification:** Radix sort has a guaranteed O(n log₂(n)) operation count, which scales very well for large inputs (n = 500). Unlike comparison-based algorithms it does not depend on the initial order of elements; each bit-pass is a full sweep of the stack. Its main drawback is that it is not particularly efficient on small or nearly-sorted inputs, which is why it is reserved for the high-disorder case in adaptive mode.

**Complexity:** O(n · log₂(n)) — log₂(n) bit-passes, each touching all n elements.

-----

### 4. Adaptive Router (default)

The default mode measures the **disorder** of the input — defined as the fraction of inversions among all pairs, computed in `get_disorder.c` — and selects the algorithm automatically:

- **disorder < 0.2 and n < 20** → Selection Sort (input is nearly sorted; cheap to fix directly)
- **0.2 ≤ disorder < 0.5** → Chunk Sort (partially shuffled; chunk sort is efficient here)
- **disorder ≥ 0.5** → Radix Sort (highly randomised; radix's predictable bit-passes win)

For n = 2, a single `sa` is used. For n = 3, a hand-crafted `sort_three()` covers all 6 permutations with at most 2 operations. For n ≤ 5, `sort_five()` pushes the two smallest elements to `b`, calls `sort_three()`, then pushes them back.

-----

## Instructions

### Requirements

- GCC (or any C99-compatible compiler)
- GNU Make
- A Unix-like system (Linux, macOS)

### Compilation

```bash
git clone <repository-url>
cd push_swap
make
```

This produces the `push_swap` executable. The nested `libft/ft_printf` library is compiled automatically.

### Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Full recompile from scratch
```

### Usage

```bash
./push_swap [FLAGS] <integers>
```

Arguments can be passed as separate tokens or as a single quoted string:

```bash
./push_swap 5 3 1 4 2
./push_swap "5 3 1 4 2"
```

#### Strategy flags (optional)

|Flag         |Algorithm             |
|-------------|----------------------|
|*(none)*     |Adaptive (recommended)|
|`--simple`   |Selection sort        |
|`--medium`   |Chunk sort            |
|`--complex`  |Radix sort            |
|`--adaptive` |Adaptive (explicit)   |

#### Benchmark flag

```bash
./push_swap --bench 5 3 1 4 2
```

Prints a detailed report to `stderr` with the total number of operations, a breakdown by operation type, the disorder score, and the strategy used. Can be combined with a strategy flag:

```bash
./push_swap --bench --medium 42 7 13 99 2
```

### Piping with a checker

```bash
# Linux:
./push_swap 5 3 1 4 2 | ./checker_linux 5 3 1 4 2
# macOS:
./push_swap 5 3 1 4 2 | ./checker_Mac 5 3 1 4 2
```

### Counting operations

```bash
./push_swap $(shuf -i 1-100 -n 100 | tr '\n' ' ') | wc -l
```

### Error handling

The program writes `Error` to `stderr` and exits with a non-zero status if the input contains non-integer values, integers outside the `INT` range, or duplicate values.

-----

## Repository structure

```
push_swap/
├── Makefile
├── README.md
├── incs/
│   └── push_swap.h              # All structs, enums, and function prototypes
├── srcs/
│   ├── main.c                   # Entry point: flag parsing, stack init, routing
│   ├── setup.c                  # Flag parsing, argument validation, stack building
│   ├── parse.c                  # Integer validation and duplicate detection
│   ├── utils.c                  # ft_atol, ft_strcmp, stack_size, is_sorted, free_stack
│   ├── node_management.c        # Linked-list node allocation (new_node, move_to_top)
│   ├── normalize.c              # Value → rank mapping (0 to n−1)
│   ├── get_disorder.c           # Inversion-fraction disorder metric
│   ├── get_pos.c                # get_min_pos / get_max_pos utilities
│   ├── routing.c                # Adaptive algorithm router and bench initialisation
│   ├── sort_three.c             # Hard-coded optimal sort for n ≤ 3
│   ├── sort_five.c              # Min-push strategy for n ≤ 5
│   ├── selection_sort.c         # O(n²) selection sort
│   ├── chunk_sort.c             # O(n√n) chunk sort
│   ├── radix_sort.c             # O(n log n) LSD radix sort
│   ├── push.c                   # pa / pb operations
│   ├── swap.c                   # sa / sb / ss operations
│   ├── rotate.c                 # ra / rb / rr operations
│   ├── rrotate.c                # rra / rrb / rrr operations
│   ├── benchmark.c              # --bench report printing
│   └── bench_utils.c            # ft_putstr_fd / ft_putnbr_fd helpers for benchmark
└── libft/
    └── ft_printf/               # Custom printf implementation
        ├── Makefile
        ├── ft_printf.h
        └── srcs/
            ├── ft_printf.c
            ├── ft_conversion.c
            ├── ft_putchar.c
            ├── ft_puthex.c
            ├── ft_putnbr.c
            ├── ft_putnbr_u.c
            ├── ft_putptr.c
            └── ft_putstr.c
```

-----

## Contributions

### nda-roch
- Radix sort & Normalization
- Rotate
- Reverse Rotate
- Sort_three & Sort_five
- ft_printf

### side-oli
- Chunk sort & Chunk utils
- Selection sort & Selection utils
- Push
- Swap
- Disorder calculation

### Both
- Algorithm choice discussion
- Optimization
- Code restructuring and cleanup
- Debugging
- Benchmark function
- Utils
- Main function
- Header
- Makefile

-----

## Resources

### Documentation & references

- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Sorting algorithm complexity cheatsheet](https://www.bigocheatsheet.com/)
- [Push_swap visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer) — visual debugger for checking your move sequence
- [ft_ps_tester by italoalmeida0](https://github.com/italoalmeida0/ft_ps_tester)
- [ft_ps_visu by italoalmeida0](https://github.com/italoalmeida0/ft_ps_visu)

### AI usage

AI was used during this project for the following tasks:

- **Algorithm research:** comparing the trade-offs between radix sort, chunk sort, and greedy insertion approaches for the push_swap constraints, and understanding why LSD radix sort maps naturally onto the `pb`/`pa` instruction set.

- **Disorder metric design:** exploring ways to quantify how unsorted a sequence is in order to drive the adaptive router; the inversion-fraction formula in `get_disorder.c` was refined through discussion with AI.

- **Debugging:** explaining unexpected operation counts and helping trace edge cases in the chunk-sort push-back phase.

- **README writing:** drafting and structuring this README (with content verified and edited by the authors).

AI suggestions were reviewed, discussed, tested and adapted by `nda-roch` and `side-oli` before integrating into the project.