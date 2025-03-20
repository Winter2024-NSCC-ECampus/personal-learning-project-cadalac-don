# comment with #
.global addNumbers
.func addNumbers

# Function is called addNumbers to add numbers.
addNumbers:
    add r24, r22 
    adc r25, r23
    ret
.endfunc

/* 
 *  Also, you comment like this. 
 *  You can make it multi-lined comments.
 *  This asembly took a while to get started.
*/
