/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:58:01 by arasal            #+#    #+#             */
/*   Updated: 2022/12/26 16:05:20 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eating(t_philo_m *m)
{
	ft_printing(m, 0);
	{
		sem_wait(m->forks);
		ft_printing(m, 0);
		ft_printing(m, 1);
		if (philo_get_time() + m->p->timetoeat > m->die_time)
		{
			ft_dying(m);
			sem_post(m->forks);
			sem_post(m->forks);
			return ;
		}
		m->die_time = philo_get_time() + m->p->timetodie + m->p->timetoeat;
		u_wait(philo_get_time() + m->p->timetoeat);
		{
			sem_wait(m->times_eaten_s);
			if (m->p->numtoeat != -1)
				m->times_eaten += 1;
			sem_post(m->times_eaten_s);
		}
		sem_post(m->forks);
	}
	sem_post(m->forks);
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
