/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:38:45 by mgould            #+#    #+#             */
/*   Updated: 2016/11/06 18:49:59 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == '\0')
		return (0);
	else if ((*s2 == '*') && (*s1 != '\0'))
		return (match((s1 + 1), s2) || match((s1), (s2 + 1)));
	else if (*s1 == *s2)
	{
		s1++;
		s2++;
		return (match(s1, s2));
	}
	else if (*s2 == '\0')
		return (0);
	else if (*s1 == '\0' && *s2 == '*')
		return (match(s1, (s2 + 1)));
	else if (*s1 != *s2)
		return (0);
	return (1);
}
