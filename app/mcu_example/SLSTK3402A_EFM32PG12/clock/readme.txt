Analog and digital clock example using the Memory LCD on the SLSTK3402A.

This example project uses the EFM32 CMSIS including EMLIB and the
board support package support functions/drivers to demonstrate driving
the Sharp Memory LCD display on the SLSTK3402A kit.

The user can switch between analog and digital clock modes by pushing
the PB0 button.

The user can increment the second count by pushing the PB1 button.
The minute count can be incremented by pushing the PB1 button for more
than 2 seconds.

The analog clock mode demonstrates the use of GLIB to draw hour, minute
and second pointers.

The digital clock demonstrates the 16x20 font (including number characters
only) of the textdisplay driver.

Board:  Silicon Labs SLSTK3402A Starter Kit
Device: EFM32PG12B500F1024GL125
