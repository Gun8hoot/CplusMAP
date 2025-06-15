
int check_ip(char *IP) {
	int dot;
	int count;
	
	count = 0;
	dot = 0;
	while (IP[count] != '\0') {
		if (IP[count] == '.')
		{
			dot++;
		}
		count++;
	}
	
	if (dot == 3) {
		return (0);
	}
	else {
		
		return (1);
	}
}
