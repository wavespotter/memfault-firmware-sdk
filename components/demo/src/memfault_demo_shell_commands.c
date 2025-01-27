//! @file
//!
//! Copyright (c) Memfault, Inc.
//! See License.txt for details
//!
//! @brief
//! Command definitions for the minimal shell/console implementation.

#include "memfault_demo_shell_commands.h"

#include <stddef.h>

#include "memfault/core/debug_log.h"
#include "memfault/core/math.h"
#include "memfault/demo/cli.h"
#include "memfault/core/compiler.h"

static int prv_panics_component_required(void) {
  MEMFAULT_LOG_RAW("Disabled. panics component integration required");
  return -1;
}

MEMFAULT_WEAK
int memfault_demo_cli_cmd_get_core(MEMFAULT_UNUSED int argc, MEMFAULT_UNUSED char *argv[]) {
  return prv_panics_component_required();
}

MEMFAULT_WEAK
int memfault_demo_cli_cmd_clear_core(MEMFAULT_UNUSED int argc, MEMFAULT_UNUSED char *argv[]) {
  return prv_panics_component_required();
}

MEMFAULT_WEAK
int memfault_demo_cli_cmd_crash(MEMFAULT_UNUSED int argc, MEMFAULT_UNUSED char *argv[]) {
  return prv_panics_component_required();
}

static const sMemfaultShellCommand s_memfault_shell_commands[] = {
  {"get_core", memfault_demo_cli_cmd_get_core, "Get coredump info"},
  {"clear_core", memfault_demo_cli_cmd_clear_core, "Clear an existing coredump"},
  {"print_chunk", memfault_demo_cli_cmd_print_chunk, "Get next Memfault data chunk to send and print as a curl command"},
  {"crash", memfault_demo_cli_cmd_crash, "Trigger a crash"},
  {"test_log", memfault_demo_cli_cmd_test_log, "Writes test logs to log buffer"},
  {"trigger_logs", memfault_demo_cli_cmd_trigger_logs, "Trigger capture of current log buffer contents"},
  {"drain_chunks",  memfault_demo_drain_chunk_data, "Flushes queued Memfault data. To upload data see https://mflt.io/posting-chunks-with-gdb"},
  {"trace", memfault_demo_cli_cmd_trace_event_capture, "Capture an example trace event"},
  {"get_device_info", memfault_demo_cli_cmd_get_device_info, "Get device info"},
  {"reboot", memfault_demo_cli_cmd_system_reboot, "Reboot system and tracks it with a trace event"},
  {"help", memfault_shell_help_handler, "Lists all commands"},
};

// Note: Declared as weak so an end user can override the command table
MEMFAULT_WEAK
const sMemfaultShellCommand *const g_memfault_shell_commands = s_memfault_shell_commands;
MEMFAULT_WEAK
const size_t g_memfault_num_shell_commands = MEMFAULT_ARRAY_SIZE(s_memfault_shell_commands);
