/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:51 by arasal            #+#    #+#             */
/*   Updated: 2023/04/20 15:41:27 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo_m *m)
{
	ft_printing(m, 0);
	pthread_mutex_lock(m->secondfork);
	ft_printing(m, 0);
	ft_printing(m, 1);
	m->die_time = philo_get_time() + m->p->timetodie + m->p->timetoeat;
	u_wait(philo_get_time() + m->p->timetoeat);
	if (m->p->numtoeat != -1)
		m->times_eaten += 1;
	pthread_mutex_unlock(m->secondfork);
	pthread_mutex_unlock(m->first_fork);
}

void	ft_sleeping(t_philo_m *m)
{
	ft_printing(m, 2);
	u_wait(philo_get_time() + m->p->timetosleep);
}

void	ft_thinking(t_philo_m *m)
{
	ft_printing(m, 3);
}

void	ft_dying(t_philo_m *m)
{
	u_wait(m->die_time);
	ft_printing(m, 4);
}
