Nandflash example.

This example demonstrates use of the NANDFLASH driver.

Connect a terminal to the TTL-level serialport (115200-N-8-1). Here EXP port pin 1 
is ground, EXP port pin 4 is transmitter and EXP port pin 6 is reciever.

Operations on the flash are initiated by issuing commands on the terminal.
Command "h" will print a help screen on the terminal :

    Available commands:
        fi         : Show NAND flash device information
        h          : Show this help
        rp n       : Read page n
        bp n       : Blankcheck page n
        bd         : Blankcheck entire device
        bb         : Check bad-block info
        mb n       : Mark block n as bad
        wp n       : Write page n
        eb n       : Erase block n
        ecc n      : Check ECC algorithm, uses page n and n+1
        cp m n     : Copy page m to page n

Note that the nandflash device used on this kit has 32 pages per block, so
pages 0-31 belongs to block 0.

Board:  Silicon Labs EFM32LG-STK3600 Development Kit
Device: EFM32LG990F256
