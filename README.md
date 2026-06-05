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

### 1. Selection Sort (`--simple`)

**How it works:** On each iteration, the current minimum element in stack `a` is located by its position. The stack is then rotated — forward or backward, whichever requires fewer moves — to bring that minimum to the top, and it is pushed to stack `b`. Once stack `a` is empty, all elements are pushed back to `a` in order.

**Justification:** Selection sort is simple and predictable. It is optimal for very small inputs (≤ 5 elements) because the overhead of more complex algorithms outweighs their benefits. It is also used as a fallback for nearly-sorted inputs, where the disorder metric is low and few rotations are needed.

**Complexity:** O(n²) moves in the worst case.

-----

### 2. Chunk Sort (`--medium`)

**How it works:** Before sorting, values are **normalized** — replaced by their rank (0 to n−1) — so that the algorithm works on a contiguous range of integers regardless of the original values. Stack `a` is then divided into chunks of fixed size (15 for n ≤ 100, 35 for n > 100). Elements are pushed from `a` to `b` chunk by chunk. Within each chunk, elements that belong to the lower half of the chunk are immediately rotated to the bottom of `b` so that `b` stays roughly sorted in descending order. Once all elements are in `b`, they are pushed back to `a` greedily: at each step, the position of the maximum of `b` is found and the shorter path (rotate or reverse-rotate) is used to bring it to the top before pushing it to `a`.

**Justification:** Chunk sort achieves a much better operation count than selection sort for medium-sized inputs. The chunk size is tuned empirically: chunks of ~15 for 100 elements and ~35 for 500 elements consistently stay under the 42 project limits of 700 and 5500 operations respectively. The greedy “shortest path to max” strategy on the push-back phase minimises unnecessary rotations.

**Complexity:** O(n · n/chunk_size) ≈ O(n) passes over the stack, making it significantly better than O(n²) in practice.

-----

### 3. Radix Sort (`--complex`)

**How it works:** After normalization, this algorithm sorts using the binary representation of each rank. It proceeds bit by bit from the least significant bit (LSB) to the most significant bit needed to represent n−1. In each pass, every element at the top of stack `a` is inspected: if the current bit is `0` it is pushed to `b`, otherwise it is rotated to the bottom of `a`. After all elements have been processed, everything is pushed back from `b` to `a`. After log₂(n) passes, the stack is sorted.

**Justification:** Radix sort has a guaranteed O(n · log₂(n)) operation count, which scales very well for large inputs (n = 500). Unlike comparison-based algorithms it does not depend on the initial order of elements; each bit-pass is a full sweep of the stack. Its main drawback is that it is not particularly efficient on small or nearly-sorted inputs, which is why it is reserved for the high-disorder case in adaptive mode.

**Complexity:** O(n · log₂(n)) operations.

-----

### 4. Adaptive Router (default)

The default mode measures the **disorder** of the input — defined as the fraction of inversions among all pairs — and selects the algorithm automatically:

- **disorder < 0.2 and n < 20** → Selection Sort (input is nearly sorted; cheap to fix directly)
- **0.2 ≤ disorder < 0.5** → Chunk Sort (partially shuffled; chunk sort is efficient here)
- **disorder ≥ 0.5** → Radix Sort (highly randomised; radix’s predictable bit-passes win)

For sizes ≤ 3 dedicated hand-crafted routines are used (hard-coded optimal sequences), and for sizes ≤ 5 selection sort is used directly.

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

|Flag       |Algorithm             |
|-----------|----------------------|
|*(none)*   |Adaptive (recommended)|
|`--simple` |Selection sort        |
|`--medium` |Chunk sort            |
|`--complex`|Radix sort            |

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
./push_swap 5 3 1 4 2 | ./checker_linux(or mac) 5 3 1 4 2
```

### Counting operations

```bash
./push_swap $(shuf -i 1-100 -n 100 | tr '\n' ' ') | wc -l
```

### Error handling

The program writes `Error` to `stderr` and exits if the input contains non-integer values, integers outside the `INT` range, or duplicate values.

## Contributions

### nda-roch
- Radix sort && Normalization
- Rotate
- Reverse Rotate
- Sort_three && Sort_five

### side-oli
- Chunk sort && Chunk utils
- Selection sort && Selection utils
- Push
- Swap

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
- ft_printf

-----

## Resources

### Documentation & references

- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — visual debugger for checking your move sequence
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Sorting algorithm complexity cheatsheet](https://www.bigocheatsheet.com/)
- [italoalmeida0 tester](https://github.com/italoalmeida0/ft_ps_tester)
- [italoalmeida0 visualizer](https://github.com/italoalmeida0/ft_ps_visu)

### AI usage

AI was used during this project for the following tasks:

- **Algorithm research:** comparing the trade-offs between radix sort, chunk sort, and greedy insertion approaches for the push_swap constraints, and understanding why LSD radix sort maps naturally onto the `pb`/`pa` instruction set.

- **Disorder metric design:** exploring ways to quantify how unsorted a sequence is in order to drive the adaptive router; the inversion-fraction formula in `get_disorder.c` was refined through discussion with AI.

- **Debugging:** explaining unexpected operation counts and helping trace edge cases in the chunk-sort push-back phase.

- **README writing:** drafting and structuring this README (with content verified and edited by the authors).

AI suggestions were reviewed, discussed, tested and adapted by `nda-roch` and `side-oli` before integrating into the project.