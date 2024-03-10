int fact_loop(int n) {
	int result = 1;
	int i = 2;
	while(i < n) {
		result = result * i;
		i = i + 1;
	}
	return result;
}

int fact_rec(int n) {
	if(n == 0) return 1;
	else return n*fact_rec(n-1);
}
