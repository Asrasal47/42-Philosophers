/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:01:54 by arasal            #+#    #+#             */
/*   Updated: 2022/12/29 22:39:51 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_table(t_philo_m *m)
{
	pthread_mutex_lock(m->first_fork);
	if (philo_get_time() + m->p->timetoeat <= m->die_time
		&& (m->times_eaten < m->p->numtoeat || m->p->numtoeat == -1))
		ft_eating(m);
	else
	{
		pthread_mutex_unlock(m->first_fork);
		if (philo_get_time() + m->p->timetoeat > m->die_time)
			ft_dying(m);
		return (0);
	}
	if (philo_get_time() + m->p->timetosleep > m->die_time)
	{
		m->die_time -= m->p->timetoeat;
		ft_dying(m);
		return (0);
	}
	else
		ft_sleeping(m);
	ft_thinking(m);
	return (1);
}

void	*philo_routine(void *philo)
{
	t_philo_m	*m;

	m = (t_philo_m *)philo;
	m->die_time = m->p->timeatstart + m->p->timetodie;
	if (m->id % 2 == 0)
		u_wait(philo_get_time() + m->p->timetoeat);
	while (1)
	{
		if (ft_table(m) == 0 || m->data->is_dead == 1)
			return (NULL);
	}
	return (NULL);
}

void	philo_r_create(t_philo_run *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_create(&philo_r->threads[i], NULL, philo_routine,
			(void *)&philo_r->philos[i]);
		i++;
	}
}

void	philo_r_join(t_philo_run *philo_r)
{
	int	i;

	i = 0;
	while (i < philo_r->count)
	{
		pthread_join(philo_r->threads[i], NULL);
		i++;
	}
}
