
# (C) 2001-2015 Altera Corporation. All rights reserved.
# Your use of Altera Corporation's design tools, logic functions and 
# other software and tools, and its AMPP partner logic functions, and 
# any output files any of the foregoing (including device programming 
# or simulation files), and any associated documentation or information 
# are expressly subject to the terms and conditions of the Altera 
# Program License Subscription Agreement, Altera MegaCore Function 
# License Agreement, or other applicable license agreement, including, 
# without limitation, that your use is for the sole purpose of 
# programming logic devices manufactured by Altera and sold by Altera 
# or its authorized distributors. Please refer to the applicable 
# agreement for further details.

# ACDS 15.1 185 linux 2015.11.16.22:30:56

# ----------------------------------------
# vcs - auto-generated simulation script

# ----------------------------------------
# This script can be used to simulate the following IP:
#     Core
# To create a top-level simulation script which compiles other
# IP, and manages other system issues, copy the following template
# and adapt it to your needs:
# 
# # Start of template
# # If the copied and modified template file is "vcs_sim.sh", run it as:
# #   ./vcs_sim.sh
# #
# # Override the top-level name
# # specify a command file containing elaboration options 
# # (system verilog extension, and compile the top-level).
# # Override the user-defined sim options, so the simulation 
# # runs forever (until $finish()).
# source vcs_setup.sh \
# TOP_LEVEL_NAME=top \
# USER_DEFINED_ELAB_OPTIONS="'-f ../../../synopsys_vcs.f'" \
# USER_DEFINED_SIM_OPTIONS=""
# 
# # helper file: synopsys_vcs.f
# +systemverilogext+.sv
# ../../../top.sv
# # End of template
# ----------------------------------------
# If Core is one of several IP cores in your
# Quartus project, you can generate a simulation script
# suitable for inclusion in your top-level simulation
# script by running the following command line:
# 
# ip-setup-simulation --quartus-project=<quartus project>
# 
# ip-setup-simulation will discover the Altera IP
# within the Quartus project, and generate a unified
# script which supports all the Altera IP within the design.
# ----------------------------------------
# ACDS 15.1 185 linux 2015.11.16.22:30:56
# ----------------------------------------
# initialize variables
TOP_LEVEL_NAME="Core"
QSYS_SIMDIR="./../../"
QUARTUS_INSTALL_DIR="/opt/altera/quartus/"
SKIP_FILE_COPY=0
SKIP_ELAB=0
SKIP_SIM=0
USER_DEFINED_ELAB_OPTIONS=""
USER_DEFINED_SIM_OPTIONS="+vcs+finish+100"
# ----------------------------------------
# overwrite variables - DO NOT MODIFY!
# This block evaluates each command line argument, typically used for 
# overwriting variables. An example usage:
#   sh <simulator>_setup.sh SKIP_ELAB=1 SKIP_SIM=1
for expression in "$@"; do
  eval $expression
  if [ $? -ne 0 ]; then
    echo "Error: This command line argument, \"$expression\", is/has an invalid expression." >&2
    exit $?
  fi
done

# ----------------------------------------
# initialize simulation properties - DO NOT MODIFY!
ELAB_OPTIONS=""
SIM_OPTIONS=""
if [[ `vcs -platform` != *"amd64"* ]]; then
  :
else
  :
fi

# ----------------------------------------
# copy RAM/ROM files to simulation directory
if [ $SKIP_FILE_COPY -eq 0 ]; then
  cp -f $QSYS_SIMDIR/submodules/Core_onchip_memory2.hex ./
fi

vcs -lca -timescale=1ps/1ps -sverilog +verilog2001ext+.v -ntb_opts dtm $ELAB_OPTIONS $USER_DEFINED_ELAB_OPTIONS \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/altera_primitives.v \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/220model.v \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/sgate.v \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/altera_mf.v \
  $QUARTUS_INSTALL_DIR/eda/sim_lib/altera_lnsim.sv \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/cycloneive_atoms.v \
  $QSYS_SIMDIR/submodules/altera_reset_controller.v \
  $QSYS_SIMDIR/submodules/altera_reset_synchronizer.v \
  $QSYS_SIMDIR/submodules/Core_irq_mapper.sv \
  $QSYS_SIMDIR/submodules/Core_mm_interconnect_0.v \
  $QSYS_SIMDIR/submodules/Core_sysid_qsys.vo \
  $QSYS_SIMDIR/submodules/Core_onchip_memory2.v \
  $QSYS_SIMDIR/submodules/Core_nios2_cpu.v \
  $QSYS_SIMDIR/submodules/Core_jtag_uart.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_serial_bus_controller.v \
  $QSYS_SIMDIR/submodules/altera_up_slow_clock_generator.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_dc2.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_d5m.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_lcm.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_ltm.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_ob_de1_soc.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_ob_de2_115.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_ob_audio.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_ob_adv7180.v \
  $QSYS_SIMDIR/submodules/altera_up_av_config_auto_init_ob_adv7181.v \
  $QSYS_SIMDIR/submodules/Core_audio_and_video_config.v \
  $QSYS_SIMDIR/submodules/altera_up_audio_bit_counter.v \
  $QSYS_SIMDIR/submodules/altera_up_audio_in_deserializer.v \
  $QSYS_SIMDIR/submodules/altera_up_audio_out_serializer.v \
  $QSYS_SIMDIR/submodules/altera_up_clock_edge.v \
  $QSYS_SIMDIR/submodules/altera_up_sync_fifo.v \
  $QSYS_SIMDIR/submodules/Core_audio.v \
  $QSYS_SIMDIR/submodules/Core_altpll_0.vo \
  $QSYS_SIMDIR/Core.v \
  -top $TOP_LEVEL_NAME
# ----------------------------------------
# simulate
if [ $SKIP_SIM -eq 0 ]; then
  ./simv $SIM_OPTIONS $USER_DEFINED_SIM_OPTIONS
fi
