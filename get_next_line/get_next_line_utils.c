#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_strclen(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str == c || !c)
		return (str);
	return (0);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*ret;
	int		len;
	char	*temp;
	char	*tmp_dest;

	len = ft_strlen(dest) + ft_strlen(src);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
	{
		free(dest);
		return (NULL);
	}
	temp = ret;
	tmp_dest = dest;
	while (dest != NULL && *dest)
	{
		*ret = *dest;
		ret++;
		dest++;
	}
	while (*src)
	{
		*ret = *src;
		ret++;
		src++;
	}
	*ret = '\0';
	if (tmp_dest)
		free(tmp_dest);
	return (temp);
}

char	*ft_strndup(char *str, int n)
{
	char	*ret;
	int		i;
	
	i = 0;
	ret = malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (str[i] != '\0' && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	int		n;

	if (!nmemb && !size && nmemb > (2147483647 / size))
		return (NULL);
	dest = malloc(size * nmemb);
	if (!dest)
		return (NULL);
	n = nmemb * size;
	while (n > 0)
	{
		*((char *)dest++) = 0;
		n--;
	}
	return (dest);
}


// int main(void)
// {
	// char *str1 = malloc(5);
	// char *tmp = str1;
	// char *buf = "Joao";
	// while (*buf)
		// *(str1++) = *(buf++);
// 
	// char *str2 = "ao";
	// printf("%s", ft_strjoin(tmp, str2));
// }
