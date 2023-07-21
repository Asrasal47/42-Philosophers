/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:34:53 by arasal            #+#    #+#             */
/*   Updated: 2022/12/29 22:40:09 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef long long	t_msec;

typedef struct s_philo_p
{
	int			numofphilo;
	t_msec		timetodie;
	t_msec		timetoeat;
	t_msec		timetosleep;
	t_msec		timeatstart;
	int			numtoeat;
}	t_philo_p;

typedef struct s_philo_m
{
	t_philo_p			*p;
	int					id;
	t_msec				die_time;
	t_msec				eat_time;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*first_fork;
	pthread_mutex_t		*secondfork;
	pthread_mutex_t		times_eaten_m;
	int					times_eaten;
	pthread_mutex_t		*pr;
	struct s_philo_run	*data;
}	t_philo_m;

typedef struct s_philo_run
{
	bool			is_dead;
	t_philo_m		*philos;
	pthread_t		*threads;
	int				count;
	pthread_mutex_t	printing;
}	t_philo_run;

enum	e_print {
	e_fork = 0,
	e_eating = 1,
	e_sleeping = 2,
	e_thinking = 3,
	e_dead = 4
};

//time.c
t_msec	philo_get_time(void);
void	u_wait(t_msec waiting_time);
//my_atoi.c
int		my_atoi(const char *str, int *n);
int		check_int(int sign, int *n);
//my_atoll.c
int		my_atoll(const char *str, t_msec *n);
int		check_ll(int sign, t_msec *n);
//philo_utils.c
void	init_philos(t_philo_m *philos, t_philo_p *inpparams, int i);
int		philo_r_init(t_philo_run *philo_r, t_philo_p *inpparams);
void	ft_printing(t_philo_m *m, enum e_print print);
void	clean_philo_r(t_philo_run *philo_r);
//philo_run.c
int		ft_table(t_philo_m *m);
void	*philo_routine(void *philo);
void	philo_r_create(t_philo_run *philo_r);
void	philo_r_join(t_philo_run *philo_r);
//philo_actions.c
void	ft_eating(t_philo_m *m);
void	ft_sleeping(t_philo_m *m);
void	ft_thinking(t_philo_m *m);
void	ft_dying(t_philo_m *m);

#endif