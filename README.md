Just me playing around to understand the classic Quake calculation of the inverse square root of a number.

# Theory

Float bit representation IEEE-754
s e e e e e e e e m m m m m m m m m m m m m m m m m m m m m m m

sign exponent        mantissa

Seen as pure bits the exponent is just a 8-bit integer `E`, similarly
the mantissa is a 23-bit integer, `M`. 

The floating point interpretation of the exponent is to see it as a value
`e` in the interval `[-127, 128]`, i.e. `e = E - B` where `B = 127`.

The floating point value of the mantissa is a value `m` in the interval
`[0, 1)`. The first bit of the mantissa has the value `1/2`, the second `1/4` etc.
. I.e. `m = M/L` where `L = 2**23`. Finally the mantissa is actually incremented by one but as an optimizition the one is not represented in the bit field.

The value of the floating point number is given by:
`(1 + m)2**e`

The integer representation of the number has the value:
`M + LE` 

... ToDo ...
         
        
         
        
         
         
        
         
         
         
         
         
         
         
        
         
         
        
         
         
        
        
        
         
        
        
        /
