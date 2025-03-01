// SPDX-License-Identifier: BSD-2-Clause
#include <vmlinux.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

char LICENSE[] SEC("license") = "BSD";

// Function prototype declaration
int stackable_args_subcall(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

SEC("kprobe")
int stackable_args(struct pt_regs *ctx)
{
	int result = stackable_args_subcall(1, 2, 3, 4, 5, 6, 7, 8, 9, -46);
	bpf_printk("result: %d\n", result);
	return 0;
}

int stackable_args_subcall(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
	bpf_printk("a: %d, b: %d, c: %d, d: %d, e: %d, f: %d, g: %d, h: %d, i: %d, j: %d\n", a, b, c, d, e, f, g, h, i, j);
	return a + b + c + d + e + f + g + h + i + j;
}
