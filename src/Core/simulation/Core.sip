set_global_assignment -entity "Core" -library "lib_Core" -name IP_TOOL_NAME "Qsys"
set_global_assignment -entity "Core" -library "lib_Core" -name IP_TOOL_VERSION "15.1"
set_global_assignment -entity "Core" -library "lib_Core" -name IP_TOOL_ENV "Qsys"
set_global_assignment -library "lib_Core" -name SPD_FILE [file join $::quartus(sip_path) "../Core.spd"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "../../Core.qsys"]

set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "Core.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_reset_controller.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_reset_synchronizer.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_reset_controller.sdc"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_irq_mapper.sv"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_mm_interconnect_0.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_sysid_qsys.vo"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_onchip_memory2.hex"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_onchip_memory2.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_nios2_cpu.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_jtag_uart.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_serial_bus_controller.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_slow_clock_generator.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_dc2.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_d5m.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_lcm.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_ltm.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_ob_de1_soc.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_ob_de2_115.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_ob_audio.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_ob_adv7180.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_av_config_auto_init_ob_adv7181.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_audio_and_video_config.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_audio_bit_counter.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_audio_in_deserializer.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_audio_out_serializer.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_clock_edge.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_up_sync_fifo.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_audio.v"]
set_global_assignment -library "lib_Core" -name MISC_FILE [file join $::quartus(sip_path) "submodules/Core_altpll_0.vo"]
