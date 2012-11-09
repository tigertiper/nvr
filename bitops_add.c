/*inline*/ int
bit(char *addr, int nr)
{
	return (addr[nr >> 3] & (1 << (nr & 7))) != 0;
}

/*inline*/ int
setbit_(char *addr, int nr)
{
	int __res = bit(addr, nr);
	addr[nr >> 3] |= (1 << (nr & 7));
	return __res != 0;
}

/*inline*/ int
clrbit_(char *addr, int nr)
{
	int __res = bit(addr, nr);
	addr[nr >> 3] &= ~(1 << (nr & 7));
	return __res != 0;
}

/*inline*/ int
find_first_zero(char *addr, int nr)
{
	int i = 0;
	while (i < nr) {
		if (!bit(addr, i))
			break;
		i++;
	}
	return i;
}
