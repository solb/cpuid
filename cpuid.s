.globl cpuid_query
# %rdi : cpuid_feat_flags_t *buf
# %esi : unsigned leaf
# %edx : unsigned subleaf
cpuid_query:
	pushq %rbx

	movl  %esi, %eax
	movl  %edx, %ecx
	cpuid
	movl  %eax,  0(%rdi)
	movl  %ecx,  4(%rdi)
	movl  %ebx,  8(%rdi)
	movl  %edx, 12(%rdi)

	popq  %rbx
	ret
