// Test.c
#include "../include/Oyun.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../include/Koloni.h"
#include <time.h>

//char* uzunlugu bulma
size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	while (i < len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_wordcounter(const char *str, char c)
{
	int	i;
	int	c_mi;

	i = 0;
	c_mi = 0;
	while (*str)
	{
		if (*str != c && c_mi == 0)
		{
			c_mi = 1;
			i++;
		}
		else if (*str == c)
			c_mi = 0;
		str++;
	}
	return (i);
}

int	ft_charcounter(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str && (*str != c))
	{
		i++;
		str++;
	}
	return (i);
}

//diziyi ayırma fonksiyonu
char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		retindex;

	retindex = 0;
	if (!str)
		return (0);
	ret = malloc(sizeof(char *) * ft_wordcounter(str, c) + 1);
	if (!ret)
		return (0);
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str == '\0')
			break ;
		ret[retindex] = ft_substr(str, 0, ft_charcounter(str, c));
		retindex++;
		str += ft_charcounter(str, c);
	}
	ret[retindex] = NULL;
	return (ret);
}

int main()
{
    char str[100];
    char **token;

	srand(time(NULL)); //rastgele sayi uretimi icin tohum
    fgets(str, 100, stdin); //kullanici girdisi
    token = ft_split(str, ' '); //kullanici girdisini bosluklara gore ayirma

    yenioyun(token); //koloni simulasyonumuz

    return (0);
}
