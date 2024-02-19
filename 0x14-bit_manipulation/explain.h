/**
 * Hexadecimal Number System
 * Hexa(6)decimal(10) = base 16
 * the sypbols that we use in Hexadecimal Numer System are: 0, 1, 2, 3, 4, 5, 
 *                                                  6, 7, 8, 9, A, B, C, E, F = 16 symbols
 * 
 *             128 64 32 16   8 4 2 1
 * 
 *Binary2
 * 8 4 2 1    Hex16     Decimal10
 * ------------------------------
 * 0 0 0 0-----> 0--------00
 * 0 0 0 1-----> 1--------01
 * 0 0 1 0-----> 2--------02
 * 0 0 1 1-----> 3--------03
 * 0 1 0 0-----> 4--------04
 * 0 1 0 1-----> 5--------05
 * 0 1 1 0-----> 6--------06              (1100111010011010)base2
 *                                         MSb             LSb
 * 0 1 1 1-----> 7--------07               1100 1110 1001 1010
 * 1 0 0 0-----> 8--------08                 |    |   |     |
 * 1 0 0 1-----> 9--------09                 C    E   9     A
 * 1 0 1 0-----> A--------10
 * 1 0 1 1-----> B--------11               (CE9A)base16 =  0xCE9A
 * 1 1 0 0-----> C--------12
 * 1 1 0 1-----> D--------13                 0x12 = 0001 0010 = 18
 * 1 1 1 0-----> E--------14                ~0x12 = 1110 1101 = 0xED = 237
 * 1 1 1 1-----> F--------15
 * 
 * How to convert decimal to hex:
 * ________________________          960 - (60 *16) = 0
 * | 16  |  960  |    0    |         960 ÷ 16 = 60 and remainder = 0   (60*16 = 960) 960-960=0
 * |     |   60  |   12    |          60 ÷ 16 = 3 and remainder = 12   (3*16 = 48)   60-48 = 12
 * |     |    3  |    3    |          3  ÷ 16 = 0 and remainder = 3    (0*16 = 0)    3-0 = 3
 * |     |    0  |         |           3→3, 12→C and 0→0
 *                                     Therefore, (960)10 = (3C0)16
 * Step 1: First, divide 960 by 16.
 * Step 2: Again, divide quotient 60 by 16.
 * Step 3: Again dividing 3 by 16, will leave quotient=0 and remainder = 3.
 * Step 4: Now taking the remainder in reverse order and substituting the equivalent hexadecimal value for them, we get,
 * 3→3, 12→C and 0→0
 * Therefore, (960)10 = (3C0)16
 *
 * 14/2 -> 14 % 2 = 0        remainder: Dividend - (Divisor x Quotient) 14 - (7 * 2) = 0
 * 7/2 -> 7%2 = 1                       7 - (3 * 2) = 1
 * 3/2 -> 3%2 = 1
 * 1/2 -> 1%2 = 1
 * 0
 * 
 * 98/2 -> 98%2 = 0
 * 49/2 -> 49%2 = 1
 * 24/2 -> 24%2 = 0
 * 12/2 -> 12%2 = 0
 * 6/2 -> 6%2 = 0
 * 3/2 -> 3%2 = 1
 * 1/2 -> 1%2 =1
 * 0
 * 98 = 1100010
 * 
 * How to convert hex to decimal:
 * 01001
 * 2^0 * 1 = 1
 * 2^3 * 0 = 0
 * 
 * 
 *
 * 
 *             128 64 32 16   8 4 2 1
 * EXAMPLES:
 *      0x88 & 0x01
 *  0x88 in hex is 136: 1000 1000          |  98 -> 98 ÷ 16 = 6 r 2  -> 6 ÷ 16 = 0 r 6 => 0x62
 *  0x01 in hex is 1:   0000 0001          |  ~0x98 -> 0x98 = 1001 1000 -> 0110 0111 => 0x67
 * Applying  bitwise &: 0000 0000 = 0x00   |  0x89 & 0x01 -> 1000 1001 & 0000 0001 -> 0000 0001 => 0x01
 * 0x66 & 0x22 -> 0110 0110 & 0010 0010 -> 0010 0010 =>0x22
 * 
    // 1 & 0 => 0
    // 0 & 1 => 0
    // 0 & 0 => 0
    // 1 & 1 => 1

    // 1 | 0 => 1
    // 0 | 1 => 1
    // 1 | 1 => 1
    // 0 | 0 => 0

    // 1 ^ 0 => 1
    // 0 ^ 1 => 1
    // 1 ^ 1 => 0
    // 0 ^ 0 => 0
 * 
 * Checking a bit                Example1: Find value of a bit at a given index (index = 2)
 * Using AND &                         1101 1110 <-- Data
 *                                   & 0000 0100 <-- Mask (Bit-shifted 2 Right)  1UL << 2
 *                                     0000 0100 <-- Result
 *
 * Checking a bit                Example2: Find value of a bit at a given index (index = 6)
 * Using AND &                         1011 1110 <-- Data
 *                                   & 0100 0000 <-- Mask (Bit-shifted 6 Right)
 *                                     0000 0000 <-- Result
 * 
 * Setting a bit                 Example3: Set value of a bit to 1 at a given index (index = 6)
 * Using OR |                          1011 1110 <-- Data
 *                                   | 0100 0000 <-- Mask (Bit-shifted 6 Right)
 *                                     1111 1110 <-- Result
 *
 * Setting a bit                 Example4: Set value of a bit to 0 at a given index (index = 6)
 * Using OR |                          1111 1110 <-- Data
 *                                   | 0100 0000 <-- Mask
 *                                     1011 1111 <-- we did ~
 *                                     1011 1110 <-- Result
 * 
 * Setting Multiple bits         Example5: Set value of a bit to 1 at a given index (index = 5 and 6)
 * Using OR |                          1001 1110 <-- Data
 *                                   | 0110 0000 <-- Mask
 *                                     1111 1110 <-- Result
 * 
 * Toggling/Flipping a bit       Example6: Flip value of a bit at a given index (index = 2)
 * Using OR |                          1011 1110 <-- Data
 *                                   ^ 0000 0100 <-- Mask
 *                                     1011 1010 <-- Result
 * 
 * Toggling/Flipping Multiple    Example6: Flip value of a bit at a given index (index = 2 and 6)
 * bits Using OR |                     0111 0110 <-- Data
 *                                   ^ 0100 0100 <-- Mask
 *                                     0011 0010 <-- Result
 * 
 * Toggling/Flipping all the     Example6: Flip value of all bits
 * bits Using OR |                   ! 1011 1110 <-- Data
 *                                     0100 0001 <-- Result
 *
 * Clearing a digit to 0         Example 9: Clearing digit 4 to 0
 * Using OR and NOT                         1111 0101 <-- Data
 *                                          0000 1010 <-- Flipped
 *                                        | 0001 0000 <-- Mask
 *                                          0001 1010 <-- OR result
 *                                          1110 0101 <-- Flipped Back
 * Flip the bits -> Bitwise OR -> Flip the bits
*/
