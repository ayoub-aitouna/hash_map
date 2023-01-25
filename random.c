#include <stdio.h>

int hash(char *s)
{
	unsigned int hash_code;
	
	hash_code = 0xD8FEA3AA;
	while (*s)
		hash_code = 31 * (hash_code ^ *s++);
	return (hash_code);
}


int main(){
	
}