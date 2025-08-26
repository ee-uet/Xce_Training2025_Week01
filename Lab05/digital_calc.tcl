# Basic digital design calculations 

# Define clock frequency and calculate period 

################################################### TASK change value of frequency #####################################################################

# Here i change the value of clock_frequency from 100mhz to 200mhz so definately now Time period will be decreased as frequency get increased also the power got increased and result proved this expectation.





set clock_freq_mhz 200 
set clock_period_ns [expr {1000.0 / $clock_freq_mhz}] 
puts "Clock period: $clock_period_ns ns" 

# Calculate power for a simple CMOS circuit 
proc calc_power {capacitance voltage frequency} { 
   return [expr {$capacitance * $voltage * $voltage * $frequency}] 
} 
set cap_pf 10.0 
set voltage 1.2 
set power_mw [calc_power $cap_pf $voltage $clock_freq_mhz] 
puts "Power consumption: $power_mw mW" 

# Simple timing calculation 
set prop_delay_ns 2.5 
set setup_time_ns 0.5 
set max_freq_mhz [expr {1000 / ($prop_delay_ns + $setup_time_ns)}] 
puts "Maximum frequency: $max_freq_mhz MHz"



###################################################### TASK ADD NEW CALCULATION ###############################################
#NEW CALCULATION of no of cycles 

set time_ns 1000
set num_cycles [expr {$time_ns / $clock_period_ns}]
puts "Number of cycles in 1 micro sec are : $num_cycles"
