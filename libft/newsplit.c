/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:13:06 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/28 14:48:18 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		count_words(char *str)
{
	int		counter;

	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str && *str != ' ')
		{
			while (*str && *str != ' ')
				str++;
			counter++;	
		}
	}
	return (counter);
}

char	**generate_array(char *str)
{
	char	**ret;
	int		i;
	int		word_len;
	int		number_words;
	
	i = 0;
	number_words = count_words(str);
	ret = malloc(count_words(str));
	if (!ret)
		return (NULL);
	while (i < number_words)
	{
		word_len = 0;
		while (*str && *(str++) != ' ')
			word_len += 1;
		if (word_len)
			ret[i] = (char *)malloc(word_len);
		if (!ret[i])
		{
			while (number_words--)
				free(ret[number_words]);
			free(ret);
		}
		i++;
	}
	return (ret);
}

char	**split(char *str)
{
	char	**ret;
	int		i;
	int		j;

	ret = generate_array(str);
	if (!ret)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str && *str != ' ')
		{
			j = 0;
			while (*str && *str != ' ')
			{
				ret[i][j] = *str;
				j++;
				str++;
			}
			i++;
		}
		str++;
	}
}

int		main(int argc, char **argv)
{
	char	**ret;
	int		i;
	int		j;
	char	*str;
	int		n_i;
	int		n_j;

	str = argv[1];
	ret = generate_array(str);
	if (!ret)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str && *str != ' ')
		{
			j = 0;
			while (*str && *str != ' ')
			{
				ret[i][j] = *str;
				j++;
				str++;
			}
			i++;
		}
		str++;
	}
	n_i = 0;
	n_j = 0;
	while (n_i++ < i)
		while (n_j++ < j)
			write(1, &ret[n_i][n_j], 1);
}