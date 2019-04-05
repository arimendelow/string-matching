/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_wcomments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:09:56 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:02:55 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** Purpose of this function is to find out whether two strings match
** s1 and s2 are considered to match when s1 and s2 are identical
** if s2 contains a star (*), we can replace this star by any character's string
**		to make s1 and s2 identical
** s2 may hold as many stars as you'd like
** for example, "main.c" and "*.c" match because it is possible to replace "*"
**		by the string "main" to render those two string identical
**
** return 1 if s1 and s2 match, or 0 if they don't.
*/

int		match(char *s1, char *s2)
{
	// base case: at the end of either string, or at a point where we know they don't match.
	// if we've made it to the end of both strings, they match.
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	// otherwise, we already know that the current characters do not match. If the current character
	//		in s2 is a *, check that it matches.
	if (*s2 == '*')
	{
		// if next character after star is null terminator, consider that a match.
		if (*(s2 + 1) == '\0')
			return (1);
		// iterate through s1 until we find a start point that matches,
		//		or we find the end of s1, in which case they do not match.
		while (*s1 != '\0' && !match((s1), (s2 + 1)))
			s1++;
		if (match((s1), (s2 + 1)))
			return (1);
		else
			return (0);
	}
	// go through the strings.
	// if we encounter a star, iterate through s1, checking from its index
	//		until the end of the string, if it matches until the next star.
	// iterate each index as long as the character
	//		at the current indices are equal to each other.
	else if (*s1 == *s2)
		return (match(++s1, ++s2));
	else
		return (0);
}
