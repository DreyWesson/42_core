int	strspn(const char *s, const char *charset)
{
	int i = 0;
	int j = 0;

	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}