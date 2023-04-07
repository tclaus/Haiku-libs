/*
 * Copyright 2019-2020, Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Adrien Destugues, pulkomandy@pulkomandy.tk
 */
#ifndef _MMC_H
#define _MMC_H


#include <device_manager.h>


#define MMC_BUS_MODULE_NAME "bus_managers/mmc/driver_v1"


struct IOOperation;


enum {
	CARD_TYPE_MMC,
	CARD_TYPE_SD,
	CARD_TYPE_SDHC,
	CARD_TYPE_UHS1,
	CARD_TYPE_UHS2,
	CARD_TYPE_SDIO
};


// Commands for SD cards defined in SD Specifications Part 1:
// Physical Layer Simplified Specification Version 8.00
// They are in the common .h file for the mmc stack because the SDHCI driver
// currently needs to map them to the corresponding expected response types.
enum SD_COMMANDS {
	// Basic commands, class 0
	SD_GO_IDLE_STATE 		= 0,
	SD_ALL_SEND_CID			= 2,
	SD_SEND_RELATIVE_ADDR	= 3,
	SD_SELECT_DESELECT_CARD	= 7,
	SD_SEND_IF_COND			= 8,
	SD_SEND_CSD				= 9,
	SD_STOP_TRANSMISSION	= 12,

	// Block oriented read and write commands, class 2
	SD_READ_SINGLE_BLOCK = 17,
	SD_READ_MULTIPLE_BLOCKS = 18,

	SD_WRITE_SINGLE_BLOCK = 24,
	SD_WRITE_MULTIPLE_BLOCKS = 25,

	// Erase commands, class 5
	SD_ERASE_WR_BLK_START = 32,
	SD_ERASE_WR_BLK_END = 33,
	SD_ERASE = 38,

	// Application specific commands, class 8
	SD_APP_CMD = 55,

	// I/O mode commands, class 9
	SD_IO_ABORT = 52,
};


enum SDHCI_APPLICATION_COMMANDS {
	SD_SET_BUS_WIDTH = 6,
	SD_SEND_OP_COND = 41,
};


// Interface between mmc_bus and underlying implementation (sdhci_pci or any
// other thing that can execute mmc commands)
typedef struct mmc_bus_interface {
	driver_module_info info;

	status_t (*set_clock)(void* controller, uint32_t kilohertz);
		// Configure the bus clock. The bus is initialized with a slow clock
		// that allows device enumeration in all cases, but after enumeration
		// the mmc_bus knows how fast each card can go, and configures the bus
		// accordingly.
	status_t (*execute_command)(void* controller, uint8_t command,
		uint32_t argument, uint32_t* result);
		// Execute a command with no I/O phase
	status_t (*do_io)(void* controller, uint8_t command,
		IOOperation* operation, bool offsetAsSectors);
		// Execute a command that involves a data transfer.
	void (*set_scan_semaphore)(void* controller, sem_id sem);
		// Pass the semaphore used for device rescan to the bus controller
	void (*set_bus_width)(void* controller, int width);
		// Set the data bus width to 1, 4 or 8 bit mode.
} mmc_bus_interface;


// Interface between mmc device driver (mmc_disk, sdio drivers, ...) and mmc_bus
// This interface is rather generic as it allows implementation of drivers for
// different type of cards, which will use different commands. The bus
// provides a generic interface for all of them, and is not specific to any
// type of card.
typedef struct mmc_device_interface {
	driver_module_info info;
	status_t (*execute_command)(device_node* node, void* cookie, uint16_t rca,
		uint8_t command, uint32_t argument, uint32_t* result);
		// Execute a command with no I/O phase
	status_t (*do_io)(device_node* controller, void* cookie, uint16_t rca,
		uint8_t command, IOOperation* operation, bool offsetAsSectors);
		// Execute a command that involves a data transfer.
	void (*set_bus_width)(device_node* controller, void* cookie, int width);
		// Set the data bus width to 1, 4 or 8 bit mode.
} mmc_device_interface;


// Device attribute paths for the MMC device
const char* const kMmcRcaAttribute = "mmc/rca";
const char* const kMmcTypeAttribute = "mmc/type";


#endif /* _MMC_H */
