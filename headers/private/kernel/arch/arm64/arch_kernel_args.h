/*
** Copyright 2021 Haiku, Inc. All rights reserved.
** Distributed under the terms of the MIT License.
*/
#ifndef KERNEL_ARCH_ARM64_KERNEL_ARGS_H
#define KERNEL_ARCH_ARM64_KERNEL_ARGS_H

#ifndef KERNEL_BOOT_KERNEL_ARGS_H
#	error This file is included from <boot/kernel_args.h> only
#endif


#include <util/FixedWidthPointer.h>
#include <boot/interrupt_controller.h>
#include <boot/uart.h>


#define _PACKED __attribute__((packed))

#define MAX_VIRTUAL_RANGES_TO_KEEP	32

typedef struct {
	uint64	phys_pgdir;
	uint64	vir_pgdir;
	uint64	next_pagetable;

	// The virtual ranges we want to keep in the kernel.
	uint32		num_virtual_ranges_to_keep;
	addr_range	virtual_ranges_to_keep[MAX_VIRTUAL_RANGES_TO_KEEP];

	// needed for UEFI, otherwise kernel acpi support can't find ACPI root
	FixedWidthPointer<void>	acpi_root;
	FixedWidthPointer<void>	fdt;

	uart_info	uart;
	intc_info	interrupt_controller;

} _PACKED arch_kernel_args;

#endif	/* KERNEL_ARCH_ARM64_KERNEL_ARGS_H */
