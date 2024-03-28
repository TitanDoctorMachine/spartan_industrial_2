
//Self generated part

if (job_id.startsWith("AUTO")) {
  #include "../../../tasks/auto.cpp"
} else

if (job_id.startsWith("DELAY")) {
  #include "../../../tasks/delay.cpp"
} else

if (job_id.startsWith("POWER_PORT_DOWN")) {
  #include "../../../tasks/power_port_down.cpp"
} else

if (job_id.startsWith("POWER_PORT_UP")) {
  #include "../../../tasks/power_port_up.cpp"
} else

if (job_id.startsWith("POWER_SUPPLIER_DOWN")) {
  #include "../../../tasks/power_supplier_down.cpp"
} else

if (job_id.startsWith("POWER_SUPPLIER_UP")) {
  #include "../../../tasks/power_supplier_up.cpp"
} else

{
  return "FAIL";
};
