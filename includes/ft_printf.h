/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:16:22 by gthomas           #+#    #+#             */
/*   Updated: 2016/12/17 19:55:33 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ABS(value) ((value < 0) ? -(value) : (value))

# include <stdarg.h>
# include "libft.h"
# include <wchar.h>

typedef struct	s_flags
{
	char		c;
	long int	wc;
	char		*str;
	wchar_t		*wstr;
	int			flag[10];
	int			width;
	int			width_orig;
	int			prec;
	int			prec_orig;
	int			spec;
	intmax_t	tmp;
	uintmax_t	utmp;
	intmax_t	tmp_len;
	int			len;
	int			len_d;
}				t_flags;

int				ft_printf(char *fmt, ...);
void			ft_flag(t_flags *flags);
void			ft_space(t_flags *flags);
void			ft_left_justify(t_flags *flags);
int				ft_specifiers(char c);
int				ft_flags(int *i, char *fmt);
int				ft_width(int *i, char *fmt);
int				ft_precision(int *i, char *fmt);
int				ft_length(int *i, char *fmt);
void			ft_width_display_int(t_flags *flags);
void			ft_width_display_str(t_flags *flags);
void			ft_flag_display(t_flags *flags);
void			ft_prec_display_int(t_flags *flags);
void			ft_hashtag_display(t_flags *flags);
void			ft_display_int(t_flags *flags);
void			ft_display_char(t_flags *flags);
void			ft_display_str(t_flags *flags);
void			ft_width_prec_hashtag(t_flags *flags);
void			ft_width_prec_sign(t_flags *flags);
void			ft_width_prec_percent(t_flags *flags);
void			ft_cast_length(t_flags *flags, va_list ap);
void			ft_flag_prior_int(t_flags *flags);
void			ft_flag_prior_uint(t_flags *flags);
void			ft_flag_prior_c(t_flags *flags);
void			ft_flag_prior_str(t_flags *flags);
void			ft_config_0(t_flags *flags);
void			ft_config_1(t_flags *flags);
void			ft_config_2(t_flags *flags);
void			ft_config_3(t_flags *flags);
void			ft_config_4(t_flags *flags);
void			ft_config_5(t_flags *flags);
void			ft_config_6(t_flags *flags);
void			ft_config_7(t_flags *flags);
void			ft_config_8(t_flags *flags);
void			ft_config_9(t_flags *flags);
void			ft_config_10(t_flags *flags);
void			ft_config_11(t_flags *flags);
void			ft_width_backup(t_flags *flags);
void			ft_width_prec_str(t_flags *flags);
void			d_parse_str(t_flags *flags);
void			d_parse_char(t_flags *flags);
void			d_parse_int(t_flags *flags);
void			d_parse_uint(t_flags *flags);
void			ft_flags_init(t_flags *flags);
void			ft_spec_is_ok(int *i, t_flags *flags, char *fmt, va_list ap);
void			ft_flags_order(int *i, char *fmt, t_flags *flags, va_list ap);
void			ft_len(t_flags *flags, va_list ap);
void			ft_not_len_str_int(t_flags *flags, va_list ap);
void			ft_not_len_uint(t_flags *flags, va_list ap);
void			ft_not_len_ptr_c(t_flags *flags, va_list ap);
int				ft_arg_init(int *i, char *fmt, va_list ap, t_flags *flags);

#endif
