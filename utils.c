#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (t1[i] == t2[i] && t1[i] && t2[i] && i + 1 < n)
		i++;
	return (t1[i] - t2[i]);
}

int	ft_nbdigit(int n)
{
	int				i;
	unsigned int	m;

	i = 0;
	if (n < 0)
	{
		m = -n;
		i++;
	}
	else
		m = n;
	if (m == 0)
		i++;
	while (m > 0)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				i;
	int				neg;
	unsigned int	m;

	i = ft_nbdigit(n);
	neg = 0;
	s = malloc(sizeof(char) * (ft_nbdigit(n)) + 1);
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		neg = 1;
		s[0] = '-';
		m = -n;
	}
	else
		m = n;
	s[i--] = '\0';
	while (i >= neg)
	{
		s[i--] = (m % 10) + 48;
		m = m / 10;
	}
	return (s);
}
